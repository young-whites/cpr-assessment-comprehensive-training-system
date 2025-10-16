/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-20     18452       the first version
 */
#include "23lc1024_sram_spi.h"






#define SRAM_CMD_WRSR       0x01    /* 写 STATUS/MODE 寄存器 */
#define SRAM_CMD_RDSR       0x05    /* 读 STATUS/MODE 寄存器 */
#define SRAM_READ_CMD       0x03    /* 23LC1024 读指令 */
#define SRAM_WRITE_CMD      0x02    /* 23LC1024 写指令 */


//以下是SPI以及SRAM引脚配置相关的函数---------------------------------------------------------------------------------------------

/* 宏定义SPI名称 */
#define     SRAM_SPI_NAME    "tft_spi2"
/* 宏定义SPI总线 */
#define     SRAM_SPI_BUS     "spi2"
/* 宏定义SPI句柄 */
struct rt_spi_device *spi_dev_sram;



/**
  * @brief  SPI Initialization
  * @retval void
  */
void sram_spi_init(void)
{
    /* 将SPI设备名挂载到总线 */
    rt_hw_spi_device_attach(SRAM_SPI_BUS, SRAM_SPI_NAME, SRAM_CS_PORT, SRAM_CS_PIN);
    /* 查找SPI设备 */
    spi_dev_sram = (struct rt_spi_device *)rt_device_find(SRAM_SPI_NAME);
    if(spi_dev_sram == NULL){
        rt_kprintf("SPI Device is not created!\r\n");
    }
    else{
        rt_kprintf("SPI Device is successfully!\r\n");
    }
    /***
     *! 配置SPI结构体参数
     *! data_width: spi传输数据长度为8bits
     *! max_hz: spi的最大工作频率；
     *! mode-> RT_SPI_MASTER: 主机模式；
     *! mode-> RT_SPI_MODE_2: 工作模式0（CPOL:1  CPHA:0）
     *! mode-> RT_SPI_MSB: 通讯数据高位在前低位在后
     * */
    struct rt_spi_configuration spi2_cfg;
    spi2_cfg.data_width = 8;
    spi2_cfg.max_hz = 20*1000*1000; /* 20M,SPI max 20MHz,SRAM 4-wire spi */
    spi2_cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_2 | RT_SPI_MSB;
    rt_spi_configure(spi_dev_sram, &spi2_cfg); /* 使能参数 */

    /* 3. HOLD 引脚初始化（CubeMX 已在 bsp_sys 完成，这里只做电平） */
    SRAM_HOLD_SET(1);   // 正常使用必须拉高
    SRAM_CS_SET(1);     // 片选空闲高电平
    rt_kprintf("23LC1024: init ok.\r\n");
}




/**
 * @brief  设置 23LC1024 的工作模式
 * @param  mode  见 sram_mode_t 枚举
 * @retval RT_EOK 成功，-RT_ERROR SPI 异常
 */
rt_err_t sram_set_mode(sram_mode_t mode)
{
    uint8_t cmd[5] = {
        SRAM_CMD_WRSR,      /* 指令：写 STATUS / MODE */
        0x00,               /* 地址高字节(固定 0)   */
        0x00,               /* 地址中字节(固定 0)   */
        0x00,               /* 地址低字节(固定 0)   */
        mode                /* 数据：模式值         */
    };

    SRAM_CS_SET(0);
    rt_size_t len = rt_spi_send(spi_dev_sram, cmd, sizeof(cmd));
    SRAM_CS_SET(1);

    return (len == sizeof(cmd)) ? RT_EOK : -RT_ERROR;
}




/**
 * @brief  读取当前工作模式
 * @retval 返回当前模式值（低 8 位有效）
 */
sram_mode_t sram_get_mode(void)
{
    uint8_t cmd[4] = { SRAM_CMD_RDSR, 0x00, 0x00, 0x00 };
    uint8_t rx = 0;

    SRAM_CS_SET(0);
    rt_spi_send_then_recv(spi_dev_sram, cmd, 4, &rx, 1);
    SRAM_CS_SET(1);

    return (sram_mode_t)(rx & 0xC0);  /* bit7:6 即模式位 */
}




/**
  * @brief  spi send one byte function
  * @retval rt_err_t
  */
rt_err_t sram_write_byte(rt_uint32_t addr, rt_uint8_t byte)
{

    rt_size_t len;

    /****
     * 说明：23LC1024 内部有 128 K 个存储单元, 每个单元 1 Byte
     *
     *       23LC1024 = 1 Mbit = 128 KByte = 2¹⁷ Byte
     *
     *       因此 有效寻址范围：0x00000 ~ 0x1FFFF → 17 位地址线足够
     *       但 SPI 协议规定 必须以“整字节”为单位发送，所以芯片要求 再补 7 个无效位凑成 24 位（3 字节）
     *       芯片手册规定：
     *                      命令(8 bit) + 地址(24 bit) + 数据(N×8 bit)
     *                      这 24 位地址里 真正用到的只有低 17 位；高 7 位是 Don’t-Care，通常填 0。
     *
     */
    rt_uint8_t cmd[4] = { SRAM_WRITE_CMD,
                          (addr >> 16) & 0xFF,
                          (addr >> 8)  & 0xFF,
                          addr & 0xFF };

    SRAM_CS_SET(0);
    len = rt_spi_send(spi_dev_sram, cmd, 4);
    if (len != 4){
        LOG_I("sram_write_addr error. %d", len);
        return -RT_ERROR;
    }

    len = rt_spi_send(spi_dev_sram, &byte, 1);
    len = rt_spi_send(spi_dev_sram, cmd, 4);
    if (len != 4){
        LOG_I("sram_write_byte error. %d", len);
        return -RT_ERROR;
    }
    SRAM_CS_SET(1);

    return RT_EOK;
}



/**
  * @brief  spi read one byte from special address.
  * @retval read byte's data
  * @note   rt_spi_send_then_recv() 就是 “一条函数完成：先写 N 字节，再读 M 字节，CS 中间不拉高” 的快捷封装，特别适合 “命令+读回数据” 类 SPI 设备。
  */
rt_uint8_t sram_read_byte(rt_uint32_t addr)
{
    rt_uint8_t cmd[4] = { SRAM_READ_CMD,
                          (addr >> 16) & 0xFF,
                          (addr >> 8)  & 0xFF,
                          addr & 0xFF };
    rt_uint8_t rx_byte; // 接受读取到的一个字节的数据

    SRAM_CS_SET(0);
    rt_spi_send_then_recv(spi_dev_sram, cmd, 4, &rx_byte, 1);
    SRAM_CS_SET(1);
    return rx_byte;
}



/**
  * @brief  向 23LC1024 连续写入一块数据（任意长度）
  * @param  addr  起始字节地址，0x00000–0x1FFFF（128 KB 范围内）
  *         buf   待写入数据缓冲区首地址
  *         len   待写入字节数；单次最大受芯片容量限制，实际可 ≤ 128 KB
  * @retval 成功返回实际写入的字节数；
  *         失败返回 -RT_ERROR（命令或数据阶段异常）
  * @note
  *   1. 本函数内部构造 4 字节命令头（WRITE+24 位地址），随后直接发送数据。
  *   2. 片选 CS 在整段传输期间持续拉低，满足 23LC1024 连续写时序要求。
  *   3. 调用者需确保 addr + len ≤ 128 KB，避免地址回卷。
  *   4. 若 SPI 总线被其他设备共享，应在调用前后自行加锁/解锁。
  */
rt_size_t sram_write_sequence(rt_uint32_t addr, const rt_uint8_t *buf, rt_size_t len)
{
    rt_size_t ret_l;
    rt_uint8_t header[4] = { SRAM_WRITE_CMD,
                             (addr >> 16) & 0xFF,
                             (addr >> 8)  & 0xFF,
                             addr & 0xFF };

    SRAM_CS_SET(0);

    ret_l = rt_spi_send(spi_dev_sram, header, 4);
    if (ret_l != 4){
        LOG_I("sram_write_block error. %d", ret_l);
        return -RT_ERROR;
    }
    rt_size_t ret = rt_spi_send(spi_dev_sram, buf, len);

    SRAM_CS_SET(1);
    return ret;
}




/**
 * @brief   以 Sequential 模式从 23LC1024 连续读取任意长度数据
 *          addr  起始字节地址，范围 0x00000 ~ 0x1FFFF（128 KB）
 *          buf   接收缓冲区首地址，长度 ≥ len
 *          len   要读取的字节数；允许跨页、跨边界，最大 ≤ 128 KB
 * @retval  成功返回实际读取的字节数；失败返回 0 或负值
 * @note
 *  1. 本函数假定芯片已处于 Sequential 模式（MODE = 0x40 或上电默认）。
 *  2. 内部地址计数器在读过程中自动递增；到达 0x1FFFF 后自动回卷到 0x00000。
 *  3. 片选 CS 在整个传输期间保持低电平，满足 23LC1024 连续读时序要求。
 *  4. 若 len 超过 SRAM 容量，超出部分会从 0x00000 重新开始读取（回卷）。
 *  5. 调用者需确保 buf 缓冲区足够大，并在多线程环境下自行加锁。
 */
rt_size_t sram_read_sequence(rt_uint32_t addr, rt_uint8_t *buf, rt_size_t len)
{
    rt_uint8_t header[4] = { SRAM_READ_CMD,
                             (addr >> 16) & 0xFF,
                             (addr >> 8)  & 0xFF,
                             addr & 0xFF };

    SRAM_CS_SET(0);
    rt_size_t ret = rt_spi_send_then_recv(spi_dev_sram, header, 4, buf, len);
    SRAM_CS_SET(1);
    return ret;
}




/**
 * @brief  Page 模式下向 23LC1024 写入数据（32 字节边界内自动回卷）
 * @param  addr  页内任意起始字节地址（0x00000~0x1FFFF）
 *         buf   待写入数据缓冲区
 *         len   待写入字节数；如果跨页，芯片会自动回卷到页首
 * @retval 成功返回实际写入的字节数；失败返回 0
 * @note
 *   1. 调用前需已通过 sram_set_mode(SRAM_MODE_PAGE) 切换到 Page 模式。
 *   2. 地址高 17 位决定“哪一页”，低 5 位决定“页内偏移”。
 *   3. 当内部偏移 ≥ 32 时自动回卷到页首（0x00）。
 */
rt_size_t sram_write_page(rt_uint32_t addr, const rt_uint8_t *buf, rt_size_t len)
{
    rt_uint8_t header[4] = {
        SRAM_WRITE_CMD,
        (addr >> 16) & 0xFF,
        (addr >> 8)  & 0xFF,
        addr & 0xFF
    };

    SRAM_CS_SET(0);

    /* 发送 4 字节命令头 */
    if (rt_spi_send(spi_dev_sram, header, 4) != 4) {
        SRAM_CS_SET(1);
        return 0;                   /* 命令头发送失败 */
    }

    /* 发送数据 */
    rt_size_t ret = rt_spi_send(spi_dev_sram, buf, len);

    SRAM_CS_SET(1);

    return ret;                     /* 成功返回实际写入数据长度 */
}

/**
 * @brief  Page 模式下从 23LC1024 读取数据（32 字节边界内自动回卷）
 * @param  addr  页内任意起始字节地址（0x00000~0x1FFFF）
 *         buf   接收缓冲区
 *         len   要读取的字节数；跨页时芯片自动回卷到页首
 * @retval 成功返回实际读取的字节数；失败返回 0
 * @note
 *   1. 调用前需已通过 sram_set_mode(SRAM_MODE_PAGE) 切换到 Page 模式。
 *   2. 内部偏移 ≥ 32 时自动回卷；len 可以大于 32，芯片会在页内循环。
 */
rt_size_t sram_read_page(rt_uint32_t addr, rt_uint8_t *buf, rt_size_t len)
{
    rt_uint8_t header[4] = {
        SRAM_READ_CMD,
        (addr >> 16) & 0xFF,
        (addr >> 8)  & 0xFF,
        addr & 0xFF
    };

    SRAM_CS_SET(0);
    rt_size_t ret = rt_spi_send_then_recv(spi_dev_sram, header, 4, buf, len);
    SRAM_CS_SET(1);

    return (ret == len) ? len : 0;
}










/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-21     Administrator       the first version
 */
#include "23lc1024_sram_test.h"




/**
  * @brief  单字节回环测试
  * @retval void
  * @note   验证点：最基本的 SPI 读写、CS 时序、地址解析正确性
  */
void sram_test_byte(void)
{
    uint32_t addr = 0x12345;
    uint8_t  pat  = 0xA5;
    uint8_t  rd;

    sram_write_byte(addr, pat);
    rd = sram_read_byte(addr);

    if(rd == pat)
        rt_kprintf("byte test ok: 0x%02X\n", rd);
    else
        rt_kprintf("byte test fail: wr=0x%02X rd=0x%02X\n", pat, rd);
}
MSH_CMD_EXPORT(sram_test_byte, sram_test_byte test);


/**
  * @brief  连续块测试（内部 SRAM 全空间遍历）
  * @retval void
  * @note   验证点： 连续写/读是否跨页、跨 128 kB 边界都能正确回卷
  *                 20 MHz 频率下信号完整性
  *                 SPI DMA（如果开了）无丢数
  */
void sram_test_full_range(void)
{
    uint32_t addr;
    uint8_t  wr_buf[256], rd_buf[256];

    /* 1. 顺序写入 0~255 递增数据 */
    for(addr = 0; addr < 128*1024; addr += 256)
    {
        for(int i = 0; i < 256; i++){
            wr_buf[i] = (uint8_t)(addr + i);
        }
        sram_write_sequence(addr, wr_buf, 256);
    }

    /* 2. 读回并校验 */
    for(addr = 0; addr < 128*1024; addr += 256)
    {
        sram_read_sequence(addr, rd_buf, 256);

        for(int i = 0; i < 256; i++)
        {
            if(rd_buf[i] != (uint8_t)(addr + i))
            {
                rt_kprintf("full test fail @0x%05lX: 0x%02X != 0x%02X\n",
                           addr+i, rd_buf[i], (uint8_t)(addr+i));
                return;
            }
        }
    }
    rt_kprintf("full range test ok\n");
}
MSH_CMD_EXPORT(sram_test_full_range, sram_test_full_range test);



/**
  * @brief  模式寄存器读写测试
  * @retval void
  * @note   验证点： WREN/WRSR/RDSR 指令正确，bit7:6 可读写
  */
void sram_test_mode(void)
{
    sram_mode_t m;

    /* 切到 Page 模式 */
    sram_set_mode(SRAM_MODE_PAGE);
    m = sram_get_mode();
    if(m != SRAM_MODE_PAGE)
        rt_kprintf("mode set/get page fail\n");

    rt_thread_mdelay(500);

    /* 切回 Sequential 模式 */
    sram_set_mode(SRAM_MODE_SEQUENTIAL);
    m = sram_get_mode();
    if(m != SRAM_MODE_SEQUENTIAL)
        rt_kprintf("mode set/get seq fail\n");
    else
        rt_kprintf("mode register test ok\n");
}
MSH_CMD_EXPORT(sram_test_mode, sram_test_mode test);



/**
  * @brief  Page 模式边界回卷测试
  * @retval void
  * @note   验证点：Page 模式下 32 字节回卷逻辑正确
  */
void sram_test_page_wrap(void)
{
    /* 选第 0 页的最后 2 字节开始写 36 字节，看是否回卷 */
    uint32_t start = 0x1FFE;       /* 页内偏移 30, 31, 0, 1, 2 ... */
    uint8_t  wr[36], rd[36];

    for(int i = 0; i < 36; i++) wr[i] = i;

    sram_set_mode(SRAM_MODE_PAGE);
    sram_write_page(start, wr, 36);
    sram_read_page (start, rd, 36);

    /* 期望 rd[0]=0, rd[1]=1 ... rd[30]=30, rd[31]=31, rd[32]=0, rd[33]=1 ... */
    for(int i = 0; i < 36; i++)
    {
        uint8_t expect = i % 32;
        if(rd[i] != expect)
        {
            rt_kprintf("page wrap fail @%d: %d != %d\n", i, rd[i], expect);
            return;
        }
    }
    rt_kprintf("page wrap test ok\n");
}
MSH_CMD_EXPORT(sram_test_page_wrap, sram_test_page_wrap test);







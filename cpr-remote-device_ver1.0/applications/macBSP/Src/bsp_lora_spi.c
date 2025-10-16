/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-07-29     Administrator       the first version
 */
#include "bsp_lora_spi.h"




//以下是SPI以及LORA引脚配置相关的函数---------------------------------------------------------------------------------------------

/* 宏定义SPI名称 */
#define     LORA_SPI_NAME    "tft_spi3"
/* 宏定义SPI总线 */
#define     LORA_SPI_BUS     "spi3"
/* 宏定义SPI句柄 */
struct rt_spi_device *spi_dev_lora;



/**
  * @brief  SPI Initialization
  * @retval void
  */
//void lora_spi_init(void)
//{
//    /* 将SPI设备名挂载到总线 */
//    rt_hw_spi_device_attach(LORA_SPI_BUS, LORA_SPI_NAME, TFT_CS_PORT, TFT_CS_PIN);
//    /* 查找SPI设备 */
//    spi_dev_tft = (struct rt_spi_device *)rt_device_find(TFT_SPI_NAME);
//    if(spi_dev_tft == NULL){
//        rt_kprintf("SPI Device is not created!\r\n");
//    }
//    else{
//        rt_kprintf("SPI Device is successfully!\r\n");
//    }
//    /***
//     *! 配置SPI结构体参数
//     *! data_width: spi传输数据长度为8bits
//     *! max_hz: spi的最大工作频率；
//     *! mode-> RT_SPI_MASTER: 主机模式；
//     *! mode-> RT_SPI_MODE_0: 工作模式0（CPOL:0  CPHA:0）
//     *! mode-> RT_SPI_MSB: 通讯数据高位在前低位在后
//     * */
//    struct rt_spi_configuration spi1_cfg;
//    spi1_cfg.data_width = 8;
//    spi1_cfg.max_hz = 42*1000*1000; /* 42M,SPI max 42MHz,lcd 4-wire spi */
//    spi1_cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_2 | RT_SPI_MSB;
//    rt_spi_configure(spi_dev_tft, &spi1_cfg); /* 使能参数 */
//}













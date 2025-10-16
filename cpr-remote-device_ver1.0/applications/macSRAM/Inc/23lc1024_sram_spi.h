/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-20     18452       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_23LC1024_SRAM_SPI_H_
#define APPLICATIONS_MACBSP_INC_23LC1024_SRAM_SPI_H_
#include "bsp_sys.h"


extern struct rt_spi_device *spi_dev_sram;

/* 片选引脚 -- CS */
#define     SRAM_CS_PORT     SRAM_CS_GPIO_Port
#define     SRAM_CS_PIN      SRAM_CS_Pin

#define     SRAM_CS_SET(bit) if(bit) \
                             HAL_GPIO_WritePin ( SRAM_CS_PORT, SRAM_CS_PIN , GPIO_PIN_SET );\
                             else \
                             HAL_GPIO_WritePin ( SRAM_CS_PORT, SRAM_CS_PIN , GPIO_PIN_RESET );


/* HOLD引脚 -- HOLD */
#define     SRAM_HOLD_PORT     SRAM_HOLD_GPIO_Port
#define     SRAM_HOLD_PIN      SRAM_HOLD_Pin

#define     SRAM_HOLD_SET(bit) if(bit) \
                               HAL_GPIO_WritePin ( SRAM_HOLD_PORT, SRAM_HOLD_PIN , GPIO_PIN_SET );\
                               else \
                               HAL_GPIO_WritePin ( SRAM_HOLD_PORT, SRAM_HOLD_PIN , GPIO_PIN_RESET );




/* 工作模式位定义 */
typedef enum {
    SRAM_MODE_BYTE      = 0x00, /* 00b : Byte 模式      */
    SRAM_MODE_SEQUENTIAL= 0x40, /* 01b : Sequential 模式*/
    SRAM_MODE_PAGE      = 0x80  /* 10b : Page 模式      */
}sram_mode_t;



void sram_spi_init(void);
rt_err_t sram_set_mode(sram_mode_t mode);
sram_mode_t sram_get_mode(void);
rt_err_t sram_write_byte(rt_uint32_t addr, rt_uint8_t byte);
rt_uint8_t sram_read_byte(rt_uint32_t addr);
rt_size_t sram_write_sequence(rt_uint32_t addr, const rt_uint8_t *buf, rt_size_t len);
rt_size_t sram_read_sequence(rt_uint32_t addr, rt_uint8_t *buf, rt_size_t len);
rt_size_t sram_write_page(rt_uint32_t addr, const rt_uint8_t *buf, rt_size_t len);
rt_size_t sram_read_page(rt_uint32_t addr, rt_uint8_t *buf, rt_size_t len);



#endif /* APPLICATIONS_MACBSP_INC_23LC1024_SRAM_SPI_H_ */

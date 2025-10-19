/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-10-17     Administrator       the first version
 */
#include "bsp_sys.h"


//---------------------------------------------------------------------------------------
#define TM1638_CLK_H()      HAL_GPIO_WritePin(TM1638_CLK_GPIO_Port, TM1638_CLK_Pin,  GPIO_PIN_SET)
#define TM1638_CLK_L()      HAL_GPIO_WritePin(TM1638_CLK_GPIO_Port, TM1638_CLK_Pin,  GPIO_PIN_RESET)
#define TM1638_DIO_H()      HAL_GPIO_WritePin(TM1638_DIO_GPIO_Port, TM1638_DIO_Pin,  GPIO_PIN_SET)
#define TM1638_DIO_L()      HAL_GPIO_WritePin(TM1638_DIO_GPIO_Port, TM1638_DIO_Pin,  GPIO_PIN_RESET)
#define TM1638_STB_H()      HAL_GPIO_WritePin(TM1638_STB_GPIO_Port, TM1638_STB_Pin,  GPIO_PIN_SET)
#define TM1638_STB_L()      HAL_GPIO_WritePin(TM1638_STB_GPIO_Port, TM1638_STB_Pin,  GPIO_PIN_RESET)


void TM1638_Delay_us(uint32_t us);
void TM1638_Write_Byte(rt_uint8_t data);


















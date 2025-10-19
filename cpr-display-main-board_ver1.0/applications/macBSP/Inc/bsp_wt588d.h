/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-10-16     Administrator       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_BSP_WT588D_H_
#define APPLICATIONS_MACBSP_INC_BSP_WT588D_H_

#include "bsp_sys.h"


//--------------------------------------------------------------------------------------------------------
#define WT588D_CLK_H()      HAL_GPIO_WritePin(WT588D_CLK_GPIO_Port,  WT588D_CLK_Pin,    GPIO_PIN_SET)
#define WT588D_CLK_L()      HAL_GPIO_WritePin(WT588D_CLK_GPIO_Port,  WT588D_CLK_Pin,    GPIO_PIN_RESET)
#define WT588D_CS_H()       HAL_GPIO_WritePin(WT588D_CS_GPIO_Port,   WT588D_CS_Pin,     GPIO_PIN_SET)
#define WT588D_CS_L()       HAL_GPIO_WritePin(WT588D_CS_GPIO_Port,   WT588D_CS_Pin,     GPIO_PIN_RESET)
#define WT588D_DATA_H()     HAL_GPIO_WritePin(WT588D_DATA_GPIO_Port, WT588D_DATA_Pin,   GPIO_PIN_SET)
#define WT588D_DATA_L()     HAL_GPIO_WritePin(WT588D_DATA_GPIO_Port, WT588D_DATA_Pin,   GPIO_PIN_RESET)
#define WT588D_RST_H()      HAL_GPIO_WritePin(WT588D_RESET_GPIO_Port,  WT588D_RESET_Pin,    GPIO_PIN_SET)
#define WT588D_RST_L()      HAL_GPIO_WritePin(WT588D_RESET_GPIO_Port,  WT588D_RESET_Pin,    GPIO_PIN_RESET)



//--------------------------------------------------------------------------------------------------------
#define WT588D_CMD_VOLUME_LEVEL0        0xE0
#define WT588D_CMD_VOLUME_LEVEL1        0xE1
#define WT588D_CMD_VOLUME_LEVEL2        0xE2
#define WT588D_CMD_VOLUME_LEVEL3        0xE3
#define WT588D_CMD_VOLUME_LEVEL4        0xE4
#define WT588D_CMD_VOLUME_LEVEL5        0xE5
#define WT588D_CMD_VOLUME_LEVEL6        0xE6
#define WT588D_CMD_VOLUME_LEVEL7        0xE7
#define WT588D_CMD_LOOP_PLAYBACK        0xF2
#define WT588D_CMD_STOP_PLAYING         0xFE

#define WT588D_ADDR_VOICE_0             0x00
#define WT588D_ADDR_VOICE_1             0x01
#define WT588D_ADDR_VOICE_2             0x02
#define WT588D_ADDR_VOICE_3             0x03
#define WT588D_ADDR_VOICE_4             0x04
#define WT588D_ADDR_VOICE_5             0x05
#define WT588D_ADDR_VOICE_6             0x06
#define WT588D_ADDR_VOICE_7             0x07
#define WT588D_ADDR_VOICE_8             0x08
#define WT588D_ADDR_VOICE_9             0x09
#define WT588D_ADDR_VOICE_10            0x0A
#define WT588D_ADDR_VOICE_11            0x0B

//--------------------------------------------------------------------------------------------------------
void WT588D_Delay_us(uint32_t us);
void WT588D_Write_Byte(rt_uint8_t data);
void WT588D_Set_Cmd(rt_uint8_t cmd);
rt_uint8_t WT588D_Busy_Check(void);
void WT588D_Loop_Playback(void);
void WT588D_Stop(void);
void WT588D_Set_Volume(rt_uint8_t cmd);





#endif /* APPLICATIONS_MACBSP_INC_BSP_WT588D_H_ */

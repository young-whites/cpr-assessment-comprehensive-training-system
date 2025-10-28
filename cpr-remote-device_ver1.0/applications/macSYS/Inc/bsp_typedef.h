/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-05-15     teati       the first version
 */
#ifndef APPLICATIONS_MACSYS_INC_BSP_TYPEDEF_H_
#define APPLICATIONS_MACSYS_INC_BSP_TYPEDEF_H_

#include "bsp_sys.h"


// 以下为移植时必须需要的结构体等的初始化---------------------------------------------------------------------------------------------------------
typedef struct {
    rt_uint8_t   Empty;                          // 空值
    rt_uint16_t  kprintf_cnt;                    // 用于打印序列
    rt_uint32_t  ulog_cnt;                       // ulog打印序列
    //------------------------------------------------------------
    rt_uint8_t  touch_down_flag;                 // 触摸按下标志
    rt_uint8_t  touch_fingers;                   // 触摸报点数
    rt_uint8_t  nrf_if_connected;                // 是否建立连接
    rt_uint8_t  nrf_sending;                     // 正在发送标志(0：发送完    1：已发送)
}RecordStruct;
extern RecordStruct Record;












#endif /* APPLICATIONS_MACSYS_INC_BSP_TYPEDEF_H_ */

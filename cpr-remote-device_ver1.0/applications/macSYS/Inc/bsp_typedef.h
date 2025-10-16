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
    rt_uint8_t  Empty;                           // 空值
    rt_uint16_t  kprintf_cnt;                     // 用于打印序列

    //------------------------------------------------------------
    rt_uint8_t  KeyPowerCnt;                     // 开关电源按下次数
    rt_uint8_t  KeyLong4sCnt;                    // 开关键长按4s次数
    rt_uint8_t  KeyHand_1_Cnt;                   // 手柄1按键按下次数
    rt_uint8_t  Bluetooth_Status;                // 蓝牙连接状态
    rt_uint8_t  OldMode;                         // 老化模式标志位
    rt_uint8_t  BlueBeepCnt;                     // 蓝牙连接标志
    rt_uint8_t  Probe_type;                      // 探头类型
    rt_uint8_t  Work_mode;                       // 工作模式
    uint16_t    Pluse_time;                      // 脉冲时间
    rt_uint8_t  Pluse_time_H;                    // 脉冲时间(高8位)
    rt_uint8_t  Pluse_time_L;                    // 脉冲时间(低8位)
    rt_uint8_t  Pneumato_switch;                 // 气体开关
    rt_uint8_t  StrengLevel;                     // 能量等级
    rt_uint16_t RealPluseTime;                   // 实际的脉冲时间
    rt_uint16_t IFWorking;                       // 是否处于工作状态
    rt_uint8_t  touch_down_flag;                 // 触摸按下标志
    rt_uint8_t  touch_fingers;                   // 触摸报点数

}RecordStruct;
extern RecordStruct Record;












#endif /* APPLICATIONS_MACSYS_INC_BSP_TYPEDEF_H_ */

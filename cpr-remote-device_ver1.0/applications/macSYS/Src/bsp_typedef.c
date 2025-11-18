/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-05-15     teati       the first version
 */

#include "bsp_typedef.h"



// 全局变量
RecordStruct Record;
FlagStruct Flag;


// 与nRF24L01通讯相关的全局事件集
rt_event_t nrf24l01_events;




void system_param_init(void)
{
    Record.nrf_if_connected = 0;
    Record.work_time = 200;
    Record.press_rate = 70;
    Record.air_rate = 50;

    Record.menu_index = 0;
}



void all_project_event_init(void)
{
    rt_event_init(&nrf24l01_events, "nrf_lvgl", RT_IPC_FLAG_FIFO);
}













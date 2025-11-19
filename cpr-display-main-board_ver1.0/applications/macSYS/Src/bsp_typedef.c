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



RecordStruct Record;


System_Config_t MySysCfg = {
    .current_mode = MODE_TRAIN,
    .edit_index   = 0,
    .setting_mode = 0,
    .params = {
        [MODE_TRAIN]   = {  .Number_CountDown = 120,
                            .Number_Press_Frequency = 0,
                            .Number_Press_Correct = 0,
                            .Number_Press_Error = 0,
                            .Number_Cycle = 0,
                            .Number_Blow_Time = 0,
                            .Number_Blow_Correct = 0,
                            .Number_Blow_Error = 0,
                            .press_rate = 90,
                            .tidal_rate = 85
                           },


        [MODE_ASSESS]  = {  .Number_CountDown = 120,
                            .Number_Press_Frequency = 0,
                            .Number_Press_Correct = 0,
                            .Number_Press_Error = 0,
                            .Number_Cycle = 0,
                            .Number_Blow_Time = 0,
                            .Number_Blow_Correct = 0,
                            .Number_Blow_Error = 0,
                            .press_rate = 90,
                            .tidal_rate = 85
                            },

        [MODE_COMPETE] = {  .Number_CountDown = 120,
                            .Number_Press_Frequency = 0,
                            .Number_Press_Correct = 0,
                            .Number_Press_Error = 0,
                            .Number_Cycle = 0,
                            .Number_Blow_Time = 0,
                            .Number_Blow_Correct = 0,
                            .Number_Blow_Error = 0,
                            .press_rate = 90,
                            .tidal_rate = 85 },
    }
};










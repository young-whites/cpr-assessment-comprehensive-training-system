/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-07-28     18452       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_BSP_BATTERY_H_
#define APPLICATIONS_MACBSP_INC_BSP_BATTERY_H_

#include "bsp_sys.h"


#define REG_VOL_3V3         3.3     /* ADC的参考电压 */
#define REG_VOL_5V0         5.0     /* ADC的参考电压 */
#define CONVERT_BITS        12      /* 分辨率 */
#define SAMPLE_NUM          8       /* 采样次数 */


void battery_recharge_enable(void);
void battery_recharge_disable(void);
rt_uint8_t battery_check_if_recharging(void);
rt_uint8_t battery_check_if_power_full(void);
float battery_get_current_data(rt_uint32_t adc_values);
float battery_get_vol_data(rt_uint32_t adc_values);

#endif /* APPLICATIONS_MACBSP_INC_BSP_BATTERY_H_ */


/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-07-28     18452       the first version
 */


#include "bsp_battery.h"


/**
  * @brief  battery recharge enable function.
  * @retval void
  * @note   GPIO -- PC3
  */
void battery_recharge_enable(void)
{
    HAL_GPIO_WritePin(BAT_EN_GPIO_Port, BAT_EN_Pin, GPIO_PIN_SET);
}



/**
  * @brief  battery recharge disable function.
  * @retval void
  * @note   GPIO -- PC3
  */
void battery_recharge_disable(void)
{
    HAL_GPIO_WritePin(BAT_EN_GPIO_Port, BAT_EN_Pin, GPIO_PIN_RESET);
}


/**
  * @brief  check if charging is enable.
  * @retval 1: battery is recharging
  *         0: battery is not recharging
  * @note   GPIO -- PA3
  */
rt_uint8_t battery_check_if_recharging(void)
{
    return HAL_GPIO_ReadPin(BAT_CHARG_GPIO_Port, BAT_CHARG_Pin) ? 0 : 1;
}



/**
  * @brief  check if the battery's power is full.
  * @retval 1: battery power is full
  *         0: battery power is not full
  * @note   GPIO -- PC2，充满电STDBY为低电平，否则为高阻态
  */
rt_uint8_t battery_check_if_power_full(void)
{
    return HAL_GPIO_ReadPin(BAT_STDBY_GPIO_Port, BAT_STDBY_Pin) ? 0 : 1;
}



/**
  * @brief  充电电流可以通过连接一个外部电阻到地端来编程设定
  * @retval TP5400的充电电流
  * @note   1.在预充电阶段，此管脚的电压被调制在0.1V;
  *         2.在恒流充电阶段，此管脚的电压被固定在1V;
  *         3.TP4500的PROG引脚的充电电流设定电阻
  *         ----------------------------------
  *             Rprog（Ω）     |          Ibat
  *         ----------------------------------
  *               10k       |    130mA
  *               5k        |    245mA
  *               2k        |    560mA
  *               1.5k      |    740mA
  *               1.1k      |    1000mA
  *         ----------------------------------
  *         4.电池充电电流是PROG引脚输出电流的1100倍
  *         5.实时检测方法：
  *         ·TP5400 在恒流阶段会把 PROG 引脚内部钳位到 1 V
  *         ·因此实际 PROG 引脚电压 VPROG 与充电电流成正比
  *         ·计算：IBAT = VPROG / RPROG × 1100
  *         ·综上，只需用 MCU 的 ADC 采集 VPROG，即可实时算出 IBAT
  */
float battery_get_current_data(rt_uint32_t adc_values)
{

    static float vol = 0.0;
    static float cur = 0.0;

    adc_values /= SAMPLE_NUM;
    vol = adc_values * REG_VOL_3V3 / 4095.0; // 单位：V
    // Rprog = 2kΩ
    cur = vol / 2.0 * 1100;  // 单位：mA

    return cur;
}



/**
  * @brief  检测电池的实时电压
  * @retval 电池的实时电压
  * @note   (Vin-Vout)/R104+(3V3-Vout)/R106 = Vout/R105
  *         ·其中： R104 = 30k
  *         ·      R105 = 15k
  *         ·      R106 = 10k
  *
  *         ·简化后：Vout = ( Vin + 10 ) / 6
  */
float battery_get_vol_data(rt_uint32_t adc_values)
{
    static float vol = 0.0;

    adc_values /= SAMPLE_NUM;
    vol = adc_values * REG_VOL_3V3 / 4095.0; // 单位：V
    vol = vol*6 - 10;

    return vol;
}



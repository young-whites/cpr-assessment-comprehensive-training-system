/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-30     Administrator       the first version
 */
#ifndef APPLICATIONS_ADC128S102_H_
#define APPLICATIONS_ADC128S102_H_

#include "app_sys.h"



typedef enum
{
    ADC128S_Channel_1 = 0,
    ADC128S_Channel_2,
    ADC128S_Channel_3,
    ADC128S_Channel_4,
    ADC128S_Channel_5,
    ADC128S_Channel_6,
    ADC128S_Channel_7,
    ADC128S_Channel_8
}adc128s_channel_et;




#define ADC128S_CS_PORT     SPI1_NSS_GPIO_Port
#define ADC128S_CS_PIN      SPI1_NSS_Pin

#define ADC128S_CS_SET(bit) if(bit) \
                            HAL_GPIO_WritePin(ADC128S_CS_PORT, ADC128S_CS_PIN, GPIO_PIN_SET);\
                            else    \
                            HAL_GPIO_WritePin(ADC128S_CS_PORT, ADC128S_CS_PIN, GPIO_PIN_RESET);




#endif /* APPLICATIONS_ADC128S102_H_ */

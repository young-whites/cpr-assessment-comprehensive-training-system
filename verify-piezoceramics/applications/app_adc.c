/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-08     18452       the first version
 */
#include "app_sys.h"


rt_uint16_t kprintf_cnt;

#define ADC1_DEVICE_NAME    "adc1"  /* 设备名称 */
#define ADC_CH1_CHANNEL     1       /* 震动传感器ADC输出通道 */


#define REG_VOL_3V3         3.3     /* ADC的参考电压 */
#define REG_VOL_5V0         5.0     /* ADC的参考电压 */
#define CONVERT_BITS        12      /* 分辨率 */
#define SAMPLE_NUM          8       /* 采样次数 */



/**
  * @brief  Used to initialize ADC devices and channels
  * @retval None
  */
typedef struct {
    char adc_dev1_name[16];             /* adc设备名称 */
    int  adc_channel_1;                 /* adc输出通道1 */

    struct rt_device_adc *adc_dev;
}_adc_init;

/**
  * @brief  ADC1 Initialization
  * @retval None
  */
static _adc_init adc_dev1   = {
        .adc_dev1_name      =   ADC1_DEVICE_NAME,
        .adc_channel_1      =   ADC_CH1_CHANNEL,
};


/**
  * @brief  adc Device Initialization
  * @retval int
  */
int ADC_Init(void)
{

    adc_dev1.adc_dev = (struct rt_device_adc*)rt_device_find(adc_dev1.adc_dev1_name);
    if(adc_dev1.adc_dev != RT_NULL){
        rt_kprintf("PRINTF:%d. adc1 device is created !! \r\n",kprintf_cnt++);
    }
    else {
        rt_kprintf("PRINTF:%d. adc1 device created failed !! \r\n",kprintf_cnt++);
        return RT_ERROR;
    }

    rt_adc_enable((rt_adc_device_t)adc_dev1.adc_dev, adc_dev1.adc_channel_1);

    return RT_EOK;
}



static rt_uint16_t adc_val = 0;
void adc_thread_entry(void* parameter)
{
    while(1)
    {
        adc_val = rt_adc_read((rt_adc_device_t)adc_dev1.adc_dev, adc_dev1.adc_channel_1);
        rt_kprintf("<any>:%d\n",adc_val);
        rt_thread_mdelay(10);
    }
}

/**
  * @brief  初始化数据解码函数
  * @retval int
  */
rt_thread_t ADC_Thread_Handle;
int ADC_Thread_Init(void)
{
    ADC_Thread_Handle = rt_thread_create("adc_thread_entry", adc_thread_entry, RT_NULL, 1024, 11, 300);
    if(ADC_Thread_Handle != RT_NULL){
        rt_kprintf("PRINTF:%d. ADC Thread is created!!\r\n",kprintf_cnt++);
        ADC_Init();
        rt_thread_startup(ADC_Thread_Handle);
    }
    else {
        rt_kprintf("PRINTF:%d. ADC Thread is not created!!\r\n",kprintf_cnt++);
    }

    return RT_EOK;
}
INIT_APP_EXPORT(ADC_Thread_Init);




/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-29     18452       the first version
 */

#include "rtt_hwtimer_state_machine.h"



#if USE_HWTIMER_STATE_MACHINE

#define HWTIMER6_DEV_NAME    "timer6"    /* 定时器名称 */
rt_device_t hw6_dev = RT_NULL;           /* 定时器设备句柄 */
rt_hwtimerval_t timeout_s;               /* 定时器超时值 */



static void HW_Timing_1ms(void)
{

}




static void HW_Timing_10ms(void)
{


}


static void HW_Timing_50ms(void)
{

}



static void HW_Timing_500ms(void)
{

}




static void HW_Timing_1s(void)
{
}


/* 定时器超时回调函数 */
static rt_err_t timer6_timeout_cb(rt_device_t dev, rt_size_t size)
{
    static rt_uint64_t time_ticks = 0;

    if(time_ticks > 60000){
        time_ticks = 0;
    }

    if((time_ticks % 1)    == 0)   HW_Timing_1ms();
    if((time_ticks % 10)   == 0)   HW_Timing_10ms();
    if((time_ticks % 50)   == 0)   HW_Timing_50ms();
    if((time_ticks % 500)  == 0)   HW_Timing_500ms();
    if((time_ticks % 1000) == 0)   HW_Timing_1s();

    return 0;
}


int hwtimer6_init(void)
{
    rt_err_t ret = RT_EOK;

    /* 定时器模式 */
    rt_hwtimer_mode_t mode;
    /* 计数频率 */
    rt_uint32_t freq = 1000000;

    /* 查找定时器设备 */
    hw6_dev = rt_device_find(HWTIMER6_DEV_NAME);
    if (hw6_dev == RT_NULL)
    {
        rt_kprintf("hwtimer sample run failed! can't find %s device!\n", HWTIMER6_DEV_NAME);
        return RT_ERROR;
    }

    /* 以读写方式打开设备 */
    ret = rt_device_open(hw6_dev, RT_DEVICE_OFLAG_RDWR);
    if (ret != RT_EOK)
     {
         rt_kprintf("open %s device failed!\n", HWTIMER6_DEV_NAME);
         return ret;
     }

    /* 设置超时回调函数 */
    rt_device_set_rx_indicate(hw6_dev, timer6_timeout_cb);

    /* 设置计数频率(默认1Mhz或支持的最小计数频率) */
    ret = rt_device_control(hw6_dev, HWTIMER_CTRL_FREQ_SET, &freq);
    if (ret != RT_EOK)
    {
        rt_kprintf("set frequency failed! ret is :%d\n", ret);
        return ret;
    }

    /* 设置模式为周期性定时器 */
    mode = HWTIMER_MODE_PERIOD;
    ret = rt_device_control(hw6_dev, HWTIMER_CTRL_MODE_SET, &mode);
    if (ret != RT_EOK)
    {
        rt_kprintf("set mode failed! ret is :%d\n", ret);
        return ret;
    }


    /* 设置定时器超时值为10ms并启动定时器 */
    timeout_s.sec = 0;      /* 秒 */
    timeout_s.usec = 10000;  /* 微秒 */

    if (rt_device_write(hw6_dev, 0, &timeout_s, sizeof(timeout_s)) != sizeof(timeout_s))
    {
        rt_kprintf("set timeout value failed\n");
        return RT_ERROR;
    }

    /* 读取定时器当前值 */
      rt_device_read(hw6_dev, 0, &timeout_s, sizeof(timeout_s));
      LOG_I("LOG_I(%d): Read: Sec = %d, Usec = %d\n",Record.ulog_cnt++, timeout_s.sec, timeout_s.usec);

      return ret;
}

#endif













/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-28     18452       the first version
 */
#include "internal_rtc.h"

#ifdef ULOG_TIME_USING_TIMESTAMP


/*
 * 程序清单：这是一个 RTC 设备使用例程
 * 例程导出了 rtc_sample 命令到控制终端
 * 命令调用格式：rtc_sample
 * 程序功能：设置RTC设备的日期和时间，延时一段时间后获取当前时间并打印显示。
*/


#define RTC_NAME       "rtc"

static int rtc_sample(int argc, char *argv[])
{
    rt_err_t ret = RT_EOK;
    time_t now;
    rt_device_t device = RT_NULL;

    /*寻找设备*/
    device = rt_device_find(RTC_NAME);
    if (!device)
    {
      LOG_E("find %s failed!", RTC_NAME);
      return RT_ERROR;
    }

    /*初始化RTC设备*/
    if(rt_device_open(device, 0) != RT_EOK)
    {
      LOG_E("open %s failed!", RTC_NAME);
      return RT_ERROR;
    }

    /* 设置日期 */
    ret = set_date(2018, 12, 3);
    if (ret != RT_EOK)
    {
        rt_kprintf("set RTC date failed\n");
        return ret;
    }

    /* 设置时间 */
    ret = set_time(11, 15, 50);
    if (ret != RT_EOK)
    {
        rt_kprintf("set RTC time failed\n");
        return ret;
    }

    /* 延时3秒 */
    rt_thread_mdelay(3000);

    /* 获取时间 */
    now = time(RT_NULL);
    rt_kprintf("%s\n", ctime(&now));

    return ret;
}
/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(rtc_sample, rtc sample);




int rtc_time_set(void)
{
    rt_err_t ret = RT_EOK;
    time_t now;
    rt_device_t device = RT_NULL;

    /*寻找设备*/
    device = rt_device_find(RTC_NAME);
    if (!device)
    {
      LOG_E("find %s failed!", RTC_NAME);
      return RT_ERROR;
    }

    /*初始化RTC设备*/
    if(rt_device_open(device, 0) != RT_EOK)
    {
      LOG_E("open %s failed!", RTC_NAME);
      return RT_ERROR;
    }

    /* 设置日期 */
    ret = set_date(2025, 8, 28);
    if (ret != RT_EOK)
    {
        rt_kprintf("set RTC date failed\n");
        return ret;
    }

    /* 设置时间 */
    ret = set_time(18, 26, 00);
    if (ret != RT_EOK)
    {
        rt_kprintf("set RTC time failed\n");
        return ret;
    }

    /* 获取时间 */
    now = time(RT_NULL);
    rt_kprintf("%s\n", ctime(&now));

    return ret;
}
INIT_APP_EXPORT(rtc_time_set);

#endif

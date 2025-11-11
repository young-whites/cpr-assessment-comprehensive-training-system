/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-11     18452       the first version
 */
#include "bsp_sys.h"









/**
  * @brief  This thread entry is used for touch pad scanning
  * @retval void
  */
void Touch_Thread_entry(void* parameter)
{



    for(;;)
    {


        rt_thread_mdelay(20);
    }

}








/**
  * @brief  This is a Initialization for water level Check
  * @retval int
  */
int Touch_Thread_Init(void)
{
    rt_thread_t Touch_Task_Handle = RT_NULL;
    /* 创建检查一些系统状态标志的线程  -- 优先级：25 */
    Touch_Task_Handle = rt_thread_create("Touch_Thread_entry", Touch_Thread_entry, RT_NULL, 1024, 11, 100);
    /* 检查是否创建成功,成功就启动线程 */
    if(Touch_Task_Handle != RT_NULL)
    {
        rt_kprintf("PRINTF:%d. Touch_Thread_entry is Succeed!! \r\n",Record.kprintf_cnt++);
        rt_thread_startup(Touch_Task_Handle);
    }
    else {
        rt_kprintf("PRINTF:%d. Touch_Thread_entry is Failed \r\n",Record.kprintf_cnt++);
    }

    return RT_EOK;
}
INIT_APP_EXPORT(Touch_Thread_Init);




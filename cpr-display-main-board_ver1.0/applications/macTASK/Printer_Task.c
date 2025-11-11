/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-07     18452       the first version
 */
#include "bsp_sys.h"


#ifndef PRINTER_RS232_SERIAL
#define PRINTER_RS232_SERIAL            "uart4"
#endif

#ifndef PRINTER_RS232_BAUDRATE
#define PRINTER_RS232_BAUDRATE          9600
#endif

#ifndef PRINTER_RS232_MASTER_PARITY
#define PRINTER_RS232_MASTER_PARITY     0
#endif

#define PRINTER_RS232_SEND_MAX_SIZE 100     //发送数据缓存大小
#define PRINTER_RS232_RECEIVED_MAX_SIZE 256 //接收数据缓存大小

rs232_inst_t *printer_hinst;
uint8_t printer_rs232_recv_buf[PRINTER_RS232_RECEIVED_MAX_SIZE];    //接收到的数据
uint8_t printer_rs232_send_buf[PRINTER_RS232_SEND_MAX_SIZE];        //接收中的数据，缓存在这里



//接收数据线程函数
void printer_recv_entry(void *parameter)
{
    int len;

    while(1)
    {
        len = rs232_recv(printer_hinst, printer_rs232_recv_buf, PRINTER_RS232_RECEIVED_MAX_SIZE);
        if (len > 0)
        {
            //mRs232ReceivedMessage为接收到的数据
            LOG_I("received data, data[0] is %d\n",printer_rs232_recv_buf[0]);
        }
    }
}




static void printer_rs232_thread_entry(void *args)
{

    // 创建一个"热敏打印机"的RS232串口的实例句柄
    printer_hinst = rs232_create(PRINTER_RS232_SERIAL, PRINTER_RS232_BAUDRATE, PRINTER_RS232_MASTER_PARITY);
    printer_hinst->received_buf = printer_rs232_recv_buf;
    printer_hinst->received_max_len = PRINTER_RS232_RECEIVED_MAX_SIZE;
    if (printer_hinst == RT_NULL){
        LOG_E("create rs232 instance fail.");
        return;
    }

    // 创建接收线程
    rt_thread_t tid = rt_thread_create("printer_recv_entry", printer_recv_entry, RT_NULL, 1024, 16, 20);
    RT_ASSERT(tid != RT_NULL);
    rt_thread_startup(tid);

    // 设备连接校验
    if (rs232_connect(printer_hinst) != RT_EOK){
        rs232_destory(printer_hinst);
        LOG_E("rs232 connect fail.");
        return;
    }




    while(1)
    {

        rt_thread_mdelay(1000);
    }
}



static int rs232_printer_task_init(void)
{
    rt_thread_t printer_handle = rt_thread_create("printer_rs232_thread_entry", printer_rs232_thread_entry, RT_NULL, 1024, 16, 20);
    RT_ASSERT(printer_handle != RT_NULL);
    rt_thread_startup(printer_handle);
    LOG_I("rs232 sample thread startup...");

    return(RT_EOK);
}
INIT_APP_EXPORT(rs232_printer_task_init);













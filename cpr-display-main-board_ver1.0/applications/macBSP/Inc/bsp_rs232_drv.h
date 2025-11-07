/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-04     Administrator       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_BSP_RS232_DRV_H_
#define APPLICATIONS_MACBSP_INC_BSP_RS232_DRV_H_
#include "bsp_sys.h"


/* 定义最小和最大字节超时时间，用于接收数据时的间隔超时控制 */
#define RS232_BYTE_TMO_MIN      2
#define RS232_BYTE_TMO_MAX      15


/* RS232 实例结构体定义，用于管理串口设备的状态和资源 */
typedef struct rs232_inst
{
    rt_device_t serial;             /* 串口设备句柄 */
    rt_timer_t received_over_timer; /* 接收超时定时器，用于检测字节间隔超时 */
    rt_mutex_t lock;                /* 互斥锁，用于同步访问 */
    struct rt_semaphore rx_sem;     /* 接收信号量，用于通知接收完成 */
    rt_uint8_t status;              /* 连接状态：0 - 未连接，1 - 已连接 */
    rt_int32_t byte_tmo;            /* 字节间隔超时时间（ms） */
    rt_uint8_t *received_buf;       /* 接收缓冲区指针 */
    rt_uint32_t received_len;       /* 当前已接收的数据长度 */
    rt_uint32_t received_max_len;   /* 接收缓冲区最大长度 */
}rs232_inst_t;



/* 创建 RS232 实例
 * @param serial   串口设备名称（如 "uart2"）
 * @param baudrate 波特率
 * @param parity   奇偶校验（0: 无，1: 奇，2: 偶）
 * @return         RS232 实例句柄，或 NULL 表示失败
 */
rs232_inst_t * rs232_create(const char *serial, int baudrate, int parity);


/* 销毁 RS232 实例
 * @param hinst    RS232 实例句柄
 * @return         RT_EOK 表示成功，否则失败
 */
int rs232_destory(rs232_inst_t * hinst);


/* 配置 RS232 参数
 * @param hinst    RS232 实例句柄
 * @param baudrate 波特率
 * @param databits 数据位（5~8）
 * @param parity   奇偶校验（0: 无，1: 奇，2: 偶）
 * @param stopbits 停止位（0: 1位，1: 2位）
 * @return         RT_EOK 表示成功，否则失败
 */
int rs232_config(rs232_inst_t * hinst, int baudrate, int databits, int parity, int stopbits);

/* 设置字节间隔超时
 * @param hinst    RS232 实例句柄
 * @param tmo_ms   超时时间（ms），默认根据波特率计算
 * @return         RT_EOK 表示成功，否则失败
 */
int rs232_set_byte_tmo(rs232_inst_t * hinst, int tmo_ms);

/* 连接（打开）RS232
 * @param hinst    RS232 实例句柄
 * @return         RT_EOK 表示成功，否则失败
 */
int rs232_connect(rs232_inst_t * hinst);

/* 断开（关闭）RS232
 * @param hinst    RS232 实例句柄
 * @return         RT_EOK 表示成功，否则失败
 */
int rs232_disconn(rs232_inst_t * hinst);

/* 接收数据
 * @param hinst    RS232 实例句柄
 * @param buf      接收缓冲区
 * @param size     最大接收长度
 * @return         实际接收长度，或 <0 表示错误
 */
int rs232_recv(rs232_inst_t * hinst, void *buf, int size);

/* 发送数据
 * @param hinst    RS232 实例句柄
 * @param buf      发送缓冲区
 * @param size     发送长度
 * @return         实际发送长度，或 <0 表示错误
 */
int rs232_send(rs232_inst_t * hinst, void *buf, int size);





#endif /* APPLICATIONS_MACBSP_INC_BSP_RS232_DRV_H_ */

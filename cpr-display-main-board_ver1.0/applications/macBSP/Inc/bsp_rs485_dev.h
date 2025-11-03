/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-03     Administrator       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_BSP_RS485_DEV_H_
#define APPLICATIONS_MACBSP_INC_BSP_RS485_DEV_H_

#include "bsp_sys.h"



//rs485-device-name, serial-device-name, baudrate, parity(0~2), control-pin, send-level(0~1)
#define RS485_DEV_CFG_TABLE {                               \
    {"rs485-1", "uart3",    115200, 0,  GET_PIN(B, 6),  1}, \
}

#define RS485_CTRL_CFG              0
#define RS485_CTRL_SET_TMO          1
#define RS485_CTRL_BREAK_RECV       2
#define RS485_CTRL_SEND_THEN_RECV   3


/**
 *
 */
typedef struct{
    const char *rs485;//rs485 device name
    const char *serial;//serial device name
    int baudrate;//baudrate of communication
    int parity;//parity bit, 0~2, 0 - none, 1 - odd, 2 - even
    int pin;//mode contrle pin
    int level;//send mode level
}rs485_dev_cfg_t;


/**
 * 配置 UART 底层参数（波特率、数据位、校验位、停止位）,不涉及引脚方向
 */
typedef struct {
    rt_uint32_t baudrate;     // 波特率，如 9600, 115200
    rt_uint8_t  databits;     // 数据位：5~8
    rt_uint8_t  parity;       // 校验：NONE, ODD, EVEN
    rt_uint8_t  stopbits;     // 停止位：1, 2
} rs485_dev_cfg_param_t;


/**
 *
 */
typedef struct{
    int ack_tmo_ms;
    int byte_tmo_ms;
}rs485_dev_tmo_param_t;


/**
 *
 *
 *
 */
typedef struct{
    void *sbuf;
    int slen;
    void *rbuf;
    int rlen;
}rs485_dev_send_then_recv_param_t;


/**
 *
 *
 *
 */
typedef struct
{
    struct rt_device parent;
    rs485_inst_t *hinst;
}rs485_dev_t;



#endif /* APPLICATIONS_MACBSP_INC_BSP_RS485_DEV_H_ */

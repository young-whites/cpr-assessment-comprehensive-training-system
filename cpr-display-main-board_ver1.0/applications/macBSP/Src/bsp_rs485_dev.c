/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-03     Administrator       the first version
 */
#include "bsp_rs485_dev.h"


#include <rs485_dev_cfg.h>

#define DBG_TAG "rs485.dev"
#define DBG_LVL DBG_INFO
#include <rtdbg.h>

static rt_err_t rs485_dev_open(rt_device_t dev)
{
    /* 把dev结构体指针赋值给pdev */
    rs485_dev_t *pdev = (rs485_dev_t *)dev;
    return(rs485_connect(pdev->hinst));
}

/***
 * @brief
 * @param dev
 * @return
 */
static rt_err_t rs485_dev_close(rt_device_t dev)
{
    rs485_dev_t *pdev = (rs485_dev_t *)dev;
    return(rs485_disconn(pdev->hinst));
}

/***
 * @param dev       设备句柄
 * @param pos       参数会被传入但忽略(RS485是流设备)
 * @param buffer    接收来自从机的数据
 * @param size      决定最多读取多少字节(可能返回少于size的值)
 * @return  返回实际读取的字节数(≥0)或者错误码
 */
static rt_ssize_t rs485_dev_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    rs485_dev_t *pdev = (rs485_dev_t *)dev;
    return(rs485_recv(pdev->hinst, buffer, size));
}

/***
 * @param dev       设备句柄
 * @param pos       写入偏移量，对流式设备（如串口、RS485）通常被忽略
 * @param buffer    用户数据缓冲区，包含要发送的数据（只读）
 * @param size      要发送的字节数
 * @return 返回实际写入的字节数；成功 ≥0，失败返回负值（如 RT_ERROR）
 */
static rt_ssize_t rs485_dev_write(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size)
{
    rs485_dev_t *pdev = (rs485_dev_t *)dev;
    return(rs485_send(pdev->hinst, (void *)buffer, size));
}



static rt_err_t rs485_dev_control(rt_device_t dev, int cmd, void *args)
{
    rt_err_t rst = RT_EINVAL;               // 默认返回“无效参数”
    rs485_dev_t *pdev = (rs485_dev_t *)dev; // 转为私有设备结构体


    switch(cmd)
    {
        /* 配置串口参数 */
        case RS485_CTRL_CFG:
            if (args)
            {
                rs485_dev_cfg_param_t *params = (rs485_dev_cfg_param_t *)args;
                rst = rs485_config(pdev->hinst, params->baudrate, params->databits, params->parity, params->stopbits);
            }
            break;
        /*  */
        case RS485_CTRL_SET_TMO:
            if (args)
            {
                rs485_dev_tmo_param_t *params = (rs485_dev_tmo_param_t *)args;
                rst = rs485_set_recv_tmo(pdev->hinst, params->ack_tmo_ms);
                if (rst != RT_EOK) break;
                rst = rs485_set_byte_tmo(pdev->hinst, params->byte_tmo_ms);
            }
            break;
        case RS485_CTRL_BREAK_RECV:
            rst = rs485_break_recv(pdev->hinst);
            break;
        case RS485_CTRL_SEND_THEN_RECV:
            if (args)
            {
                rs485_dev_send_then_recv_param_t *params = (rs485_dev_send_then_recv_param_t *)args;
                rst = rs485_send_then_recv(pdev->hinst, params->sbuf, params->slen, params->rbuf, params->rlen);
            }
            break;
        default:
            break;
    }
    return(rst);
}

#ifdef RT_USING_DEVICE_OPS
static const struct rt_device_ops rs485_dev_ops = {
    RT_NULL,
    rs485_dev_open,
    rs485_dev_close,
    rs485_dev_read,
    rs485_dev_write,
    rs485_dev_control
};
#endif

static const rs485_dev_cfg_t rs485_dev_cfg_table[] = RS485_DEV_CFG_TABLE;

static int rs485_dev_create(void)
{
    for(int i=0; i<(sizeof(rs485_dev_cfg_table)/sizeof(rs485_dev_cfg_table[0])); i++)
    {
        rs485_dev_t *dev = (rs485_dev_t *)rt_calloc(1, sizeof(rs485_dev_t));
        if (dev == RT_NULL)
        {
            return(-RT_ENOMEM);
        }

        rs485_dev_cfg_t *pcfg = (rs485_dev_cfg_t *)rs485_dev_cfg_table + i;
        dev->hinst = rs485_create(pcfg->serial, pcfg->baudrate, pcfg->parity, pcfg->pin, pcfg->level);
        if (dev->hinst == RT_NULL)
        {
            rt_free(dev);
            return(-RT_ENOMEM);
        }

        dev->parent.type = RT_Device_Class_Char;

        #ifdef RT_USING_DEVICE_OPS
        dev->parent.ops = &rs485_dev_ops;
        #else
        dev->parent.init = NULL;
        dev->parent.open = (void *)rs485_dev_open;
        dev->parent.close = (void *)rs485_dev_close;
        dev->parent.read = (void *)rs485_dev_read;
        dev->parent.write = (void *)rs485_dev_write;
        dev->parent.control = (void *)rs485_dev_control;
        #endif

        rt_device_register((rt_device_t)dev, pcfg->rs485, RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STREAM | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX);
    }

    return(RT_EOK);
}
INIT_DEVICE_EXPORT(rs485_dev_create);


















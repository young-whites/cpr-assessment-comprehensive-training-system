/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-04     Administrator       the first version
 */
#include "bsp_rs485_message.h"



static uint16_t crc16_modbus(uint8_t *dat,uint8_t len)
{
    uint16_t    CRC_index = 0xffff;
    uint16_t    buffer;
    volatile    uint8_t i = 0, j = 0;
    for(i = 0; i < len; i++){
        buffer = dat[i];
        CRC_index ^= buffer;
        for(j = 0; j < 8; j++){
            if(CRC_index & 0x0001){
                CRC_index >>= 1;
                CRC_index ^= 0xa001;
            }else{
                CRC_index >>= 1;
            }
        }
    }
    return CRC_index;
}







void my_protocol_decode(uint8_t *frame, int len, int port_idx)
{
    if(len < 4) return;

    uint8_t addr = frame[0];
    uint8_t func = frame[1];
    uint16_t crc = frame[len-2] | (frame[len-1]<<8);

    if(crc16_modbus(frame, len-2) != crc){
        rt_kprintf("crc16 error!\n");
        return;
    }


    // 地址过滤
    if(addr != RS485_SLAVE_ADDR && addr != 0x00) return;

    switch(func)
    {
        case 0x03:  // 读保持寄存器
        {

        }break;


        case 0x10:  // 写多个寄存器
        {

        }break;


        default: break;
    }
}














void rs485_decode_thread_entry(void *paragram)
{



    while(1)
    {

    }

}




rt_thread_t rs485_decode_thread_handle;
int rs485_decode_thread_init(void)
{

    // 接收解码线程------------------------------------------------------------------------------------------
    rs485_decode_thread_handle = rt_thread_create(" rs485_decode_thread_entry",
                                                    rs485_decode_thread_entry,
                                                    RT_NULL, 1024, 10, 200);
    if(rs485_decode_thread_handle != RT_NULL){
        rt_kprintf("PRINTF:%d. rs485 decode thread is created!!\r\n",Record.kprintf_cnt++);
        rt_thread_startup(rs485_decode_thread_handle);
    }
    else {
        rt_kprintf("PRINTF:%d. rs485 decode is not created!!\r\n",Record.kprintf_cnt++);
    }

    return RT_EOK;
}









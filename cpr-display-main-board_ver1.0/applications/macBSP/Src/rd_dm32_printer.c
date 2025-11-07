/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-07     18452       the first version
 */
#include "rd_dm32_printer.h"
#include "bsp_rs232_drv.h"


extern rs232_inst_t *printer_hinst;


/**
 * @brief 清除打印缓冲区中的数据，复位打印参数到当前打印机缺省参数
 * @param ASCII -> ESC @
 * @param HEX   -> 1B  40
 * @note  打印机接收缓冲区的数据并不被清除
 */
void rd_printer_reset_cmd(void)
{
    static rt_uint8_t cmd_buf[2] = {0x1B, 0x40};
    rs232_send(printer_hinst, cmd_buf, sizeof(cmd_buf));
}


/**
 * @brief 将打印缓冲区中的数据全部打印出来并返回标准模式
 * @param ASCII -> FF
 * @param HEX   -> 0C
 * @note  如果打印纸有预印刷黑标，则打印缓冲区中的数据后，走纸到黑标处，如果打印纸无黑标，则走纸30cm后停止
 */
void rd_printer_print_to_next_page_cmd(void)
{
    static rt_uint8_t cmd_buf[1] = {0x0C};
    rs232_send(printer_hinst, cmd_buf, sizeof(cmd_buf));
}


/**
 * @brief 打印并换行
 * @param ASCII -> LF
 * @param HEX   -> 0A
 * @note
 */
void rd_printer_print_and_line_feed_cmd(void)
{
    static rt_uint8_t cmd_buf[1] = {0x0A};
    rs232_send(printer_hinst, cmd_buf, sizeof(cmd_buf));
}



/**
 * @brief 打印并回车
 * @param ASCII -> CR
 * @param HEX   -> 0D
 * @note
 */
void rd_printer_print_and_enter_cmd(void)
{
    static rt_uint8_t cmd_buf[1] = {0x0D};
    rs232_send(printer_hinst, cmd_buf, sizeof(cmd_buf));
}



/**
 * @brief 打印输出打印缓冲区中的数据，并进纸[n ⅹ 0.125mm(0.0049”)]
 * @param ASCII -> ESC J   n （0 ≤ n ≤ 255）
 * @param HEX   -> 1B  4A  n （0 ≤ n ≤ 255）
 * @note  打印结束后，将下一行的开始设定为打印起始位置
 *
 */
void rd_printer_print_and_formfeed_1_cmd(rt_uint8_t n)
{
    rt_uint8_t cmd_buf[3] = { 0 };
    cmd_buf[0] = 0x1B;
    cmd_buf[1] = 0x4A;
    cmd_buf[2] = n;
    rs232_send(printer_hinst, cmd_buf, sizeof(cmd_buf));
}


/**
 * @brief 打印输出打印缓冲区中的数据，并进纸n行
 * @param ASCII -> ESC d   n （0 ≤ n ≤ 255）
 * @param HEX   -> 1B  64  n （0 ≤ n ≤ 255）
 * @note  一行的距离为24个垂直点距(0.125mm)
 *        打印结束后，该命令设置打印起始位置为行起点
 *
 */
void rd_printer_print_and_formfeed_2_cmd(rt_uint8_t n)
{
    rt_uint8_t cmd_buf[3] = { 0 };
    cmd_buf[0] = 0x1B;
    cmd_buf[1] = 0x64;
    cmd_buf[2] = n;
    rs232_send(printer_hinst, cmd_buf, sizeof(cmd_buf));
}


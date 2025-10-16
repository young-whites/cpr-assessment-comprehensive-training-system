/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-05-15     teati       the first version
 */
#ifndef APPLICATIONS_MACSYS_INC_BSP_SYS_H_

#define APPLICATIONS_MACSYS_INC_BSP_SYS_H_

/* RTT实时操作系统的头文件 */
#include <rtthread.h>
#include <drv_common.h>
#include <board.h>
#include <rtdevice.h>
#include <rthw.h>
#include <drv_spi.h>
#include <rtdbg.h>

/* 该头文件包含了所有CubeMX自动生成的初始化引脚 */
#include "main.h"

/* macAPP 头文件 */
#include "rtt_system_work.h"

/* macBSP 头文件 */
#include "bsp_hard.h"
#include "bsp_key.h"
#include "bsp_led.h"
#include "ft6336u_driver.h"
#include "ft6336u_iic.h"
#include "lcd_driver.h"
#include "st7789_driver.h"
#include "st7789_spi.h"
#include "bsp_battery.h"
#include "bsp_lora_spi.h"
#include "23lc1024_sram_spi.h"
#include "23lc1024_sram_test.h"
#include "23lc1024_sram_tlsf.h"
#include "tlsf.h"

/* macSYS 头文件 */
#include "bsp_typedef.h"

/* LVGL 路径下头文件 */
#include "lvgl_gui.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include <macGUI/lvgl_custom/setup_scr_screen.h>
#include <macGUI/lvgl_examples/lvgl_tests.h>


// 这个宏用于使能lv_printf.c文件中的lv_snprintf()函数
#define USE_LV_SNPRINTF     0




#endif /* APPLICATIONS_MACSYS_INC_BSP_SYS_H_ */

#include <basic_widgets.h>
/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-26     18452       the first version
 */


void draw_basic_button(void)
{
    lv_obj_t* obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, 50, 50);
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00ff00), LV_STATE_DEFAULT);
}














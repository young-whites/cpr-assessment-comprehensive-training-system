/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-02     Administrator       the first version
 */
#include "bsp_sys.h"





void setup_scr_screen_data(lvgl_ui_t *ui)
{
    //Write codes screen_data
    ui->screen_data = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_data, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_data, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_data_cont_1
    ui->screen_data_cont_1 = lv_obj_create(ui->screen_data);
    lv_obj_set_pos(ui->screen_data_cont_1, 0, 0);
    lv_obj_set_size(ui->screen_data_cont_1, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_data_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_data_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_data_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_data_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_data_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_data_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_data_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_data_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_data_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_data_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_data_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_data_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_data_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_data_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_data_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_data.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_data);

}














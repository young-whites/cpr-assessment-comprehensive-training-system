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

    //Write codes screen_data_cont_data
    ui->screen_data_cont_data = lv_obj_create(ui->screen_data);
    lv_obj_set_pos(ui->screen_data_cont_data, 0, 0);
    lv_obj_set_size(ui->screen_data_cont_data, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_data_cont_data, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_data_cont_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_data_cont_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_data_cont_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_data_cont_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_data_cont_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_data_cont_data, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_data_cont_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_data_cont_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_data_cont_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_data_cont_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_data_cont_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_data_label_1_model
    ui->screen_data_label_1_model = lv_label_create(ui->screen_data_cont_data);
    lv_label_set_text(ui->screen_data_label_1_model, "心肺复苏操作模型");
    lv_label_set_long_mode(ui->screen_data_label_1_model, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_data_label_1_model, 40, 12);
    lv_obj_set_size(ui->screen_data_label_1_model, 161, 40);

    //Write style for screen_data_label_1_model, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_data_label_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_data_label_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_data_label_1_model, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_data_label_1_model, &lv_font_SourceHanSerifSC_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_data_label_1_model, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_data_label_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_data_label_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_data_label_1_model, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_data_label_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_data_label_1_model, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_data_label_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_data_label_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_data_label_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_data_label_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_data.

    //Update current screen layout.
    lv_obj_update_layout(ui->screen_data);

}














/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-03     Administrator       the first version
 */
#include "bsp_sys.h"




void setup_scr_screen_setting(lvgl_ui_t *ui)
{
    //Write codes screen_setting
    ui->screen_setting = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_setting, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_setting, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_setting_cont_setting
    ui->screen_setting_cont_setting = lv_obj_create(ui->screen_setting);
    lv_obj_set_pos(ui->screen_setting_cont_setting, 0, 0);
    lv_obj_set_size(ui->screen_setting_cont_setting, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_setting_cont_setting, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_setting_cont_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_setting_cont_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_setting_cont_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_setting_cont_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_setting_cont_setting, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_setting_cont_setting, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_setting_cont_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_setting_cont_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_setting_cont_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_setting_cont_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_setting_cont_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_setting_btn_1_time_set
    ui->screen_setting_btn_1_time_set = lv_btn_create(ui->screen_setting_cont_setting);
    lv_obj_add_flag(ui->screen_setting_btn_1_time_set, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_setting_btn_1_time_set_label = lv_label_create(ui->screen_setting_btn_1_time_set);
    lv_label_set_text(ui->screen_setting_btn_1_time_set_label, "时间设置");
    lv_label_set_long_mode(ui->screen_setting_btn_1_time_set_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_setting_btn_1_time_set_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_setting_btn_1_time_set, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_setting_btn_1_time_set_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_setting_btn_1_time_set, 55, 47);
    lv_obj_set_size(ui->screen_setting_btn_1_time_set, 130, 37);

    //Write style for screen_setting_btn_1_time_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_setting_btn_1_time_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_setting_btn_1_time_set, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_setting_btn_1_time_set, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_setting_btn_1_time_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_setting_btn_1_time_set, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_setting_btn_1_time_set, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_setting_btn_1_time_set, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_setting_btn_1_time_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_setting_btn_1_time_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_setting_btn_1_time_set, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_setting_btn_1_time_set, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_setting_btn_1_time_set, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_setting_btn_1_time_set, &lv_font_AlimamaDongFangDaKai_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_setting_btn_1_time_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_setting_btn_1_time_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_setting_label_1_set
    ui->screen_setting_label_1_set = lv_label_create(ui->screen_setting_cont_setting);
    lv_label_set_text(ui->screen_setting_label_1_set, "设置");
    lv_label_set_long_mode(ui->screen_setting_label_1_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_setting_label_1_set, 68, 5);
    lv_obj_set_size(ui->screen_setting_label_1_set, 100, 32);

    //Write style for screen_setting_label_1_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_setting_label_1_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_setting_label_1_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_setting_label_1_set, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_setting_label_1_set, &lv_font_AlimamaDongFangDaKai_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_setting_label_1_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_setting_label_1_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_setting_label_1_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_setting_label_1_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_setting_label_1_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_setting_label_1_set, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_setting_label_1_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_setting_label_1_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_setting_label_1_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_setting_label_1_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_setting_btn_2_press_rate
    ui->screen_setting_btn_2_press_rate = lv_btn_create(ui->screen_setting_cont_setting);
    lv_obj_add_flag(ui->screen_setting_btn_2_press_rate, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_setting_btn_2_press_rate_label = lv_label_create(ui->screen_setting_btn_2_press_rate);
    lv_label_set_text(ui->screen_setting_btn_2_press_rate_label, "按压达标率");
    lv_label_set_long_mode(ui->screen_setting_btn_2_press_rate_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_setting_btn_2_press_rate_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_setting_btn_2_press_rate, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_setting_btn_2_press_rate_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_setting_btn_2_press_rate, 55, 107);
    lv_obj_set_size(ui->screen_setting_btn_2_press_rate, 130, 37);

    //Write style for screen_setting_btn_2_press_rate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_setting_btn_2_press_rate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_setting_btn_2_press_rate, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_setting_btn_2_press_rate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_setting_btn_2_press_rate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_setting_btn_2_press_rate, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_setting_btn_2_press_rate, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_setting_btn_2_press_rate, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_setting_btn_2_press_rate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_setting_btn_2_press_rate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_setting_btn_2_press_rate, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_setting_btn_2_press_rate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_setting_btn_2_press_rate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_setting_btn_2_press_rate, &lv_font_AlimamaDongFangDaKai_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_setting_btn_2_press_rate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_setting_btn_2_press_rate, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_setting_btn_plus
    ui->screen_setting_btn_plus = lv_btn_create(ui->screen_setting_cont_setting);
    ui->screen_setting_btn_plus_label = lv_label_create(ui->screen_setting_btn_plus);
    lv_label_set_text(ui->screen_setting_btn_plus_label, "-");
    lv_label_set_long_mode(ui->screen_setting_btn_plus_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_setting_btn_plus_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_setting_btn_plus, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_setting_btn_plus_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_setting_btn_plus, 10, 249);
    lv_obj_set_size(ui->screen_setting_btn_plus, 45, 33);
    lv_obj_add_flag(ui->screen_setting_btn_plus, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_setting_btn_plus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_setting_btn_plus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_setting_btn_plus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_setting_btn_plus, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_setting_btn_plus, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_setting_btn_plus, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_setting_btn_plus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_setting_btn_plus, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_setting_btn_plus, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_setting_btn_plus, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_setting_btn_plus, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_setting_btn_plus, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_setting_btn_plus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_setting_btn_plus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_setting_label_time_value
    ui->screen_setting_label_time_value = lv_label_create(ui->screen_setting_cont_setting);
    lv_label_set_text(ui->screen_setting_label_time_value, "200s");
    lv_label_set_long_mode(ui->screen_setting_label_time_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_setting_label_time_value, 70, 244);
    lv_obj_set_size(ui->screen_setting_label_time_value, 109, 43);
    lv_obj_add_flag(ui->screen_setting_label_time_value, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_setting_label_time_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_setting_label_time_value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_setting_label_time_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_setting_label_time_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_setting_label_time_value, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_setting_label_time_value, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_setting_label_time_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_setting_label_time_value, &lv_font_SourceHanSerifSC_Regular_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_setting_label_time_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_setting_label_time_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_setting_label_time_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_setting_label_time_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_setting_label_time_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_setting_label_time_value, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_setting_label_time_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_setting_label_time_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_setting_label_time_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_setting_label_time_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_setting_btn_minus
    ui->screen_setting_btn_minus = lv_btn_create(ui->screen_setting_cont_setting);
    ui->screen_setting_btn_minus_label = lv_label_create(ui->screen_setting_btn_minus);
    lv_label_set_text(ui->screen_setting_btn_minus_label, "+");
    lv_label_set_long_mode(ui->screen_setting_btn_minus_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_setting_btn_minus_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_setting_btn_minus, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_setting_btn_minus_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_setting_btn_minus, 188, 249);
    lv_obj_set_size(ui->screen_setting_btn_minus, 45, 33);
    lv_obj_add_flag(ui->screen_setting_btn_minus, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_setting_btn_minus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_setting_btn_minus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_setting_btn_minus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_setting_btn_minus, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_setting_btn_minus, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_setting_btn_minus, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_setting_btn_minus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_setting_btn_minus, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_setting_btn_minus, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_setting_btn_minus, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_setting_btn_minus, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_setting_btn_minus, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_setting_btn_minus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_setting_btn_minus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_setting_btn_3_air_rate
    ui->screen_setting_btn_3_air_rate = lv_btn_create(ui->screen_setting_cont_setting);
    lv_obj_add_flag(ui->screen_setting_btn_3_air_rate, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_setting_btn_3_air_rate_label = lv_label_create(ui->screen_setting_btn_3_air_rate);
    lv_label_set_text(ui->screen_setting_btn_3_air_rate_label, "潮气达标率");
    lv_label_set_long_mode(ui->screen_setting_btn_3_air_rate_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_setting_btn_3_air_rate_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_setting_btn_3_air_rate, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_setting_btn_3_air_rate_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_setting_btn_3_air_rate, 55, 167);
    lv_obj_set_size(ui->screen_setting_btn_3_air_rate, 130, 37);

    //Write style for screen_setting_btn_3_air_rate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_setting_btn_3_air_rate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_setting_btn_3_air_rate, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_setting_btn_3_air_rate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_setting_btn_3_air_rate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_setting_btn_3_air_rate, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_setting_btn_3_air_rate, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_setting_btn_3_air_rate, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_setting_btn_3_air_rate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_setting_btn_3_air_rate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_setting_btn_3_air_rate, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_setting_btn_3_air_rate, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_setting_btn_3_air_rate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_setting_btn_3_air_rate, &lv_font_AlimamaDongFangDaKai_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_setting_btn_3_air_rate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_setting_btn_3_air_rate, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_setting.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_setting);

    //Init events for screen.
    events_init_screen_setting(ui);
}













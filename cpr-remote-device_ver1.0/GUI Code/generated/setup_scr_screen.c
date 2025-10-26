/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_3
    ui->screen_cont_3 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_3, 0, 0);
    lv_obj_set_size(ui->screen_cont_3, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_cont_3, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_cont_3, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_2
    ui->screen_cont_2 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_2, 0, 0);
    lv_obj_set_size(ui->screen_cont_2, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_cont_2, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_cont_2, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_printer
    ui->screen_label_printer = lv_label_create(ui->screen_cont_2);
    lv_label_set_text(ui->screen_label_printer, "打印");
    lv_label_set_long_mode(ui->screen_label_printer, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_printer, 94, 287);
    lv_obj_set_size(ui->screen_label_printer, 55, 18);

    //Write style for screen_label_printer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_printer, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_printer, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_printer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_printer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_assess
    ui->screen_label_assess = lv_label_create(ui->screen_cont_2);
    lv_label_set_text(ui->screen_label_assess, "考核模式");
    lv_label_set_long_mode(ui->screen_label_assess, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_assess, 13, 83);
    lv_obj_set_size(ui->screen_label_assess, 65, 18);

    //Write style for screen_label_assess, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_label_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_label_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_assess, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_assess, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_assess, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_assess, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_competation
    ui->screen_img_competation = lv_img_create(ui->screen_cont_2);
    lv_obj_add_flag(ui->screen_img_competation, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_competation, &_competation_alpha_50x50);
    lv_img_set_pivot(ui->screen_img_competation, 50,50);
    lv_img_set_angle(ui->screen_img_competation, 0);
    lv_obj_set_pos(ui->screen_img_competation, 96, 21);
    lv_obj_set_size(ui->screen_img_competation, 50, 50);

    //Write style for screen_img_competation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_competation, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_competation, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_assess
    ui->screen_img_assess = lv_img_create(ui->screen_cont_2);
    lv_obj_add_flag(ui->screen_img_assess, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_assess, &_assess_alpha_50x50);
    lv_img_set_pivot(ui->screen_img_assess, 50,50);
    lv_img_set_angle(ui->screen_img_assess, 0);
    lv_obj_set_pos(ui->screen_img_assess, 24, 21);
    lv_obj_set_size(ui->screen_img_assess, 50, 50);

    //Write style for screen_img_assess, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_img_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_assess, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_img_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_assess, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_printer
    ui->screen_img_printer = lv_img_create(ui->screen_cont_2);
    lv_obj_add_flag(ui->screen_img_printer, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_printer, &_printer_alpha_50x50);
    lv_img_set_pivot(ui->screen_img_printer, 50,50);
    lv_img_set_angle(ui->screen_img_printer, 0);
    lv_obj_set_pos(ui->screen_img_printer, 96, 224);
    lv_obj_set_size(ui->screen_img_printer, 50, 50);

    //Write style for screen_img_printer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_img_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_printer, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_printer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_competation
    ui->screen_label_competation = lv_label_create(ui->screen_cont_2);
    lv_label_set_text(ui->screen_label_competation, "竞赛模式");
    lv_label_set_long_mode(ui->screen_label_competation, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_competation, 90, 82);
    lv_obj_set_size(ui->screen_label_competation, 68, 19);

    //Write style for screen_label_competation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_label_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_label_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_competation, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_competation, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_competation, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_competation, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_train
    ui->screen_img_train = lv_img_create(ui->screen_cont_2);
    lv_obj_add_flag(ui->screen_img_train, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_train, &_train_alpha_50x50);
    lv_img_set_pivot(ui->screen_img_train, 50,50);
    lv_img_set_angle(ui->screen_img_train, 0);
    lv_obj_set_pos(ui->screen_img_train, 168, 21);
    lv_obj_set_size(ui->screen_img_train, 50, 50);

    //Write style for screen_img_train, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_img_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_train, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_train, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_train
    ui->screen_label_train = lv_label_create(ui->screen_cont_2);
    lv_label_set_text(ui->screen_label_train, "训练模式");
    lv_label_set_long_mode(ui->screen_label_train, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_train, 159, 82);
    lv_obj_set_size(ui->screen_label_train, 68, 19);

    //Write style for screen_label_train, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_label_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_label_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_train, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_train, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_train, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_train, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_score
    ui->screen_img_score = lv_img_create(ui->screen_cont_2);
    lv_obj_add_flag(ui->screen_img_score, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_score, &_score_alpha_50x50);
    lv_img_set_pivot(ui->screen_img_score, 50,50);
    lv_img_set_angle(ui->screen_img_score, 0);
    lv_obj_set_pos(ui->screen_img_score, 24, 121);
    lv_obj_set_size(ui->screen_img_score, 50, 50);

    //Write style for screen_img_score, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_img_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_score, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_score, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_score
    ui->screen_label_score = lv_label_create(ui->screen_cont_2);
    lv_label_set_text(ui->screen_label_score, "成绩查询");
    lv_label_set_long_mode(ui->screen_label_score, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_score, 18, 183);
    lv_obj_set_size(ui->screen_label_score, 65, 18);

    //Write style for screen_label_score, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_score, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_score, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_score, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_score, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_setting
    ui->screen_label_setting = lv_label_create(ui->screen_cont_2);
    lv_label_set_text(ui->screen_label_setting, "设置");
    lv_label_set_long_mode(ui->screen_label_setting, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_setting, 17, 287);
    lv_obj_set_size(ui->screen_label_setting, 65, 18);

    //Write style for screen_label_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_setting, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_setting, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_setting, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_setting
    ui->screen_img_setting = lv_img_create(ui->screen_cont_2);
    lv_obj_add_flag(ui->screen_img_setting, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_setting, &_setting_alpha_50x50);
    lv_img_set_pivot(ui->screen_img_setting, 50,50);
    lv_img_set_angle(ui->screen_img_setting, 0);
    lv_obj_set_pos(ui->screen_img_setting, 23, 224);
    lv_obj_set_size(ui->screen_img_setting, 50, 50);

    //Write style for screen_img_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_img_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_setting, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_operation
    ui->screen_img_operation = lv_img_create(ui->screen_cont_2);
    lv_obj_add_flag(ui->screen_img_operation, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_operation, &_operation_alpha_50x50);
    lv_img_set_pivot(ui->screen_img_operation, 50,50);
    lv_img_set_angle(ui->screen_img_operation, 0);
    lv_obj_set_pos(ui->screen_img_operation, 96, 121);
    lv_obj_set_size(ui->screen_img_operation, 50, 50);

    //Write style for screen_img_operation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_img_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_operation, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_operation, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_switch
    ui->screen_img_switch = lv_img_create(ui->screen_cont_2);
    lv_obj_add_flag(ui->screen_img_switch, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_switch, &_switch_alpha_50x50);
    lv_img_set_pivot(ui->screen_img_switch, 50,50);
    lv_img_set_angle(ui->screen_img_switch, 0);
    lv_obj_set_pos(ui->screen_img_switch, 170, 224);
    lv_obj_set_size(ui->screen_img_switch, 50, 50);

    //Write style for screen_img_switch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_img_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_switch, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_switch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_specification
    ui->screen_img_specification = lv_img_create(ui->screen_cont_2);
    lv_obj_add_flag(ui->screen_img_specification, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_specification, &_specification_alpha_50x50);
    lv_img_set_pivot(ui->screen_img_specification, 50,50);
    lv_img_set_angle(ui->screen_img_specification, 0);
    lv_obj_set_pos(ui->screen_img_specification, 168, 121);
    lv_obj_set_size(ui->screen_img_specification, 50, 50);

    //Write style for screen_img_specification, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_img_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_specification, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_specification, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_operation
    ui->screen_label_operation = lv_label_create(ui->screen_cont_2);
    lv_label_set_text(ui->screen_label_operation, "功能操作");
    lv_label_set_long_mode(ui->screen_label_operation, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_operation, 90, 182);
    lv_obj_set_size(ui->screen_label_operation, 65, 18);

    //Write style for screen_label_operation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_operation, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_operation, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_operation, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_operation, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_switch
    ui->screen_label_switch = lv_label_create(ui->screen_cont_2);
    lv_label_set_text(ui->screen_label_switch, "关闭");
    lv_label_set_long_mode(ui->screen_label_switch, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_switch, 160, 287);
    lv_obj_set_size(ui->screen_label_switch, 65, 18);

    //Write style for screen_label_switch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_switch, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_switch, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_switch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_switch, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_specification
    ui->screen_label_specification = lv_label_create(ui->screen_cont_2);
    lv_label_set_text(ui->screen_label_specification, "使用说明");
    lv_label_set_long_mode(ui->screen_label_specification, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_specification, 160, 183);
    lv_obj_set_size(ui->screen_label_specification, 65, 18);

    //Write style for screen_label_specification, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_specification, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_specification, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_specification, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_specification, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_specification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_1
    ui->screen_cont_1 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_1, 0, 0);
    lv_obj_set_size(ui->screen_cont_1, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_1_start
    ui->screen_btn_1_start = lv_btn_create(ui->screen_cont_1);
    ui->screen_btn_1_start_label = lv_label_create(ui->screen_btn_1_start);
    lv_label_set_text(ui->screen_btn_1_start_label, "开始");
    lv_label_set_long_mode(ui->screen_btn_1_start_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_1_start_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_1_start, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_1_start_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_btn_1_start, 119, 251);
    lv_obj_set_size(ui->screen_btn_1_start, 100, 50);

    //Write style for screen_btn_1_start, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_btn_1_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_1_start, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_1_start, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_1_start, &lv_font_AlimamaDongFangDaKai_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_1_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_1_start, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_btn_1_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_1_start, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_1_start, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_1_start, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_btn_1_start, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_btn_1_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_btn_1_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_btn_1_start, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_btn_1_start, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_1_title
    ui->screen_label_1_title = lv_label_create(ui->screen_cont_1);
    lv_label_set_text(ui->screen_label_1_title, "心肺复苏模型遥控器");
    lv_label_set_long_mode(ui->screen_label_1_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_1_title, 45, 50);
    lv_obj_set_size(ui->screen_label_1_title, 150, 48);

    //Write style for screen_label_1_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_1_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_1_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_1_title, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_1_title, &lv_font_AlimamaDongFangDaKai_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_1_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_1_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_1_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_1_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_1_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_1_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_1_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_1_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_1_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_1_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_2_connect
    ui->screen_label_2_connect = lv_label_create(ui->screen_cont_1);
    lv_label_set_text(ui->screen_label_2_connect, "连接中...");
    lv_label_set_long_mode(ui->screen_label_2_connect, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_2_connect, 45, 125);
    lv_obj_set_size(ui->screen_label_2_connect, 150, 30);
    lv_obj_add_flag(ui->screen_label_2_connect, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_label_2_connect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_2_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_2_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_2_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_2_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_2_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_2_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_2_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_2_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_2_connect, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_2_connect, &lv_font_AlimamaDongFangDaKai_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_2_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_2_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_2_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_2_connect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

    //Init events for screen.
    events_init_screen(ui);
}

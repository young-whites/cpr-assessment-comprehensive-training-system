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




void setup_scr_screen_menu(lvgl_ui_t *ui)
{
    //Write codes screen_menu
    ui->screen_menu = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_menu, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_menu, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_cont_1
    ui->screen_menu_cont_1 = lv_obj_create(ui->screen_menu);
    lv_obj_set_pos(ui->screen_menu_cont_1, 0, 0);
    lv_obj_set_size(ui->screen_menu_cont_1, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_menu_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_menu_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_menu_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_menu_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_menu_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_menu_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_menu_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_menu_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_label_8_pprinter
    ui->screen_menu_label_8_pprinter = lv_label_create(ui->screen_menu_cont_1);
    lv_label_set_text(ui->screen_menu_label_8_pprinter, "打印");
    lv_label_set_long_mode(ui->screen_menu_label_8_pprinter, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_menu_label_8_pprinter, 85, 290);
    lv_obj_set_size(ui->screen_menu_label_8_pprinter, 55, 18);

    //Write style for screen_menu_label_8_pprinter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_menu_label_8_pprinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_label_8_pprinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_label_8_pprinter, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_label_8_pprinter, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_label_8_pprinter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_menu_label_8_pprinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_menu_label_8_pprinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_label_8_pprinter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_label_8_pprinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_menu_label_8_pprinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_menu_label_8_pprinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_menu_label_8_pprinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_menu_label_8_pprinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_label_8_pprinter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_label_1_assess
    ui->screen_menu_label_1_assess = lv_label_create(ui->screen_menu_cont_1);
    lv_label_set_text(ui->screen_menu_label_1_assess, "考核模式");
    lv_label_set_long_mode(ui->screen_menu_label_1_assess, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_menu_label_1_assess, 10, 74);
    lv_obj_set_size(ui->screen_menu_label_1_assess, 65, 18);

    //Write style for screen_menu_label_1_assess, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_menu_label_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_label_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_label_1_assess, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_label_1_assess, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_label_1_assess, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_menu_label_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_menu_label_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_label_1_assess, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_label_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_menu_label_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_menu_label_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_menu_label_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_menu_label_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_label_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_imgbtn_2_competation
    ui->screen_menu_imgbtn_2_competation = lv_imgbtn_create(ui->screen_menu_cont_1);
    lv_obj_add_flag(ui->screen_menu_imgbtn_2_competation, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_menu_imgbtn_2_competation, LV_IMGBTN_STATE_RELEASED, NULL, &_competation_alpha_70x70, NULL);
    ui->screen_menu_imgbtn_2_competation_label = lv_label_create(ui->screen_menu_imgbtn_2_competation);
    lv_label_set_text(ui->screen_menu_imgbtn_2_competation_label, "");
    lv_label_set_long_mode(ui->screen_menu_imgbtn_2_competation_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_imgbtn_2_competation_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_imgbtn_2_competation, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_menu_imgbtn_2_competation, 84, 4);
    lv_obj_set_size(ui->screen_menu_imgbtn_2_competation, 70, 70);

    //Write style for screen_menu_imgbtn_2_competation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_2_competation, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_2_competation, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_2_competation, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_imgbtn_2_competation, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_imgbtn_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_menu_imgbtn_2_competation, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_menu_imgbtn_2_competation, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_2_competation, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_2_competation, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_2_competation, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_2_competation, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_2_competation, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_2_competation, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_menu_imgbtn_2_competation, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_2_competation, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_2_competation, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_2_competation, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_2_competation, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_2_competation, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_2_competation, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_menu_imgbtn_2_competation, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_2_competation, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_2_competation, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_menu_imgbtn_3_train
    ui->screen_menu_imgbtn_3_train = lv_imgbtn_create(ui->screen_menu_cont_1);
    lv_obj_add_flag(ui->screen_menu_imgbtn_3_train, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_menu_imgbtn_3_train, LV_IMGBTN_STATE_RELEASED, NULL, &_train_alpha_70x67, NULL);
    ui->screen_menu_imgbtn_3_train_label = lv_label_create(ui->screen_menu_imgbtn_3_train);
    lv_label_set_text(ui->screen_menu_imgbtn_3_train_label, "");
    lv_label_set_long_mode(ui->screen_menu_imgbtn_3_train_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_imgbtn_3_train_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_imgbtn_3_train, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_menu_imgbtn_3_train, 165, 5);
    lv_obj_set_size(ui->screen_menu_imgbtn_3_train, 70, 67);

    //Write style for screen_menu_imgbtn_3_train, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_3_train, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_3_train, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_3_train, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_imgbtn_3_train, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_imgbtn_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_menu_imgbtn_3_train, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_menu_imgbtn_3_train, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_3_train, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_3_train, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_3_train, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_3_train, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_3_train, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_3_train, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_menu_imgbtn_3_train, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_3_train, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_3_train, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_3_train, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_3_train, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_3_train, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_3_train, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_menu_imgbtn_3_train, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_3_train, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_3_train, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_menu_label_2_competation
    ui->screen_menu_label_2_competation = lv_label_create(ui->screen_menu_cont_1);
    lv_label_set_text(ui->screen_menu_label_2_competation, "竞赛模式");
    lv_label_set_long_mode(ui->screen_menu_label_2_competation, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_menu_label_2_competation, 85, 74);
    lv_obj_set_size(ui->screen_menu_label_2_competation, 68, 19);

    //Write style for screen_menu_label_2_competation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_menu_label_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_menu_label_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_label_2_competation, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_label_2_competation, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_label_2_competation, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_menu_label_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_menu_label_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_label_2_competation, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_label_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_menu_label_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_menu_label_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_menu_label_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_menu_label_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_label_2_competation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_label_3_train
    ui->screen_menu_label_3_train = lv_label_create(ui->screen_menu_cont_1);
    lv_label_set_text(ui->screen_menu_label_3_train, "训练模式");
    lv_label_set_long_mode(ui->screen_menu_label_3_train, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_menu_label_3_train, 160, 74);
    lv_obj_set_size(ui->screen_menu_label_3_train, 68, 19);

    //Write style for screen_menu_label_3_train, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_menu_label_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_label_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_label_3_train, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_label_3_train, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_label_3_train, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_menu_label_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_menu_label_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_label_3_train, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_label_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_menu_label_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_menu_label_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_menu_label_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_menu_label_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_label_3_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_label_4_score
    ui->screen_menu_label_4_score = lv_label_create(ui->screen_menu_cont_1);
    lv_label_set_text(ui->screen_menu_label_4_score, "成绩查询");
    lv_label_set_long_mode(ui->screen_menu_label_4_score, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_menu_label_4_score, 10, 170);
    lv_obj_set_size(ui->screen_menu_label_4_score, 65, 18);

    //Write style for screen_menu_label_4_score, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_menu_label_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_label_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_label_4_score, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_label_4_score, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_label_4_score, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_menu_label_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_menu_label_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_label_4_score, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_label_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_menu_label_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_menu_label_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_menu_label_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_menu_label_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_label_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_label_7_settings
    ui->screen_menu_label_7_settings = lv_label_create(ui->screen_menu_cont_1);
    lv_label_set_text(ui->screen_menu_label_7_settings, "设置");
    lv_label_set_long_mode(ui->screen_menu_label_7_settings, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_menu_label_7_settings, 10, 290);
    lv_obj_set_size(ui->screen_menu_label_7_settings, 65, 18);

    //Write style for screen_menu_label_7_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_menu_label_7_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_label_7_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_label_7_settings, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_label_7_settings, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_label_7_settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_menu_label_7_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_menu_label_7_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_label_7_settings, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_label_7_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_menu_label_7_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_menu_label_7_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_menu_label_7_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_menu_label_7_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_label_7_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_label_5_operation
    ui->screen_menu_label_5_operation = lv_label_create(ui->screen_menu_cont_1);
    lv_label_set_text(ui->screen_menu_label_5_operation, "功能操作");
    lv_label_set_long_mode(ui->screen_menu_label_5_operation, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_menu_label_5_operation, 85, 170);
    lv_obj_set_size(ui->screen_menu_label_5_operation, 65, 18);

    //Write style for screen_menu_label_5_operation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_menu_label_5_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_label_5_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_label_5_operation, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_label_5_operation, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_label_5_operation, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_menu_label_5_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_menu_label_5_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_label_5_operation, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_label_5_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_menu_label_5_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_menu_label_5_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_menu_label_5_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_menu_label_5_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_label_5_operation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_label_9_switch
    ui->screen_menu_label_9_switch = lv_label_create(ui->screen_menu_cont_1);
    lv_label_set_text(ui->screen_menu_label_9_switch, "关闭");
    lv_label_set_long_mode(ui->screen_menu_label_9_switch, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_menu_label_9_switch, 160, 290);
    lv_obj_set_size(ui->screen_menu_label_9_switch, 65, 18);

    //Write style for screen_menu_label_9_switch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_menu_label_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_label_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_label_9_switch, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_label_9_switch, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_label_9_switch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_menu_label_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_menu_label_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_label_9_switch, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_label_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_menu_label_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_menu_label_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_menu_label_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_menu_label_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_label_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_imgbtn_9_switch
    ui->screen_menu_imgbtn_9_switch = lv_imgbtn_create(ui->screen_menu_cont_1);
    lv_obj_add_flag(ui->screen_menu_imgbtn_9_switch, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_menu_imgbtn_9_switch, LV_IMGBTN_STATE_RELEASED, NULL, &_switch_alpha_75x75, NULL);
    ui->screen_menu_imgbtn_9_switch_label = lv_label_create(ui->screen_menu_imgbtn_9_switch);
    lv_label_set_text(ui->screen_menu_imgbtn_9_switch_label, "");
    lv_label_set_long_mode(ui->screen_menu_imgbtn_9_switch_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_imgbtn_9_switch_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_imgbtn_9_switch, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_menu_imgbtn_9_switch, 160, 210);
    lv_obj_set_size(ui->screen_menu_imgbtn_9_switch, 75, 75);

    //Write style for screen_menu_imgbtn_9_switch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_9_switch, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_9_switch, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_9_switch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_imgbtn_9_switch, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_imgbtn_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_menu_imgbtn_9_switch, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_9_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_menu_imgbtn_9_switch, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_9_switch, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_9_switch, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_9_switch, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_9_switch, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_9_switch, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_9_switch, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_menu_imgbtn_9_switch, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_9_switch, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_9_switch, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_9_switch, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_9_switch, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_9_switch, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_9_switch, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_menu_imgbtn_9_switch, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_9_switch, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_9_switch, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_menu_imgbtn_5_opreation
    ui->screen_menu_imgbtn_5_opreation = lv_imgbtn_create(ui->screen_menu_cont_1);
    lv_obj_add_flag(ui->screen_menu_imgbtn_5_opreation, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_menu_imgbtn_5_opreation, LV_IMGBTN_STATE_RELEASED, NULL, &_operation_alpha_70x70, NULL);
    ui->screen_menu_imgbtn_5_opreation_label = lv_label_create(ui->screen_menu_imgbtn_5_opreation);
    lv_label_set_text(ui->screen_menu_imgbtn_5_opreation_label, "");
    lv_label_set_long_mode(ui->screen_menu_imgbtn_5_opreation_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_imgbtn_5_opreation_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_imgbtn_5_opreation, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_menu_imgbtn_5_opreation, 85, 95);
    lv_obj_set_size(ui->screen_menu_imgbtn_5_opreation, 70, 70);

    //Write style for screen_menu_imgbtn_5_opreation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_5_opreation, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_5_opreation, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_5_opreation, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_imgbtn_5_opreation, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_imgbtn_5_opreation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_menu_imgbtn_5_opreation, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_5_opreation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_menu_imgbtn_5_opreation, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_5_opreation, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_5_opreation, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_5_opreation, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_5_opreation, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_5_opreation, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_5_opreation, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_menu_imgbtn_5_opreation, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_5_opreation, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_5_opreation, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_5_opreation, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_5_opreation, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_5_opreation, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_5_opreation, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_menu_imgbtn_5_opreation, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_5_opreation, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_5_opreation, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_menu_label_6_instructions
    ui->screen_menu_label_6_instructions = lv_label_create(ui->screen_menu_cont_1);
    lv_label_set_text(ui->screen_menu_label_6_instructions, "使用说明");
    lv_label_set_long_mode(ui->screen_menu_label_6_instructions, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_menu_label_6_instructions, 160, 170);
    lv_obj_set_size(ui->screen_menu_label_6_instructions, 65, 18);

    //Write style for screen_menu_label_6_instructions, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_menu_label_6_instructions, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_label_6_instructions, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_label_6_instructions, lv_color_hex(0x2F35DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_label_6_instructions, &lv_font_AlimamaDongFangDaKai_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_label_6_instructions, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_menu_label_6_instructions, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_menu_label_6_instructions, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_label_6_instructions, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_label_6_instructions, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_menu_label_6_instructions, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_menu_label_6_instructions, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_menu_label_6_instructions, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_menu_label_6_instructions, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_label_6_instructions, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_imgbtn_6_instruction
    ui->screen_menu_imgbtn_6_instruction = lv_imgbtn_create(ui->screen_menu_cont_1);
    lv_obj_add_flag(ui->screen_menu_imgbtn_6_instruction, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_menu_imgbtn_6_instruction, LV_IMGBTN_STATE_RELEASED, NULL, &_specification_alpha_70x70, NULL);
    ui->screen_menu_imgbtn_6_instruction_label = lv_label_create(ui->screen_menu_imgbtn_6_instruction);
    lv_label_set_text(ui->screen_menu_imgbtn_6_instruction_label, "");
    lv_label_set_long_mode(ui->screen_menu_imgbtn_6_instruction_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_imgbtn_6_instruction_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_imgbtn_6_instruction, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_menu_imgbtn_6_instruction, 160, 95);
    lv_obj_set_size(ui->screen_menu_imgbtn_6_instruction, 70, 70);

    //Write style for screen_menu_imgbtn_6_instruction, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_6_instruction, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_6_instruction, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_6_instruction, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_imgbtn_6_instruction, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_imgbtn_6_instruction, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_menu_imgbtn_6_instruction, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_6_instruction, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_menu_imgbtn_6_instruction, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_6_instruction, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_6_instruction, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_6_instruction, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_6_instruction, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_6_instruction, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_6_instruction, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_menu_imgbtn_6_instruction, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_6_instruction, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_6_instruction, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_6_instruction, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_6_instruction, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_6_instruction, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_6_instruction, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_menu_imgbtn_6_instruction, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_6_instruction, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_6_instruction, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_menu_imgbtn_7_setting
    ui->screen_menu_imgbtn_7_setting = lv_imgbtn_create(ui->screen_menu_cont_1);
    lv_obj_add_flag(ui->screen_menu_imgbtn_7_setting, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_menu_imgbtn_7_setting, LV_IMGBTN_STATE_RELEASED, NULL, &_setting_alpha_70x70, NULL);
    ui->screen_menu_imgbtn_7_setting_label = lv_label_create(ui->screen_menu_imgbtn_7_setting);
    lv_label_set_text(ui->screen_menu_imgbtn_7_setting_label, "");
    lv_label_set_long_mode(ui->screen_menu_imgbtn_7_setting_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_imgbtn_7_setting_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_imgbtn_7_setting, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_menu_imgbtn_7_setting, 5, 210);
    lv_obj_set_size(ui->screen_menu_imgbtn_7_setting, 70, 70);

    //Write style for screen_menu_imgbtn_7_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_7_setting, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_7_setting, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_7_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_imgbtn_7_setting, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_imgbtn_7_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_menu_imgbtn_7_setting, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_7_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_menu_imgbtn_7_setting, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_7_setting, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_7_setting, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_7_setting, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_7_setting, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_7_setting, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_7_setting, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_menu_imgbtn_7_setting, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_7_setting, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_7_setting, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_7_setting, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_7_setting, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_7_setting, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_7_setting, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_menu_imgbtn_7_setting, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_7_setting, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_7_setting, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_menu_imgbtn_8_printer
    ui->screen_menu_imgbtn_8_printer = lv_imgbtn_create(ui->screen_menu_cont_1);
    lv_obj_add_flag(ui->screen_menu_imgbtn_8_printer, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_menu_imgbtn_8_printer, LV_IMGBTN_STATE_RELEASED, NULL, &_printer_alpha_70x70, NULL);
    ui->screen_menu_imgbtn_8_printer_label = lv_label_create(ui->screen_menu_imgbtn_8_printer);
    lv_label_set_text(ui->screen_menu_imgbtn_8_printer_label, "");
    lv_label_set_long_mode(ui->screen_menu_imgbtn_8_printer_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_imgbtn_8_printer_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_imgbtn_8_printer, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_menu_imgbtn_8_printer, 83, 210);
    lv_obj_set_size(ui->screen_menu_imgbtn_8_printer, 70, 70);

    //Write style for screen_menu_imgbtn_8_printer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_8_printer, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_8_printer, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_8_printer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_imgbtn_8_printer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_imgbtn_8_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_menu_imgbtn_8_printer, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_8_printer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_menu_imgbtn_8_printer, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_8_printer, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_8_printer, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_8_printer, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_8_printer, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_8_printer, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_8_printer, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_menu_imgbtn_8_printer, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_8_printer, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_8_printer, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_8_printer, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_8_printer, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_8_printer, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_8_printer, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_menu_imgbtn_8_printer, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_8_printer, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_8_printer, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_menu_imgbtn_4_score
    ui->screen_menu_imgbtn_4_score = lv_imgbtn_create(ui->screen_menu_cont_1);
    lv_obj_add_flag(ui->screen_menu_imgbtn_4_score, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_menu_imgbtn_4_score, LV_IMGBTN_STATE_RELEASED, NULL, &_score_alpha_70x70, NULL);
    ui->screen_menu_imgbtn_4_score_label = lv_label_create(ui->screen_menu_imgbtn_4_score);
    lv_label_set_text(ui->screen_menu_imgbtn_4_score_label, "");
    lv_label_set_long_mode(ui->screen_menu_imgbtn_4_score_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_imgbtn_4_score_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_imgbtn_4_score, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_menu_imgbtn_4_score, 5, 95);
    lv_obj_set_size(ui->screen_menu_imgbtn_4_score, 70, 70);

    //Write style for screen_menu_imgbtn_4_score, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_4_score, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_4_score, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_4_score, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_imgbtn_4_score, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_imgbtn_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_menu_imgbtn_4_score, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_4_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_menu_imgbtn_4_score, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_4_score, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_4_score, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_4_score, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_4_score, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_4_score, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_4_score, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_menu_imgbtn_4_score, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_4_score, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_4_score, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_4_score, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_4_score, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_4_score, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_4_score, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_menu_imgbtn_4_score, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_4_score, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_4_score, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_menu_imgbtn_1_assess
    ui->screen_menu_imgbtn_1_assess = lv_imgbtn_create(ui->screen_menu_cont_1);
    lv_obj_add_flag(ui->screen_menu_imgbtn_1_assess, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_menu_imgbtn_1_assess, LV_IMGBTN_STATE_RELEASED, NULL, &_assess_alpha_80x70, NULL);
    ui->screen_menu_imgbtn_1_assess_label = lv_label_create(ui->screen_menu_imgbtn_1_assess);
    lv_label_set_text(ui->screen_menu_imgbtn_1_assess_label, "");
    lv_label_set_long_mode(ui->screen_menu_imgbtn_1_assess_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_imgbtn_1_assess_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_imgbtn_1_assess, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_menu_imgbtn_1_assess, 0, 0);
    lv_obj_set_size(ui->screen_menu_imgbtn_1_assess, 80, 70);

    //Write style for screen_menu_imgbtn_1_assess, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_1_assess, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_1_assess, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_1_assess, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_imgbtn_1_assess, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_1_assess, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_imgbtn_1_assess, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_menu_imgbtn_1_assess, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_menu_imgbtn_1_assess, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_1_assess, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_1_assess, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_1_assess, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_1_assess, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_1_assess, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_1_assess, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_menu_imgbtn_1_assess, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_1_assess, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_1_assess, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_menu_imgbtn_1_assess, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_menu_imgbtn_1_assess, &lv_font_SourceHanSerifSC_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_menu_imgbtn_1_assess, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_menu_imgbtn_1_assess, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_menu_imgbtn_1_assess, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_menu_imgbtn_1_assess, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_menu_imgbtn_1_assess, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //The custom code of screen_menu.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_menu);

    //Init events for screen.
    events_init_screen_menu(ui);
}





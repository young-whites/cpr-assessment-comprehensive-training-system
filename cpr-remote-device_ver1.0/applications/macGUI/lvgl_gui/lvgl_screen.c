/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-29     18452       the first version
 */
#include "lvgl_screen.h"







void setup_scr_screen(lvgl_ui_t *ui)
{
    //------------------------------------------------------------------------------------------------------------
    /***
     *! 人为创建一个屏幕对象（根对象）
     *! 区别于 lv_scr_act()，想显现这个屏幕对象时，必须使用 lv_scr_load()
     *! 创建一个新的对象，父对象填 NULL , 这个对象就成为一个屏幕
     */
    // 返回指针保存在 ui->screen_main 中，方便后续引用
    ui->screen_main = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_main, 240, 320);
    // 关闭滚动条，当屏幕内容超出范围会自动出现滚动条，这里直接关掉，保持首页面整洁
    lv_obj_set_scrollbar_mode(ui->screen_main, LV_SCROLLBAR_MODE_OFF);

    //------------------------------------------------------------------------------------------------------------
    /***
     *! 把主屏幕背景设为完全透明
     *! 透明度 0 = 全透，255 = 不透；此处全透可避免遮挡底层画面
     *! 仅对主体部分、默认状态生效，其余状态/部件不受影响
     */
    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_1
    ui->screen_cont_1 = lv_obj_create(ui->screen_main);
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

    //------------------------------------------------------------------------------------------------------------
    // 在这个 ui->screen_cont_1 容器对象内部，创建一个新的按钮对象，并把按钮指针保存到 ui->screen_start_btn 中
    ui->screen_start_btn = lv_btn_create(ui->screen_cont_1);
    // 在这个 ui->screen_start_btn 对象内部，创建一个新的标签对象，并把标签指针保存到 ui->screen_start_btn_label 中
    ui->screen_start_btn_label = lv_label_create(ui->screen_start_btn);
    // 设置标签内容为 "开始"
    lv_label_set_text(ui->screen_start_btn_label, "开始");

    /***
     *! LV_LABEL_LONG_EXPAND : 不处理，直接扩展 label 的宽度（默认）
     *! LV_LABEL_LONG_BREAK  : 自动换行（同 WRAP，旧版本名字）
     *! LV_LABEL_LONG_DOT    : 末尾显示“...”省略号
     *! LV_LABEL_LONG_SCROLL : 文字向左循环滚动（跑马灯）
     *! LV_LABEL_LONG_SCROLL_CIRCULAR : 循环滚动，首尾相接
     *! LV_LABEL_LONG_CLIP   : 超出部分直接裁剪掉，不显示
     */
    // 设置标签（label）在文本内容过长时的 "超长处理模式" 为自动换行（wrap）
    lv_label_set_long_mode(ui->screen_start_btn_label, LV_LABEL_LONG_WRAP);
    // 把标签对象放到父对象的正中间
    lv_obj_align(ui->screen_start_btn_label, LV_ALIGN_CENTER, 0, 0);
    // 设置按钮的内边距为0
    lv_obj_set_style_pad_all(ui->screen_start_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_start_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_start_btn, 120, 248);
    lv_obj_set_size(ui->screen_start_btn, 100, 50);


    //Write style for screen_start_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_start_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_start_btn, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_start_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_start_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_start_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_start_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_start_btn, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_start_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_start_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_start_btn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_start_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_start_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_start_btn, &lv_font_AlimamaShuHeiTi_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_start_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_start_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_title_lab
    ui->screen_main_title_lab = lv_label_create(ui->screen_cont_1);
    lv_label_set_text(ui->screen_main_title_lab, "LVGL");
    lv_label_set_long_mode(ui->screen_main_title_lab, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_main_title_lab, 35, 33);
    lv_obj_set_size(ui->screen_main_title_lab, 175, 60);

    //Write style for screen_main_title_lab, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_main_title_lab, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_title_lab, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_main_title_lab, lv_color_hex(0xc30909), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_main_title_lab, &lv_font_AlimamaShuHeiTi_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_main_title_lab, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_main_title_lab, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_main_title_lab, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_main_title_lab, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_main_title_lab, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_main_title_lab, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_main_title_lab, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_main_title_lab, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_main_title_lab, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_main_title_lab, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    // 立即执行一次布局计算，让 ui->screen_main 上所有控件的位置、大小都按最新设定刷新到正确状态
    lv_obj_update_layout(ui->screen_main);

    // 添加事件
    events_init_screen(ui);

}




void setup_ui(lvgl_ui_t *ui)
{
    setup_scr_screen(ui);
    lv_scr_load(ui->screen_main);
}


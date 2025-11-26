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



void update_progress_bars(lvgl_ui_t *ui, int percentage);
void init_gradient_image(void);
lv_color_t get_gradient_color(int percentage);


// ==================== 全局渐变色条像素缓冲区（只生成一次）=================
#define GRADIENT_HEIGHT 240
static lv_color_t gradient_buf[GRADIENT_HEIGHT * 10];  // 宽10像素就够了（实际显示20px也够）
static lv_img_dsc_t gradient_img_dsc = {
    .header.always_zero = 0,
    .header.w = 10,
    .header.h = GRADIENT_HEIGHT,
    .data_size = sizeof(gradient_buf),
    .header.cf = LV_IMG_CF_TRUE_COLOR,
    .data = (const uint8_t*)gradient_buf,
};



void setup_scr_screen_data(lvgl_ui_t *ui)
{
    // ==================== 创建屏幕 ====================
    ui->screen_data = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_data, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_data, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_opa(ui->screen_data, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ==================== 白色背景容器 ====================
    ui->screen_data_cont_data = lv_obj_create(ui->screen_data);
    lv_obj_set_pos(ui->screen_data_cont_data, 0, 0);
    lv_obj_set_size(ui->screen_data_cont_data, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_data_cont_data, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_opa(ui->screen_data_cont_data, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_data_cont_data, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_data_cont_data, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_data_cont_data, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->screen_data_cont_data, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ==================== 标题 ====================
    ui->screen_data_label_1_model = lv_label_create(ui->screen_data_cont_data);
    lv_label_set_text(ui->screen_data_label_1_model, "心肺复苏操作模型");
    lv_obj_set_pos(ui->screen_data_label_1_model, 40, 12);
    lv_obj_set_size(ui->screen_data_label_1_model, 161, 40);
    lv_obj_set_style_text_color(ui->screen_data_label_1_model, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_data_label_1_model, &lv_font_SourceHanSerifSC_Regular_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_data_label_1_model, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_data_label_1_model, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_data_label_1_model, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ==================== 7 个黑色圆环表盘 ====================
    // 定义一个宏，用于设置圆圈的基本样式
#define SET_CIRCLE_STYLE(obj) \
    /* 1. 设置为圆形 */ \
    lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT); \
    \
    /* 2. 设置白色填充色（与父容器背景色一致） */ \
    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT); \
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT); \
    \
    /* 3. 设置黑色边界（边框） */ \
    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT); /* 边框宽度 */ \
    lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); /* 黑色边界 */ \
    \
    /* 4. 移除阴影 */ \
    lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT)


    ui->screen_data_circle_1 = lv_obj_create(ui->screen_data_cont_data);
    lv_obj_set_pos(ui->screen_data_circle_1, 64, 165);
    lv_obj_set_size(ui->screen_data_circle_1, 25, 25);
    SET_CIRCLE_STYLE(ui->screen_data_circle_1);

    ui->screen_data_circle_2 = lv_obj_create(ui->screen_data_cont_data);
    lv_obj_set_pos(ui->screen_data_circle_2, 150, 164);
    lv_obj_set_size(ui->screen_data_circle_2, 25, 25);
    SET_CIRCLE_STYLE(ui->screen_data_circle_2);

    ui->screen_data_circle_3 = lv_obj_create(ui->screen_data_cont_data);
    lv_obj_set_pos(ui->screen_data_circle_3, 108, 163);
    lv_obj_set_size(ui->screen_data_circle_3, 25, 25);
    SET_CIRCLE_STYLE(ui->screen_data_circle_3);

    ui->screen_data_circle_4 = lv_obj_create(ui->screen_data_cont_data);
    lv_obj_set_pos(ui->screen_data_circle_4, 107, 117);
    lv_obj_set_size(ui->screen_data_circle_4, 25, 25);
    SET_CIRCLE_STYLE(ui->screen_data_circle_4);

    ui->screen_data_circle_5 = lv_obj_create(ui->screen_data_cont_data);
    lv_obj_set_pos(ui->screen_data_circle_5, 108, 208);
    lv_obj_set_size(ui->screen_data_circle_5, 25, 25);
    SET_CIRCLE_STYLE(ui->screen_data_circle_5);

    ui->screen_data_circle_6 = lv_obj_create(ui->screen_data_cont_data);
    lv_obj_set_pos(ui->screen_data_circle_6, 108, 73);
    lv_obj_set_size(ui->screen_data_circle_6, 25, 25);
    SET_CIRCLE_STYLE(ui->screen_data_circle_6);

    ui->screen_data_circle_7 = lv_obj_create(ui->screen_data_cont_data);
    lv_obj_set_pos(ui->screen_data_circle_7, 108, 253);
    lv_obj_set_size(ui->screen_data_circle_7, 25, 25);
    SET_CIRCLE_STYLE(ui->screen_data_circle_7);




    // ==================== 左右两个进度条 ====================
    int bar_width = 20;
    int bar_height = 240;
    int start_y = 60;

    init_gradient_image();

    // --- 左边进度条（从底部向上）---
    ui->screen_data_bar_left_cont = lv_obj_create(ui->screen_data_cont_data);
    lv_obj_set_pos(ui->screen_data_bar_left_cont, 10, start_y);
    lv_obj_set_size(ui->screen_data_bar_left_cont, bar_width, bar_height);
    lv_obj_set_style_border_width(ui->screen_data_bar_left_cont, 1, 0);
    lv_obj_set_style_border_color(ui->screen_data_bar_left_cont, lv_color_hex(0x000000), 0);
    lv_obj_set_style_radius(ui->screen_data_bar_left_cont, 0, 0);
    lv_obj_set_style_bg_opa(ui->screen_data_bar_left_cont, 0, 0);  // 透明背景
    lv_obj_clear_flag(ui->screen_data_bar_left_cont, LV_OBJ_FLAG_SCROLLABLE);

    ui->screen_data_bar_left_img = lv_img_create(ui->screen_data_bar_left_cont);
    lv_img_set_src(ui->screen_data_bar_left_img, &gradient_img_dsc);
    lv_obj_align(ui->screen_data_bar_left_img, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    lv_img_set_zoom(ui->screen_data_bar_left_img, 256 * bar_width / 10);  // 横向拉伸到20px (256=100%)
    // 初始高度为0
    lv_obj_set_height(ui->screen_data_bar_left_img, 0);

    // --- 右边进度条（从顶部向下）---
    ui->screen_data_bar_right_cont = lv_obj_create(ui->screen_data_cont_data);
    lv_obj_set_pos(ui->screen_data_bar_right_cont, 210 - bar_width, start_y);
    lv_obj_set_size(ui->screen_data_bar_right_cont, bar_width, bar_height);
    lv_obj_set_style_border_width(ui->screen_data_bar_right_cont, 1, 0);
    lv_obj_set_style_border_color(ui->screen_data_bar_right_cont, lv_color_hex(0x000000), 0);
    lv_obj_set_style_radius(ui->screen_data_bar_right_cont, 0, 0);
    lv_obj_set_style_bg_opa(ui->screen_data_bar_right_cont, 0, 0);
    lv_obj_clear_flag(ui->screen_data_bar_right_cont, LV_OBJ_FLAG_SCROLLABLE);

    ui->screen_data_bar_right_img = lv_img_create(ui->screen_data_bar_right_cont);
    lv_img_set_src(ui->screen_data_bar_right_img, &gradient_img_dsc);
    lv_obj_align(ui->screen_data_bar_right_img, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_img_set_zoom(ui->screen_data_bar_right_img, 256 * bar_width / 10);
    // 初始高度为满（从顶部开始）
    lv_obj_set_height(ui->screen_data_bar_right_img, bar_height);

    // 初始值示例
    update_progress_bars(ui, 60);
    // ==================== 更新布局 ====================
    lv_obj_update_layout(ui->screen_data);
}




// 只调用一次初始化（建议放在程序启动时调用）
void init_gradient_image(void)
{
    for (int y = 0; y < GRADIENT_HEIGHT; y++) {
        int percentage = (int)((float)y / (GRADIENT_HEIGHT - 1) * 100);  // 0~100
        lv_color_t c = get_gradient_color(percentage);

        // 垂直填充一列（宽10像素）
        for (int x = 0; x < 10; x++) {
            gradient_buf[y * 10 + x] = c;
        }
    }
    // 初始化后这张图片就永远不会变了
}


// 假设这是您的颜色映射函数
lv_color_t get_gradient_color(int percentage)
{
    if (percentage < 0) percentage = 0;
    if (percentage > 100) percentage = 100;

    // 定义关键颜色点 (R, G, B)
    // 浅绿 (0%) - 假设 R:150, G:255, B:150 (柔和绿)
    // 深绿 (50%) - 假设 R:0, G:100, B:0 (深苔绿)
    // 黄色 (75%) - 假设 R:255, G:255, B:0 (纯黄)
    // 红色 (100%) - 假设 R:255, G:0, B:0 (纯红)

    if (percentage <= 50) {
        // 0% (浅绿) -> 50% (深绿)
        float factor = (float)percentage / 50.0f; // 0.0 -> 1.0

        int r = (int)(150 - (150 - 0) * factor);
        int g = (int)(255 - (255 - 100) * factor);
        int b = (int)(150 - (150 - 0) * factor);
        return lv_color_make(r, g, b);
    } else if (percentage <= 75) {
        // 50% (深绿) -> 75% (纯黄)
        float factor = ((float)percentage - 50.0f) / 25.0f; // 0.0 -> 1.0

        int r = (int)(0 + (255 - 0) * factor);
        int g = (int)(100 + (255 - 100) * factor);
        int b = (int)(0 + (0 - 0) * factor); // 保持 B 不变
        return lv_color_make(r, g, b);
    } else { // 75% 到 100%
        // 75% (纯黄) -> 100% (纯红)
        float factor = ((float)percentage - 75.0f) / 25.0f; // 0.0 -> 1.0

        int r = (int)(255 + (255 - 255) * factor); // 保持 R 不变
        int g = (int)(255 - (255 - 0) * factor);
        int b = (int)(0 + (0 - 0) * factor); // 保持 B 不变
        return lv_color_make(r, g, b);
    }
}

// ==================== 新的更新函数（超级简单！）===================
void update_progress_bars(lvgl_ui_t *ui, int percentage)
{
    if (percentage < 0) percentage = 0;
    if (percentage > 100) percentage = 100;

    int height = (int)((float)percentage / 100.0f * 240);

    // 左边：从底部向上增长
    lv_obj_set_height(ui->screen_data_bar_left_img, height);
    lv_obj_align(ui->screen_data_bar_left_img, LV_ALIGN_BOTTOM_LEFT, 0, 0);

    // 右边：从顶部向下减少
    lv_obj_set_height(ui->screen_data_bar_right_img, 240 - height);
    lv_obj_align(ui->screen_data_bar_right_img, LV_ALIGN_TOP_LEFT, 0, 0);

    // 加个平滑动画（可选）
    lv_obj_add_flag(ui->screen_data_bar_left_img, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_add_flag(ui->screen_data_bar_right_img, LV_OBJ_FLAG_ADV_HITTEST);
}

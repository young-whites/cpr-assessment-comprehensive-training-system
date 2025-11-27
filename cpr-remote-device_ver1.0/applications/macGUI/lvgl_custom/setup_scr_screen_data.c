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




#define GRID_COUNT      50      // 一共 50 格（每格代表 2%）
#define GRID_HEIGHT     4       // 每格高度 4px
#define GRID_GAP        2       // 格子间距 2px（总占用高度 = 4+2=6px）
#define GRID_TOTAL_H    (GRID_HEIGHT + GRID_GAP)  // 每格总高度
#define BAR_WIDTH       20





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




    // ==================== 更新布局 ====================
    lv_obj_update_layout(ui->screen_data);
}





// ==================== 创建充电格进度条（替换原来的 bar 部分）================
void create_battery_grid_bar(lv_obj_t *parent, lv_obj_t **grid_cont, int x, int y)
{
    *grid_cont = lv_obj_create(parent);
    lv_obj_set_pos(*grid_cont, x, y);
    lv_obj_set_size(*grid_cont, BAR_WIDTH, GRID_COUNT * GRID_TOTAL_H);
    lv_obj_set_style_bg_opa(*grid_cont, 0, 0);
    lv_obj_set_style_border_width(*grid_cont, 1, 0);
    lv_obj_set_style_border_color(*grid_cont, lv_color_hex(0x000000), 0);
    lv_obj_clear_flag(*grid_cont, LV_OBJ_FLAG_SCROLLABLE);

    for (int i = 0; i < GRID_COUNT; i++) {
        lv_obj_t *cell = lv_obj_create(*grid_cont);
        lv_obj_set_size(cell, BAR_WIDTH - 4, GRID_HEIGHT);           // 左右留2px边距
        lv_obj_set_pos(cell, 2, i * GRID_TOTAL_H + 1);               // 垂直排列 + 间距
        lv_obj_set_style_radius(cell, 2, 0);                         // 小圆角更精致
        lv_obj_set_style_border_width(cell, 0, 0);
        lv_obj_set_style_shadow_width(cell, 0, 0);

        // 默认未充满：浅灰色半透明（空心感）
        lv_obj_set_style_bg_color(cell, lv_color_hex(0xDDDDDD), 0);
        lv_obj_set_style_bg_opa(cell, 100, 0);

        // 给每个格子加个 tag，方便后面批量改色
        lv_obj_set_user_data(cell, (void*)(intptr_t)i);
    }
}


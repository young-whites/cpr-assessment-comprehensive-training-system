/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-30     18452       the first version
 */
#include "lvgl_events.h"




static void screen_main_btn_1_start_event_handler (lv_event_t *e)
{
    LV_LOG_USER("Clicked");
    if (Record.nrf_if_connected) {
            // 已连接，直接切换到控制菜单页面
        ui_load_scr_animation(&guider_lvgl, &guider_lvgl.screen_menu, guider_lvgl.screen_menu_del, &guider_lvgl.screen_main_del, setup_scr_screen_menu, LV_SCR_LOAD_ANIM_NONE, 0, 100, true, true);
        } else {
            // 未连接，隐藏按钮，显示“连接中...”
            lv_obj_add_flag(guider_lvgl.screen_main_btn_1_start, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(guider_lvgl.screen_main_label_2_connect, LV_OBJ_FLAG_HIDDEN);
        }

}






void events_init_screen_main (lvgl_ui_t *ui)
{
    lv_obj_add_event_cb(ui->screen_main_btn_1_start, screen_main_btn_1_start_event_handler, LV_EVENT_CLICKED, ui);
}


//-----------------------------------------------------------------------------------------------------------------------


static void screen_menu_imgbtn_2_competation_event_handler (lv_event_t *e)
{
    LV_LOG_USER("Released");

    ui_load_scr_animation(&guider_lvgl, &guider_lvgl.screen_data, guider_lvgl.screen_data_del, &guider_lvgl.screen_menu_del, setup_scr_screen_data, LV_SCR_LOAD_ANIM_NONE, 0, 100, true, true);
}

static void screen_menu_imgbtn_3_train_event_handler (lv_event_t *e)
{
    LV_LOG_USER("Released");

    ui_load_scr_animation(&guider_lvgl, &guider_lvgl.screen_data, guider_lvgl.screen_data_del, &guider_lvgl.screen_menu_del, setup_scr_screen_data, LV_SCR_LOAD_ANIM_NONE, 0, 100, true, true);
}

static void screen_menu_imgbtn_1_assess_event_handler (lv_event_t *e)
{
    LV_LOG_USER("Released");

    ui_load_scr_animation(&guider_lvgl, &guider_lvgl.screen_data, guider_lvgl.screen_data_del, &guider_lvgl.screen_menu_del, setup_scr_screen_data, LV_SCR_LOAD_ANIM_NONE, 0, 100, true, true);
}


void events_init_screen_menu (lvgl_ui_t *ui)
{
    lv_obj_add_event_cb(ui->screen_menu_imgbtn_2_competation, screen_menu_imgbtn_2_competation_event_handler, LV_EVENT_RELEASED, ui);
    lv_obj_add_event_cb(ui->screen_menu_imgbtn_3_train, screen_menu_imgbtn_3_train_event_handler, LV_EVENT_RELEASED, ui);
    lv_obj_add_event_cb(ui->screen_menu_imgbtn_1_assess, screen_menu_imgbtn_1_assess_event_handler, LV_EVENT_RELEASED, ui);
}





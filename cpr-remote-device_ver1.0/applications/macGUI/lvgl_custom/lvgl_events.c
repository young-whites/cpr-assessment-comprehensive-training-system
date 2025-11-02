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

    lv_obj_add_flag(guider_lvgl.screen_main_btn_1_start, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_lvgl.screen_main_label_2_connect, LV_OBJ_FLAG_HIDDEN);
}



static void screen_label_connect_state_event_handler (lv_event_t *e)
{
    LV_LOG_USER("Clicked");


}




void events_init_screen (lvgl_ui_t *ui)
{
    lv_obj_add_event_cb(ui->screen_main_btn_1_start, screen_main_btn_1_start_event_handler, LV_EVENT_ALL, ui);
}








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




static void screen_start_btn_event_handler (lv_event_t *e)
{
    LV_LOG_USER("Clicked");

    lv_obj_add_flag(guider_lvgl.screen_start_btn, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_lvgl.screen_label_connect_state, LV_OBJ_FLAG_HIDDEN);
}



static void screen_label_connect_state_event_handler (lv_event_t *e)
{
    LV_LOG_USER("Clicked");


}




void events_init_screen (lvgl_ui_t *ui)
{
    lv_obj_add_event_cb(ui->screen_start_btn, screen_start_btn_event_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(ui->screen_label_connect_state, screen_label_connect_state_event_handler, LV_EVENT_CLICKED, ui);
}








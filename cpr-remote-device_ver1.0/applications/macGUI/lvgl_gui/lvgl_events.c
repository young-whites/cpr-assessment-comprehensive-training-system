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

    static uint32_t cnt = 1;
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * label = lv_obj_get_child(btn, 0);
    lv_label_set_text_fmt(label, "%"LV_PRIu32, cnt);
    cnt++;
}



void events_init_screen (lvgl_ui_t *ui)
{
    lv_obj_add_event_cb(ui->screen_start_btn, screen_start_btn_event_handler, LV_EVENT_CLICKED, NULL);
}








/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-30     18452       the first version
 */
#include "bsp_sys.h"




//-----------------------------------------------------------------------------------------------------------------------





static void screen_menu_img_1_assess_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lvgl_ui_t *ui = lv_event_get_user_data(e);

    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(ui, &ui->screen_data, ui->screen_data_del, &ui->screen_menu_del, setup_scr_screen_data, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void screen_menu_img_2_competation_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lvgl_ui_t *ui = lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(ui, &ui->screen_data, ui->screen_data_del, &ui->screen_menu_del, setup_scr_screen_data, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void screen_menu_img_3_train_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lvgl_ui_t *ui = lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(ui, &ui->screen_data, ui->screen_data_del, &ui->screen_menu_del, setup_scr_screen_data, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}


static void screen_menu_img_5_operation_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lvgl_ui_t *ui = lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(ui, &ui->screen_operation, ui->screen_operation_del, &ui->screen_menu_del, setup_scr_screen_operation, LV_SCR_LOAD_ANIM_NONE, 0, 200, true, true);
        break;
    }
    default:
        break;
    }
}

static void screen_menu_img_7_setting_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lvgl_ui_t *ui = lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(ui, &ui->screen_setting, ui->screen_setting_del, &ui->screen_menu_del, setup_scr_screen_setting, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void screen_menu_img_8_printer_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lvgl_ui_t *ui = lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void screen_menu_img_9_switch_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lvgl_ui_t *ui = lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}


void events_init_screen_menu (lvgl_ui_t *ui)
{
    lv_obj_add_event_cb(ui->screen_menu_img_1_assess, screen_menu_img_1_assess_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->screen_menu_img_2_competation, screen_menu_img_2_competation_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->screen_menu_img_3_train, screen_menu_img_3_train_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->screen_menu_img_5_operation, screen_menu_img_5_operation_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->screen_menu_img_7_setting, screen_menu_img_7_setting_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->screen_menu_img_8_printer, screen_menu_img_8_printer_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->screen_menu_img_9_switch, screen_menu_img_9_switch_event_handler, LV_EVENT_CLICKED, ui);

}






//-----------------------------------------------------------------------------------------------------------------------




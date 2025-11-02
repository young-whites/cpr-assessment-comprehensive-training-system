/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-29     18452       the first version
 */
#ifndef APPLICATIONS_MACGUI_LVGL_CUSTOM_SETUP_SCR_SCREEN_H_
#define APPLICATIONS_MACGUI_CUSTOM_SETUP_SCR_SCREEN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "bsp_sys.h"
#include "lvgl.h"

typedef struct
{
    lv_obj_t *screen_main;
    bool screen_main_del;
    lv_obj_t *screen_main_cont_3;
    lv_obj_t *screen_main_cont_2;
    lv_obj_t *screen_main_label_printer;
    lv_obj_t *screen_main_label_assess;
    lv_obj_t *screen_main_img_competation;
    lv_obj_t *screen_main_img_assess;
    lv_obj_t *screen_main_img_printer;
    lv_obj_t *screen_main_label_competation;
    lv_obj_t *screen_main_img_train;
    lv_obj_t *screen_main_label_train;
    lv_obj_t *screen_main_img_score;
    lv_obj_t *screen_main_label_score;
    lv_obj_t *screen_main_label_setting;
    lv_obj_t *screen_main_img_setting;
    lv_obj_t *screen_main_img_operation;
    lv_obj_t *screen_main_img_switch;
    lv_obj_t *screen_main_img_specification;
    lv_obj_t *screen_main_label_operation;
    lv_obj_t *screen_main_label_switch;
    lv_obj_t *screen_main_label_specification;
    lv_obj_t *screen_main_cont_1;
    lv_obj_t *screen_main_btn_1_start;
    lv_obj_t *screen_main_btn_1_start_label;
    lv_obj_t *screen_main_label_1_title;
    lv_obj_t *screen_main_label_2_connect;

}lvgl_ui_t;
extern lvgl_ui_t guider_lvgl;


void lv_user_gui_init(void);
void events_init_screen (lvgl_ui_t *ui);
void setup_scr_screen(lvgl_ui_t *ui);

LV_IMG_DECLARE(_competation_alpha_50x50);
LV_IMG_DECLARE(_assess_alpha_50x50);
LV_IMG_DECLARE(_printer_alpha_50x50);
LV_IMG_DECLARE(_train_alpha_50x50);
LV_IMG_DECLARE(_score_alpha_50x50);
LV_IMG_DECLARE(_setting_alpha_50x50);
LV_IMG_DECLARE(_operation_alpha_50x50);
LV_IMG_DECLARE(_switch_alpha_50x50);
LV_IMG_DECLARE(_specification_alpha_50x50);

LV_FONT_DECLARE(lv_font_AlimamaDongFangDaKai_15)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_AlimamaDongFangDaKai_18)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_AlimamaDongFangDaKai_24)



#ifdef __cplusplus
}
#endif


#endif /* APPLICATIONS_MACGUI_LVGL_CUSTOM_SETUP_SCR_SCREEN_H_ */

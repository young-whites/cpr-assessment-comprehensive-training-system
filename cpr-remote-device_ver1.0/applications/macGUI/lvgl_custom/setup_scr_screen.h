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
    lv_obj_t *screen_main_cont_1;
    lv_obj_t *screen_main_btn_1_start;
    lv_obj_t *screen_main_btn_1_start_label;
    lv_obj_t *screen_main_label_1_title;
    lv_obj_t *screen_main_label_2_connect;
    lv_obj_t *screen_menu;
    bool screen_menu_del;
    lv_obj_t *screen_menu_cont_1;
    lv_obj_t *screen_menu_label_8_pprinter;
    lv_obj_t *screen_menu_label_1_assess;
    lv_obj_t *screen_menu_imgbtn_2_competation;
    lv_obj_t *screen_menu_imgbtn_2_competation_label;
    lv_obj_t *screen_menu_imgbtn_3_train;
    lv_obj_t *screen_menu_imgbtn_3_train_label;
    lv_obj_t *screen_menu_label_2_competation;
    lv_obj_t *screen_menu_label_3_train;
    lv_obj_t *screen_menu_label_4_score;
    lv_obj_t *screen_menu_label_7_settings;
    lv_obj_t *screen_menu_label_5_operation;
    lv_obj_t *screen_menu_label_9_switch;
    lv_obj_t *screen_menu_imgbtn_9_switch;
    lv_obj_t *screen_menu_imgbtn_9_switch_label;
    lv_obj_t *screen_menu_imgbtn_5_opreation;
    lv_obj_t *screen_menu_imgbtn_5_opreation_label;
    lv_obj_t *screen_menu_label_6_instructions;
    lv_obj_t *screen_menu_imgbtn_6_instruction;
    lv_obj_t *screen_menu_imgbtn_6_instruction_label;
    lv_obj_t *screen_menu_imgbtn_7_setting;
    lv_obj_t *screen_menu_imgbtn_7_setting_label;
    lv_obj_t *screen_menu_imgbtn_8_printer;
    lv_obj_t *screen_menu_imgbtn_8_printer_label;
    lv_obj_t *screen_menu_imgbtn_4_score;
    lv_obj_t *screen_menu_imgbtn_4_score_label;
    lv_obj_t *screen_menu_imgbtn_1_assess;
    lv_obj_t *screen_menu_imgbtn_1_assess_label;
    lv_obj_t *screen_data;
    bool screen_data_del;
    lv_obj_t *screen_data_cont_1;
}lvgl_ui_t;
extern lvgl_ui_t guider_lvgl;

typedef void (*ui_setup_scr_t)(lvgl_ui_t * ui);




/* lvgl_gui.c文件 */
void ui_load_scr_animation(lvgl_ui_t *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void init_scr_del_flag(lvgl_ui_t *ui);
void lv_user_gui_init(void);



/* setup_scr_screen.c文件 */
void setup_scr_screen_main(lvgl_ui_t *ui);
void setup_scr_screen_menu(lvgl_ui_t *ui);
void setup_scr_screen_data(lvgl_ui_t *ui);
/* lvgl_events.c文件 */
void events_init_screen_main (lvgl_ui_t *ui);


LV_IMG_DECLARE(_competation_alpha_70x70);
LV_IMG_DECLARE(_competation_pressed_alpha_70x70);
LV_IMG_DECLARE(_train_alpha_70x67);
LV_IMG_DECLARE(_train_pressed_alpha_70x67);
LV_IMG_DECLARE(_switch_alpha_75x75);
LV_IMG_DECLARE(_switch_pressed_alpha_75x75);
LV_IMG_DECLARE(_operation_alpha_70x70);
LV_IMG_DECLARE(_operation_presssed_alpha_70x70);
LV_IMG_DECLARE(_specification_alpha_70x70);
LV_IMG_DECLARE(_specification_pressed_alpha_70x70);
LV_IMG_DECLARE(_setting_alpha_70x70);
LV_IMG_DECLARE(_setting_pressed_alpha_70x70);
LV_IMG_DECLARE(_printer_alpha_70x70);
LV_IMG_DECLARE(_printer_pressed_alpha_70x70);
LV_IMG_DECLARE(_score_alpha_70x70);
LV_IMG_DECLARE(_score_pressed_alpha_70x70);
LV_IMG_DECLARE(_assess_alpha_80x70);
LV_IMG_DECLARE(_assess_pressed_alpha_80x70);

LV_FONT_DECLARE(lv_font_AlimamaDongFangDaKai_18)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_AlimamaDongFangDaKai_24)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_AlimamaDongFangDaKai_15)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_12)



#ifdef __cplusplus
}
#endif


#endif /* APPLICATIONS_MACGUI_LVGL_CUSTOM_SETUP_SCR_SCREEN_H_ */

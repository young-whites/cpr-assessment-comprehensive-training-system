/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-06-29     Administrator       the first version
 */
#include <macGUI/lvgl_gui/lvgl_gui.h>

lvgl_ui_t guider_lvgl;

void lv_user_gui_init(void)
{

#define USE_GUI_GUIDER 1
#if USE_GUI_GUIDER
    extern void setup_ui(lvgl_ui_t *ui);
    setup_ui(&guider_lvgl);
#endif

#if USE_LVGL_EXAMPLES
    draw_basic_button();
#endif
}




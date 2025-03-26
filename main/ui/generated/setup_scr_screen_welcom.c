/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_welcom(lv_ui *ui)
{
    //Write codes screen_welcom
    ui->screen_welcom = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_welcom, 800, 480);
    lv_obj_set_scrollbar_mode(ui->screen_welcom, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_welcom, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_welcom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_welcom_label_1
    ui->screen_welcom_label_1 = lv_label_create(ui->screen_welcom);
    lv_label_set_text(ui->screen_welcom_label_1, "欢迎光临！！！请前往前台办理开房...");
    lv_label_set_long_mode(ui->screen_welcom_label_1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_pos(ui->screen_welcom_label_1, 137, 179);
    lv_obj_set_size(ui->screen_welcom_label_1, 549, 145);

    //Write style for screen_welcom_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_welcom_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_welcom_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_welcom_label_1, lv_color_hex(0x12301e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_welcom_label_1, &lv_font_simsun_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_welcom_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_welcom_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_welcom_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_welcom_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_welcom_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_welcom_label_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_welcom_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_welcom_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_welcom_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_welcom_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_welcom.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_welcom);

}

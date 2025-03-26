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



void setup_scr_screen_serving(lv_ui *ui)
{
    //Write codes screen_serving
    ui->screen_serving = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_serving, 800, 480);
    lv_obj_set_scrollbar_mode(ui->screen_serving, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_serving, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_serving, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serving_msgbox_1
    static const char * screen_serving_msgbox_1_btns[] = {""};
    ui->screen_serving_msgbox_1 = lv_msgbox_create(ui->screen_serving, "提示", "请刷卡", screen_serving_msgbox_1_btns, true);
    lv_obj_set_size(lv_msgbox_get_btns(ui->screen_serving_msgbox_1), 0, 30);
    lv_obj_set_pos(ui->screen_serving_msgbox_1, 122, 98);
    lv_obj_set_size(ui->screen_serving_msgbox_1, 510, 290);

    //Write style for screen_serving_msgbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_serving_msgbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serving_msgbox_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serving_msgbox_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_serving_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serving_msgbox_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serving_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_serving_msgbox_1_extra_title_main_default
    static lv_style_t style_screen_serving_msgbox_1_extra_title_main_default;
    ui_init_style(&style_screen_serving_msgbox_1_extra_title_main_default);

    lv_style_set_text_color(&style_screen_serving_msgbox_1_extra_title_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_screen_serving_msgbox_1_extra_title_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_screen_serving_msgbox_1_extra_title_main_default, 255);
    lv_style_set_text_letter_space(&style_screen_serving_msgbox_1_extra_title_main_default, 0);
    lv_style_set_text_line_space(&style_screen_serving_msgbox_1_extra_title_main_default, 30);
    lv_obj_add_style(lv_msgbox_get_title(ui->screen_serving_msgbox_1), &style_screen_serving_msgbox_1_extra_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_serving_msgbox_1_extra_content_main_default
    static lv_style_t style_screen_serving_msgbox_1_extra_content_main_default;
    ui_init_style(&style_screen_serving_msgbox_1_extra_content_main_default);

    lv_style_set_text_color(&style_screen_serving_msgbox_1_extra_content_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_screen_serving_msgbox_1_extra_content_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_screen_serving_msgbox_1_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_screen_serving_msgbox_1_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_screen_serving_msgbox_1_extra_content_main_default, 10);
    lv_obj_add_style(lv_msgbox_get_text(ui->screen_serving_msgbox_1), &style_screen_serving_msgbox_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_serving_msgbox_1_extra_btns_items_default
    static lv_style_t style_screen_serving_msgbox_1_extra_btns_items_default;
    ui_init_style(&style_screen_serving_msgbox_1_extra_btns_items_default);

    lv_style_set_bg_opa(&style_screen_serving_msgbox_1_extra_btns_items_default, 255);
    lv_style_set_bg_color(&style_screen_serving_msgbox_1_extra_btns_items_default, lv_color_hex(0xe6e6e6));
    lv_style_set_bg_grad_dir(&style_screen_serving_msgbox_1_extra_btns_items_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_serving_msgbox_1_extra_btns_items_default, 0);
    lv_style_set_radius(&style_screen_serving_msgbox_1_extra_btns_items_default, 10);
    lv_style_set_text_color(&style_screen_serving_msgbox_1_extra_btns_items_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_screen_serving_msgbox_1_extra_btns_items_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_screen_serving_msgbox_1_extra_btns_items_default, 255);
    lv_obj_add_style(lv_msgbox_get_btns(ui->screen_serving_msgbox_1), &style_screen_serving_msgbox_1_extra_btns_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes screen_serving_label_2
    ui->screen_serving_label_2 = lv_label_create(ui->screen_serving);
    lv_label_set_text(ui->screen_serving_label_2, "");
    lv_label_set_long_mode(ui->screen_serving_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_serving_label_2, 169, 106);
    lv_obj_set_size(ui->screen_serving_label_2, 150, 64);

    //Write style for screen_serving_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_serving_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serving_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serving_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serving_label_2, &lv_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serving_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_serving_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_serving_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serving_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_serving_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_serving_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_serving_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_serving_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_serving_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serving_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serving_btn_2
    ui->screen_serving_btn_2 = lv_btn_create(ui->screen_serving);
    ui->screen_serving_btn_2_label = lv_label_create(ui->screen_serving_btn_2);
    lv_label_set_text(ui->screen_serving_btn_2_label, "服务");
    lv_label_set_long_mode(ui->screen_serving_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_serving_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_serving_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_serving_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_serving_btn_2, 95, 381);
    lv_obj_set_size(ui->screen_serving_btn_2, 200, 90);

    //Write style for screen_serving_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_serving_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serving_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serving_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_serving_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serving_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serving_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serving_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serving_btn_2, &lv_font_simsun_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serving_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serving_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serving_btn_3
    ui->screen_serving_btn_3 = lv_btn_create(ui->screen_serving);
    ui->screen_serving_btn_3_label = lv_label_create(ui->screen_serving_btn_3);
    lv_label_set_text(ui->screen_serving_btn_3_label, "结算");
    lv_label_set_long_mode(ui->screen_serving_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_serving_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_serving_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_serving_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_serving_btn_3, 453, 386);
    lv_obj_set_size(ui->screen_serving_btn_3, 200, 90);

    //Write style for screen_serving_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_serving_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serving_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serving_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_serving_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serving_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serving_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serving_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serving_btn_3, &lv_font_simsun_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serving_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serving_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serving_label_4
    ui->screen_serving_label_4 = lv_label_create(ui->screen_serving);
    lv_label_set_text(ui->screen_serving_label_4, "123456");
    lv_label_set_long_mode(ui->screen_serving_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_serving_label_4, 111, 302);
    lv_obj_set_size(ui->screen_serving_label_4, 440, 56);

    //Write style for screen_serving_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_serving_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serving_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serving_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serving_label_4, &lv_font_simsun_60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serving_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_serving_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_serving_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serving_label_4, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_serving_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_serving_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_serving_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_serving_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_serving_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serving_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serving_label_3
    ui->screen_serving_label_3 = lv_label_create(ui->screen_serving);
    lv_label_set_text(ui->screen_serving_label_3, "ID:");
    lv_label_set_long_mode(ui->screen_serving_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_serving_label_3, 8, 302);
    lv_obj_set_size(ui->screen_serving_label_3, 96, 56);

    //Write style for screen_serving_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_serving_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serving_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serving_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serving_label_3, &lv_font_simsun_60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serving_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_serving_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_serving_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serving_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_serving_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_serving_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_serving_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_serving_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_serving_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serving_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serving_btn_4
    ui->screen_serving_btn_4 = lv_btn_create(ui->screen_serving);
    ui->screen_serving_btn_4_label = lv_label_create(ui->screen_serving_btn_4);
    lv_label_set_text(ui->screen_serving_btn_4_label, "庄");
    lv_label_set_long_mode(ui->screen_serving_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_serving_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_serving_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_serving_btn_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_serving_btn_4, 30, 10);
    lv_obj_set_size(ui->screen_serving_btn_4, 400, 280);

    //Write style for screen_serving_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_serving_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_serving_btn_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_serving_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_serving_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serving_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serving_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serving_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serving_btn_4, &lv_font_simsun_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serving_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serving_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_serving_label_5
    ui->screen_serving_label_5 = lv_label_create(ui->screen_serving);
    lv_label_set_text(ui->screen_serving_label_5, "120");
    lv_label_set_long_mode(ui->screen_serving_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_serving_label_5, 480, 118);
    lv_obj_set_size(ui->screen_serving_label_5, 300, 80);

    //Write style for screen_serving_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_serving_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_serving_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_serving_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_serving_label_5, &lv_font_simsun_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_serving_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_serving_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_serving_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_serving_label_5, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_serving_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_serving_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_serving_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_serving_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_serving_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_serving_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_serving.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_serving);

    //Init events for screen.
    events_init_screen_serving(ui);
}

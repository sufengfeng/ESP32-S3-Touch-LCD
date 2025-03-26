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



void setup_scr_screen_begin(lv_ui *ui)
{
    //Write codes screen_begin
    ui->screen_begin = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_begin, 800, 480);
    lv_obj_set_scrollbar_mode(ui->screen_begin, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_begin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_begin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_begin_msgbox_1
    static const char * screen_begin_msgbox_1_btns[] = {""};
    ui->screen_begin_msgbox_1 = lv_msgbox_create(ui->screen_begin, "提示", "请刷卡", screen_begin_msgbox_1_btns, true);
    lv_obj_set_size(lv_msgbox_get_btns(ui->screen_begin_msgbox_1), 0, 30);
    lv_obj_set_pos(ui->screen_begin_msgbox_1, 122, 97);
    lv_obj_set_size(ui->screen_begin_msgbox_1, 510, 290);

    //Write style for screen_begin_msgbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_begin_msgbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_begin_msgbox_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_begin_msgbox_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_begin_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_begin_msgbox_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_begin_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_begin_msgbox_1_extra_title_main_default
    static lv_style_t style_screen_begin_msgbox_1_extra_title_main_default;
    ui_init_style(&style_screen_begin_msgbox_1_extra_title_main_default);

    lv_style_set_text_color(&style_screen_begin_msgbox_1_extra_title_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_screen_begin_msgbox_1_extra_title_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_screen_begin_msgbox_1_extra_title_main_default, 255);
    lv_style_set_text_letter_space(&style_screen_begin_msgbox_1_extra_title_main_default, 0);
    lv_style_set_text_line_space(&style_screen_begin_msgbox_1_extra_title_main_default, 30);
    lv_obj_add_style(lv_msgbox_get_title(ui->screen_begin_msgbox_1), &style_screen_begin_msgbox_1_extra_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_begin_msgbox_1_extra_content_main_default
    static lv_style_t style_screen_begin_msgbox_1_extra_content_main_default;
    ui_init_style(&style_screen_begin_msgbox_1_extra_content_main_default);

    lv_style_set_text_color(&style_screen_begin_msgbox_1_extra_content_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_screen_begin_msgbox_1_extra_content_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_screen_begin_msgbox_1_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_screen_begin_msgbox_1_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_screen_begin_msgbox_1_extra_content_main_default, 10);
    lv_obj_add_style(lv_msgbox_get_text(ui->screen_begin_msgbox_1), &style_screen_begin_msgbox_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_begin_msgbox_1_extra_btns_items_default
    static lv_style_t style_screen_begin_msgbox_1_extra_btns_items_default;
    ui_init_style(&style_screen_begin_msgbox_1_extra_btns_items_default);

    lv_style_set_bg_opa(&style_screen_begin_msgbox_1_extra_btns_items_default, 255);
    lv_style_set_bg_color(&style_screen_begin_msgbox_1_extra_btns_items_default, lv_color_hex(0xe6e6e6));
    lv_style_set_bg_grad_dir(&style_screen_begin_msgbox_1_extra_btns_items_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_begin_msgbox_1_extra_btns_items_default, 0);
    lv_style_set_radius(&style_screen_begin_msgbox_1_extra_btns_items_default, 10);
    lv_style_set_text_color(&style_screen_begin_msgbox_1_extra_btns_items_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_screen_begin_msgbox_1_extra_btns_items_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_screen_begin_msgbox_1_extra_btns_items_default, 255);
    lv_obj_add_style(lv_msgbox_get_btns(ui->screen_begin_msgbox_1), &style_screen_begin_msgbox_1_extra_btns_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes screen_begin_btn_zhuang
    ui->screen_begin_btn_zhuang = lv_btn_create(ui->screen_begin);
    ui->screen_begin_btn_zhuang_label = lv_label_create(ui->screen_begin_btn_zhuang);
    lv_label_set_text(ui->screen_begin_btn_zhuang_label, "庄");
    lv_label_set_long_mode(ui->screen_begin_btn_zhuang_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_begin_btn_zhuang_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_begin_btn_zhuang, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_begin_btn_zhuang_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_begin_btn_zhuang, 30, 10);
    lv_obj_set_size(ui->screen_begin_btn_zhuang, 400, 280);

    //Write style for screen_begin_btn_zhuang, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_begin_btn_zhuang, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_begin_btn_zhuang, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_begin_btn_zhuang, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_begin_btn_zhuang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_begin_btn_zhuang, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_begin_btn_zhuang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_begin_btn_zhuang, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_begin_btn_zhuang, &lv_font_simsun_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_begin_btn_zhuang, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_begin_btn_zhuang, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_begin_btn_huanzhuang
    ui->screen_begin_btn_huanzhuang = lv_btn_create(ui->screen_begin);
    ui->screen_begin_btn_huanzhuang_label = lv_label_create(ui->screen_begin_btn_huanzhuang);
    lv_label_set_text(ui->screen_begin_btn_huanzhuang_label, "换庄");
    lv_label_set_long_mode(ui->screen_begin_btn_huanzhuang_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_begin_btn_huanzhuang_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_begin_btn_huanzhuang, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_begin_btn_huanzhuang_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_begin_btn_huanzhuang, 304, 385);
    lv_obj_set_size(ui->screen_begin_btn_huanzhuang, 200, 90);

    //Write style for screen_begin_btn_huanzhuang, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_begin_btn_huanzhuang, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_begin_btn_huanzhuang, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_begin_btn_huanzhuang, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_begin_btn_huanzhuang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_begin_btn_huanzhuang, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_begin_btn_huanzhuang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_begin_btn_huanzhuang, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_begin_btn_huanzhuang, &lv_font_simsun_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_begin_btn_huanzhuang, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_begin_btn_huanzhuang, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_begin_btn_kaiju
    ui->screen_begin_btn_kaiju = lv_btn_create(ui->screen_begin);
    ui->screen_begin_btn_kaiju_label = lv_label_create(ui->screen_begin_btn_kaiju);
    lv_label_set_text(ui->screen_begin_btn_kaiju_label, "准备");
    lv_label_set_long_mode(ui->screen_begin_btn_kaiju_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_begin_btn_kaiju_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_begin_btn_kaiju, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_begin_btn_kaiju_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_begin_btn_kaiju, 580, 385);
    lv_obj_set_size(ui->screen_begin_btn_kaiju, 200, 90);

    //Write style for screen_begin_btn_kaiju, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_begin_btn_kaiju, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_begin_btn_kaiju, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_begin_btn_kaiju, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_begin_btn_kaiju, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_begin_btn_kaiju, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_begin_btn_kaiju, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_begin_btn_kaiju, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_begin_btn_kaiju, &lv_font_simsun_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_begin_btn_kaiju, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_begin_btn_kaiju, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_begin_label_carId
    ui->screen_begin_label_carId = lv_label_create(ui->screen_begin);
    lv_label_set_text(ui->screen_begin_label_carId, "123456");
    lv_label_set_long_mode(ui->screen_begin_label_carId, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_begin_label_carId, 170, 314);
    lv_obj_set_size(ui->screen_begin_label_carId, 304, 56);

    //Write style for screen_begin_label_carId, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_begin_label_carId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_begin_label_carId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_begin_label_carId, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_begin_label_carId, &lv_font_simsun_60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_begin_label_carId, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_begin_label_carId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_begin_label_carId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_begin_label_carId, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_begin_label_carId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_begin_label_carId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_begin_label_carId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_begin_label_carId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_begin_label_carId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_begin_label_carId, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_begin_label_scor
    ui->screen_begin_label_scor = lv_label_create(ui->screen_begin);
    lv_label_set_text(ui->screen_begin_label_scor, "120");
    lv_label_set_long_mode(ui->screen_begin_label_scor, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_begin_label_scor, 480, 118);
    lv_obj_set_size(ui->screen_begin_label_scor, 300, 80);

    //Write style for screen_begin_label_scor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_begin_label_scor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_begin_label_scor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_begin_label_scor, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_begin_label_scor, &lv_font_simsun_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_begin_label_scor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_begin_label_scor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_begin_label_scor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_begin_label_scor, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_begin_label_scor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_begin_label_scor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_begin_label_scor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_begin_label_scor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_begin_label_scor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_begin_label_scor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_begin_label_3
    ui->screen_begin_label_3 = lv_label_create(ui->screen_begin);
    lv_label_set_text(ui->screen_begin_label_3, "ID:");
    lv_label_set_long_mode(ui->screen_begin_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_begin_label_3, 52, 314);
    lv_obj_set_size(ui->screen_begin_label_3, 111, 56);

    //Write style for screen_begin_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_begin_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_begin_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_begin_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_begin_label_3, &lv_font_simsun_60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_begin_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_begin_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_begin_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_begin_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_begin_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_begin_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_begin_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_begin_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_begin_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_begin_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_begin_btn_huanwei
    ui->screen_begin_btn_huanwei = lv_btn_create(ui->screen_begin);
    ui->screen_begin_btn_huanwei_label = lv_label_create(ui->screen_begin_btn_huanwei);
    lv_label_set_text(ui->screen_begin_btn_huanwei_label, "换位");
    lv_label_set_long_mode(ui->screen_begin_btn_huanwei_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_begin_btn_huanwei_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_begin_btn_huanwei, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_begin_btn_huanwei_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_begin_btn_huanwei, 30, 385);
    lv_obj_set_size(ui->screen_begin_btn_huanwei, 200, 90);

    //Write style for screen_begin_btn_huanwei, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_begin_btn_huanwei, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_begin_btn_huanwei, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_begin_btn_huanwei, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_begin_btn_huanwei, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_begin_btn_huanwei, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_begin_btn_huanwei, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_begin_btn_huanwei, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_begin_btn_huanwei, &lv_font_simsun_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_begin_btn_huanwei, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_begin_btn_huanwei, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_begin_btn_1
    ui->screen_begin_btn_1 = lv_btn_create(ui->screen_begin);
    ui->screen_begin_btn_1_label = lv_label_create(ui->screen_begin_btn_1);
    lv_label_set_text(ui->screen_begin_btn_1_label, "准备");
    lv_label_set_long_mode(ui->screen_begin_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_begin_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_begin_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_begin_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_begin_btn_1, 577, 213);
    lv_obj_set_size(ui->screen_begin_btn_1, 200, 90);

    //Write style for screen_begin_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_begin_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_begin_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_begin_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_begin_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_begin_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_begin_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_begin_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_begin_btn_1, &lv_font_simsun_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_begin_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_begin_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_begin.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_begin);

    //Init events for screen.
    events_init_screen_begin(ui);
}

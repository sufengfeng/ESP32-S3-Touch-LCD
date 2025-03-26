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



void setup_scr_screen_sum(lv_ui *ui)
{
    //Write codes screen_sum
    ui->screen_sum = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_sum, 800, 480);
    lv_obj_set_scrollbar_mode(ui->screen_sum, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_sum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_sum_msgbox_1
    static const char * screen_sum_msgbox_1_btns[] = {"确定", ""};
    ui->screen_sum_msgbox_1 = lv_msgbox_create(ui->screen_sum, "提示", "请刷卡", screen_sum_msgbox_1_btns, true);
    lv_obj_set_size(lv_msgbox_get_btns(ui->screen_sum_msgbox_1), 60, 30);
    lv_obj_set_pos(ui->screen_sum_msgbox_1, 122, 98);
    lv_obj_set_size(ui->screen_sum_msgbox_1, 510, 290);

    //Write style for screen_sum_msgbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sum_msgbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sum_msgbox_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sum_msgbox_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sum_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sum_msgbox_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sum_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_sum_msgbox_1_extra_title_main_default
    static lv_style_t style_screen_sum_msgbox_1_extra_title_main_default;
    ui_init_style(&style_screen_sum_msgbox_1_extra_title_main_default);

    lv_style_set_text_color(&style_screen_sum_msgbox_1_extra_title_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_screen_sum_msgbox_1_extra_title_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_screen_sum_msgbox_1_extra_title_main_default, 255);
    lv_style_set_text_letter_space(&style_screen_sum_msgbox_1_extra_title_main_default, 0);
    lv_style_set_text_line_space(&style_screen_sum_msgbox_1_extra_title_main_default, 30);
    lv_obj_add_style(lv_msgbox_get_title(ui->screen_sum_msgbox_1), &style_screen_sum_msgbox_1_extra_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_sum_msgbox_1_extra_content_main_default
    static lv_style_t style_screen_sum_msgbox_1_extra_content_main_default;
    ui_init_style(&style_screen_sum_msgbox_1_extra_content_main_default);

    lv_style_set_text_color(&style_screen_sum_msgbox_1_extra_content_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_screen_sum_msgbox_1_extra_content_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_screen_sum_msgbox_1_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_screen_sum_msgbox_1_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_screen_sum_msgbox_1_extra_content_main_default, 10);
    lv_obj_add_style(lv_msgbox_get_text(ui->screen_sum_msgbox_1), &style_screen_sum_msgbox_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_sum_msgbox_1_extra_btns_items_default
    static lv_style_t style_screen_sum_msgbox_1_extra_btns_items_default;
    ui_init_style(&style_screen_sum_msgbox_1_extra_btns_items_default);

    lv_style_set_bg_opa(&style_screen_sum_msgbox_1_extra_btns_items_default, 255);
    lv_style_set_bg_color(&style_screen_sum_msgbox_1_extra_btns_items_default, lv_color_hex(0xe6e6e6));
    lv_style_set_bg_grad_dir(&style_screen_sum_msgbox_1_extra_btns_items_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_sum_msgbox_1_extra_btns_items_default, 0);
    lv_style_set_radius(&style_screen_sum_msgbox_1_extra_btns_items_default, 10);
    lv_style_set_text_color(&style_screen_sum_msgbox_1_extra_btns_items_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_screen_sum_msgbox_1_extra_btns_items_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_screen_sum_msgbox_1_extra_btns_items_default, 255);
    lv_obj_add_style(lv_msgbox_get_btns(ui->screen_sum_msgbox_1), &style_screen_sum_msgbox_1_extra_btns_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes screen_sum_label_1
    ui->screen_sum_label_1 = lv_label_create(ui->screen_sum);
    lv_label_set_text(ui->screen_sum_label_1, "分数：80\n扣除服务分：40\n余额：30");
    lv_label_set_long_mode(ui->screen_sum_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_sum_label_1, 112, 85);
    lv_obj_set_size(ui->screen_sum_label_1, 341, 153);

    //Write style for screen_sum_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_sum_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sum_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_sum_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_sum_label_1, &lv_font_simsun_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_sum_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_sum_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_sum_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_sum_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_sum_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_sum_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_sum_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_sum_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_sum_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sum_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_sum_label_3
    ui->screen_sum_label_3 = lv_label_create(ui->screen_sum);
    lv_label_set_text(ui->screen_sum_label_3, "123456");
    lv_label_set_long_mode(ui->screen_sum_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_sum_label_3, 111, 302);
    lv_obj_set_size(ui->screen_sum_label_3, 440, 56);

    //Write style for screen_sum_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_sum_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sum_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_sum_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_sum_label_3, &lv_font_simsun_60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_sum_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_sum_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_sum_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_sum_label_3, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_sum_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_sum_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_sum_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_sum_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_sum_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sum_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_sum_label_2
    ui->screen_sum_label_2 = lv_label_create(ui->screen_sum);
    lv_label_set_text(ui->screen_sum_label_2, "ID:");
    lv_label_set_long_mode(ui->screen_sum_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_sum_label_2, 8, 302);
    lv_obj_set_size(ui->screen_sum_label_2, 96, 56);

    //Write style for screen_sum_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_sum_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sum_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_sum_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_sum_label_2, &lv_font_simsun_60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_sum_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_sum_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_sum_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_sum_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_sum_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_sum_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_sum_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_sum_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_sum_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sum_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_sum.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_sum);

    //Init events for screen.
    events_init_screen_sum(ui);
}

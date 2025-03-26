/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_begin_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        lv_obj_add_flag(guider_ui.screen_begin_btn_huanwei, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_begin_btn_huanzhuang, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_begin_msgbox_1, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_begin_btn_kaiju, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(guider_ui.screen_begin_label_carId, "");
        lv_label_set_text(guider_ui.screen_begin_label_scor, "0");
        break;
    }
    default:
        break;
    }
}

void events_init_screen_begin (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_begin, screen_begin_event_handler, LV_EVENT_ALL, ui);
}

static void screen_serving_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        lv_obj_add_flag(guider_ui.screen_serving_msgbox_1, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void screen_serving_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_begin, guider_ui.screen_begin_del, &guider_ui.screen_serving_del, setup_scr_screen_begin, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_serving (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_serving, screen_serving_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_serving_btn_3, screen_serving_btn_3_event_handler, LV_EVENT_ALL, ui);
}

static void screen_upload_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        lv_obj_add_flag(guider_ui.screen_upload_msgbox_1, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_upload (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_upload, screen_upload_event_handler, LV_EVENT_ALL, ui);
}

static void screen_sum_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        lv_obj_add_flag(guider_ui.screen_sum_msgbox_1, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_sum (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_sum, screen_sum_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}

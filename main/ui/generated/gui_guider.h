/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen_welcom;
	bool screen_welcom_del;
	lv_obj_t *screen_welcom_label_1;
	lv_obj_t *screen_welcom_btn_1;
	lv_obj_t *screen_welcom_btn_1_label;
	lv_obj_t *screen_welcom_btn_2;
	lv_obj_t *screen_welcom_btn_2_label;
	lv_obj_t *screen_welcom_label_2;
	lv_obj_t *screen_welcom_btn_3;
	lv_obj_t *screen_welcom_btn_3_label;
	lv_obj_t *screen_welcom_btn_4;
	lv_obj_t *screen_welcom_btn_4_label;
	lv_obj_t *screen_begin;
	bool screen_begin_del;
	lv_obj_t *screen_begin_msgbox_1;
	lv_obj_t *screen_begin_btn_zhuang;
	lv_obj_t *screen_begin_btn_zhuang_label;
	lv_obj_t *screen_begin_btn_huanzhuang;
	lv_obj_t *screen_begin_btn_huanzhuang_label;
	lv_obj_t *screen_begin_btn_kaiju;
	lv_obj_t *screen_begin_btn_kaiju_label;
	lv_obj_t *screen_begin_label_carId;
	lv_obj_t *screen_begin_label_scor;
	lv_obj_t *screen_begin_label_3;
	lv_obj_t *screen_begin_btn_huanwei;
	lv_obj_t *screen_begin_btn_huanwei_label;
	lv_obj_t *screen_begin_btn_1;
	lv_obj_t *screen_begin_btn_1_label;
	lv_obj_t *screen_serving;
	bool screen_serving_del;
	lv_obj_t *screen_serving_msgbox_1;
	lv_obj_t *screen_serving_label_2;
	lv_obj_t *screen_serving_btn_2;
	lv_obj_t *screen_serving_btn_2_label;
	lv_obj_t *screen_serving_btn_3;
	lv_obj_t *screen_serving_btn_3_label;
	lv_obj_t *screen_serving_label_4;
	lv_obj_t *screen_serving_label_3;
	lv_obj_t *screen_serving_btn_4;
	lv_obj_t *screen_serving_btn_4_label;
	lv_obj_t *screen_serving_label_5;
	lv_obj_t *screen_upload;
	bool screen_upload_del;
	lv_obj_t *screen_upload_msgbox_1;
	lv_obj_t *screen_upload_btn_1;
	lv_obj_t *screen_upload_btn_1_label;
	lv_obj_t *screen_upload_btn_2;
	lv_obj_t *screen_upload_btn_2_label;
	lv_obj_t *screen_upload_btn_3;
	lv_obj_t *screen_upload_btn_3_label;
	lv_obj_t *screen_upload_btn_4;
	lv_obj_t *screen_upload_btn_4_label;
	lv_obj_t *screen_upload_label_4;
	lv_obj_t *screen_upload_label_3;
	lv_obj_t *screen_upload_label_5;
	lv_obj_t *screen_sum;
	bool screen_sum_del;
	lv_obj_t *screen_sum_msgbox_1;
	lv_obj_t *screen_sum_label_1;
	lv_obj_t *screen_sum_label_3;
	lv_obj_t *screen_sum_label_2;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen_welcom(lv_ui *ui);
void setup_scr_screen_begin(lv_ui *ui);
void setup_scr_screen_serving(lv_ui *ui);
void setup_scr_screen_upload(lv_ui *ui);
void setup_scr_screen_sum(lv_ui *ui);

LV_FONT_DECLARE(lv_font_simsun_40)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_simsun_12)
LV_FONT_DECLARE(lv_font_simsun_80)
LV_FONT_DECLARE(lv_font_simsun_60)
LV_FONT_DECLARE(lv_font_simsun_48)
LV_FONT_DECLARE(lv_font_simsun_16)


#ifdef __cplusplus
}
#endif
#endif

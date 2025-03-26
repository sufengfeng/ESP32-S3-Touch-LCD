/*
 * Copyright 2023 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "esp_log.h" // Add this line to include the ESP-IDF logging header file

/*********************
 *      DEFINES
 *********************/
#define TAG "sufengcustom"
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
// 定义按钮点击事件处理函数
static void btn_4_click_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    // 获取用户数据
    lv_ui *ui = lv_event_get_user_data(e); 
    if(code == LV_EVENT_CLICKED) {
        // 加载 screen_upload
        ESP_LOGI(TAG, "End of btn_4_click_event_cb...");
        // lv_scr_load_anim(ui->screen_upload, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false);
        // ui_load_scr_animation(ui, &ui->screen_begin, ui->screen_begin_del, &ui->screen_welcom_del, setup_scr_screen_begin, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
    }
}

/**
 * Create a demo application
 */
void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    // 绑定 btn_3 的点击事件处理函数
    lv_obj_add_event_cb(ui->screen_welcom_btn_4, btn_4_click_event_cb, LV_EVENT_CLICKED, NULL);

}


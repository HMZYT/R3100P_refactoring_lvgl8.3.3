#include "../inc/theme_style.h"
#include "../../res/fonts/gui_fonts.h"

static lv_style_t style_label_edit_36px_0;      //36px+灰框+文本
static lv_style_t style_label_normal_36px_0;    //36px+黑+中
static lv_style_t style_label_normal_36px_1;    //36px+黑+右
static lv_style_t style_label_normal_36px_2;    //36px+黑+左
static lv_style_t style_label_normal_36px_3;    //36px+蓝+中
static lv_style_t style_label_normal_36px_4;    //36px+绿+中
static lv_style_t style_label_normal_36px_5;    //36px+红+中
static lv_style_t style_label_normal_32px_0;    //32px+黑+中
static lv_style_t style_label_normal_32px_red;   //32px+红+中
static lv_style_t style_label_normal_20px_0;    //20px+黑+中
static lv_style_t style_label_normal_20px_1;    //20px+黑+右
static lv_style_t style_label_normal_20px_2;    //20px+黑+左
static lv_style_t style_label_normal_20px_green;//20px+绿+中
static lv_style_t style_label_normal_24px_0;    //24px+红+中
static lv_style_t style_label_normal_24px_1;    //24px+黑+中
static lv_style_t style_label_bg_0;             //灰色背景
static lv_style_t style_label_bg_1;             //蓝色背景
static lv_style_t style_label_bg_2;             //绿色背景
static lv_style_t style_line_green;             //绿线

void theme_style_init(void) {
    lv_style_init(&style_label_edit_36px_0);
    lv_style_set_text_color(&style_label_edit_36px_0, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_text_font(&style_label_edit_36px_0, &working_mode_36px);
    lv_style_set_border_width(&style_label_edit_36px_0, 2);
    lv_style_set_border_opa(&style_label_edit_36px_0, LV_OPA_COVER);
    lv_style_set_border_color(&style_label_edit_36px_0, lv_color_make(0x97, 0x97, 0x97));
    lv_style_set_border_side(&style_label_edit_36px_0, LV_BORDER_SIDE_FULL);
    lv_style_set_bg_color(&style_label_edit_36px_0, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_opa(&style_label_edit_36px_0, LV_OPA_COVER);
    lv_style_set_text_align(&style_label_edit_36px_0, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_edit_36px_0,0);
    lv_style_set_pad_all(&style_label_edit_36px_0,0);

    lv_style_init(&style_label_normal_36px_0);
    lv_style_set_text_color(&style_label_normal_36px_0, lv_color_black());
    lv_style_set_text_font(&style_label_normal_36px_0, &working_mode_36px);
    lv_style_set_text_align(&style_label_normal_36px_0, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_normal_36px_0,0);
    lv_style_set_pad_all(&style_label_normal_36px_0,0);

    lv_style_init(&style_label_normal_32px_0);
    lv_style_set_text_color(&style_label_normal_32px_0, lv_color_black());
    lv_style_set_text_font(&style_label_normal_32px_0, &working_mode_32px);
    lv_style_set_text_align(&style_label_normal_32px_0, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_normal_32px_0,0);
    lv_style_set_pad_all(&style_label_normal_32px_0,0);

    lv_style_init(&style_label_normal_32px_red);
    lv_style_set_text_color(&style_label_normal_32px_red, lv_color_make(0xff, 0x00, 0x00));
    lv_style_set_text_font(&style_label_normal_32px_red, &working_mode_32px);
    lv_style_set_text_align(&style_label_normal_32px_red, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_normal_32px_red,0);
    lv_style_set_pad_all(&style_label_normal_32px_red,0);

    lv_style_init(&style_label_normal_20px_1);
    lv_style_set_text_color(&style_label_normal_20px_1, lv_color_black());
    lv_style_set_text_font(&style_label_normal_20px_1, &working_mode_20px);
    lv_style_set_text_align(&style_label_normal_20px_1, LV_TEXT_ALIGN_RIGHT);
    lv_style_set_radius(&style_label_normal_20px_1,0);
    lv_style_set_pad_all(&style_label_normal_20px_1,0);

    lv_style_init(&style_label_normal_36px_1);
    lv_style_set_text_color(&style_label_normal_36px_1, lv_color_black());
    lv_style_set_text_font(&style_label_normal_36px_1, &working_mode_36px);
    lv_style_set_text_align(&style_label_normal_36px_1, LV_TEXT_ALIGN_RIGHT);
    lv_style_set_radius(&style_label_normal_36px_1,0);
    lv_style_set_pad_all(&style_label_normal_36px_1,0);

    lv_style_init(&style_label_normal_20px_0);
    lv_style_set_text_color(&style_label_normal_20px_0, lv_color_black());
    lv_style_set_text_font(&style_label_normal_20px_0, &working_mode_20px);
    lv_style_set_text_align(&style_label_normal_20px_0, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_normal_20px_0,0);
    lv_style_set_pad_all(&style_label_normal_20px_0,0);

    lv_style_init(&style_label_normal_20px_2);
    lv_style_set_text_color(&style_label_normal_20px_2, lv_color_black());
    lv_style_set_text_font(&style_label_normal_20px_2, &working_mode_20px);
    lv_style_set_text_align(&style_label_normal_20px_2, LV_TEXT_ALIGN_LEFT);
    lv_style_set_radius(&style_label_normal_20px_2,0);
    lv_style_set_pad_all(&style_label_normal_20px_2,0);

    lv_style_init(&style_label_normal_20px_green);
    lv_style_set_text_color(&style_label_normal_20px_green, lv_color_make(0x26, 0xAC, 0x0E));
    lv_style_set_text_font(&style_label_normal_20px_green, &working_mode_20px);
    lv_style_set_text_align(&style_label_normal_20px_green, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_normal_20px_green,0);
    lv_style_set_pad_all(&style_label_normal_20px_green,0);

    lv_style_init(&style_label_normal_36px_2);
    lv_style_set_text_color(&style_label_normal_36px_2, lv_color_black());
    lv_style_set_text_font(&style_label_normal_36px_2, &working_mode_36px);
    lv_style_set_text_align(&style_label_normal_36px_2, LV_TEXT_ALIGN_LEFT);
    lv_style_set_radius(&style_label_normal_36px_2,0);
    lv_style_set_pad_all(&style_label_normal_36px_2,0);

    lv_style_init(&style_label_normal_36px_3);
    lv_style_set_text_color(&style_label_normal_36px_3, lv_color_make(0x00, 0x00, 0xff));
    lv_style_set_text_font(&style_label_normal_36px_3, &working_mode_36px);
    lv_style_set_text_align(&style_label_normal_36px_3, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_normal_36px_3,0);
    lv_style_set_pad_all(&style_label_normal_36px_3,0);

    lv_style_init(&style_label_normal_36px_4);
    lv_style_set_text_color(&style_label_normal_36px_4, lv_color_make(0x04, 0x9F, 0x00));
    lv_style_set_text_font(&style_label_normal_36px_4, &working_mode_36px);
    lv_style_set_text_align(&style_label_normal_36px_4, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_normal_36px_4,0);
    lv_style_set_pad_all(&style_label_normal_36px_4,0);

    lv_style_init(&style_label_normal_24px_0);
    lv_style_set_text_color(&style_label_normal_24px_0, lv_color_make(0xff, 0x00, 0x00));
    lv_style_set_text_font(&style_label_normal_24px_0, &working_mode_24px);
    lv_style_set_text_align(&style_label_normal_24px_0, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_normal_24px_0,0);
    lv_style_set_pad_all(&style_label_normal_24px_0,0);

    lv_style_init(&style_label_normal_24px_1);
    lv_style_set_text_color(&style_label_normal_24px_1, lv_color_black());
    lv_style_set_text_font(&style_label_normal_24px_1, &working_mode_24px);
    lv_style_set_text_align(&style_label_normal_24px_1, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_normal_24px_1,0);
    lv_style_set_pad_all(&style_label_normal_24px_1,0);

    lv_style_init(&style_label_normal_36px_5);
    lv_style_set_text_color(&style_label_normal_36px_5, lv_color_make(0xff, 0x00, 0x00));
    lv_style_set_text_font(&style_label_normal_36px_5, &working_mode_36px);
    lv_style_set_text_align(&style_label_normal_36px_5, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(&style_label_normal_36px_5,0);
    lv_style_set_pad_all(&style_label_normal_36px_5,0);

    lv_style_init(&style_label_bg_0);
    lv_style_set_bg_color(&style_label_bg_0, lv_color_make(0xde, 0xde, 0xde));
    lv_style_set_bg_opa(&style_label_bg_0, LV_OPA_COVER);
    lv_style_set_radius(&style_label_bg_0,0);
    lv_style_set_pad_all(&style_label_bg_0,0);

    lv_style_init(&style_label_bg_1);
    lv_style_set_border_width(&style_label_bg_1, 0);
    lv_style_set_bg_color(&style_label_bg_1, lv_color_make(0x00, 0x00, 0xff));
    lv_style_set_bg_opa(&style_label_bg_1, LV_OPA_COVER);
    lv_style_set_radius(&style_label_bg_1,0);
    lv_style_set_pad_all(&style_label_bg_1,0);

    lv_style_init(&style_label_bg_2);
    lv_style_set_border_width(&style_label_bg_2, 0);
    lv_style_set_bg_color(&style_label_bg_2, lv_color_make(0x04, 0x9F, 0x00));
    lv_style_set_bg_opa(&style_label_bg_2, LV_OPA_COVER);
    lv_style_set_radius(&style_label_bg_2,0);
    lv_style_set_pad_all(&style_label_bg_2,0);

#pragma region line
    lv_style_init(&style_line_green);
    lv_style_set_line_width(&style_line_green,1);
    lv_style_set_line_color(&style_line_green, lv_color_make(0x69, 0xA5, 0x59));
#pragma endregion line
}

#pragma region 20px
lv_style_t *theme_style_get_label_normal_20px_0() {
    return &style_label_normal_20px_0;
}

lv_style_t *theme_style_get_label_normal_20px_1() {
    return &style_label_normal_20px_1;
}

lv_style_t *theme_style_get_label_normal_20px_2() {
    return &style_label_normal_20px_2;
}

lv_style_t *theme_style_get_label_normal_20px_green() {
    return &style_label_normal_20px_green;
}
#pragma endregion 20px

#pragma region 24px
lv_style_t *theme_style_get_label_normal_24px_0() {
    return &style_label_normal_24px_0;
}

lv_style_t *theme_style_get_label_normal_24px_1() {
    return &style_label_normal_24px_1;
}
#pragma region 24px

#pragma region 32px
lv_style_t *theme_style_get_label_normal_32px_0() {
    return &style_label_normal_32px_0;
}

lv_style_t *theme_style_get_label_normal_32px_red() {
    return &style_label_normal_32px_red;
}
#pragma region 32px

#pragma region 36px
lv_style_t *theme_style_get_label_edit_36px_0() {
    return &style_label_edit_36px_0;
}

lv_style_t *theme_style_get_label_normal_36px_0() {
    return &style_label_normal_36px_0;
}

lv_style_t *theme_style_get_label_normal_36px_1() {
    return &style_label_normal_36px_1;
}

lv_style_t *theme_style_get_label_normal_36px_2() {
    return &style_label_normal_36px_2;
}

lv_style_t *theme_style_get_label_normal_36px_3() {
    return &style_label_normal_36px_3;
}

lv_style_t *theme_style_get_label_normal_36px_4() {
    return &style_label_normal_36px_4;
}

lv_style_t *theme_style_get_label_normal_36px_5() {
    return &style_label_normal_36px_5;
}
#pragma region 36px

lv_style_t *theme_style_get_bg_0() {
    return &style_label_bg_0;
}

lv_style_t *theme_style_get_bg_1() {
    return &style_label_bg_1;
}

lv_style_t *theme_style_get_bg_2() {
    return &style_label_bg_2;
}

lv_style_t *theme_style_get_line_green() {
    return &style_line_green;
}
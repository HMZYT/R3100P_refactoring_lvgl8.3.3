#include "../inc/theme_R1100P_white.h"
#include "lvgl/lvgl.h"
#include "../../res/fonts/gui_fonts.h"

#define COLOR_WHITE                 lv_color_white()
#define COLOR_BLACK                 lv_color_black()

static lv_style_t style_bg;
static lv_style_t style_bar_main;
static lv_style_t style_bar_indicator;
static lv_style_t style_label;

static void theme_apply(lv_theme_t *th, lv_obj_t *obj) {
    LV_UNUSED(th);

    if (lv_obj_check_type(obj, &lv_obj_class)) {
        lv_obj_add_style(obj, &style_bg, 0);
    }
    else if (lv_obj_check_type(obj, &lv_label_class)) {
        lv_obj_add_style(obj, &style_label, 0);
    }
    else if (lv_obj_check_type(obj, &lv_bar_class)) {
        lv_obj_add_style(obj, &style_bar_main, LV_PART_MAIN);
        lv_obj_add_style(obj, &style_bar_indicator, LV_PART_INDICATOR);
    }
}


static void theme_init(void) {
#pragma region style_bg
    lv_style_init(&style_bg);
    lv_style_set_bg_color(&style_bg, COLOR_WHITE);
    lv_style_set_bg_opa(&style_bg, LV_OPA_COVER);
    lv_style_set_border_width(&style_bg, 2);
    lv_style_set_border_color(&style_bg,  lv_color_make(0xde, 0xde, 0xde));
    lv_style_set_radius(&style_bg,0);
    lv_style_set_pad_all(&style_bg,0);
#pragma endregion style_bg

#pragma region style_label
    lv_style_init(&style_label);
    lv_style_set_text_color(&style_label, lv_color_black());
    lv_style_set_bg_opa(&style_label, LV_OPA_TRANSP);
    lv_style_set_text_font(&style_label, &working_mode_24px);
    lv_style_set_text_align(&style_label, LV_TEXT_ALIGN_CENTER );
#pragma endregion style_label

#pragma region style_bar_main
    lv_style_init(&style_bar_main);
    lv_style_set_bg_color(&style_bar_main, lv_color_hex(0xd0d0d0));
    lv_style_set_bg_opa(&style_bar_main, LV_OPA_100);
#pragma endregion style_bar_main

#pragma region style_bar_indicator
    lv_style_init(&style_bar_indicator);
    lv_style_set_bg_color(&style_bar_indicator, lv_color_hex(0x171717));
    lv_style_set_bg_opa(&style_bar_indicator, LV_OPA_100);
#pragma endregion style_bar_indicator
}

static void theme_set(void) {
    lv_theme_t *th_act = lv_disp_get_theme(NULL);
    if (th_act == NULL) {
        th_act = lv_theme_basic_init(NULL);
    }

    static lv_theme_t th_new;
    th_new = *th_act;

    lv_theme_set_parent(&th_new, th_act);
    lv_theme_set_apply_cb(&th_new, theme_apply);

    lv_disp_set_theme(NULL, &th_new);
}


void theme_R1100P_white_init(void) {
    theme_init();
    theme_set();
}




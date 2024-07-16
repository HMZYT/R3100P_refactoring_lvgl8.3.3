#include "../inc/rc_lcd_working_widget.h"
#include "../inc/working_header.h"
#include "../inc/working_footer.h"
#include "../../theme/inc/theme_style.h"
#include "../../theme/inc/theme_R1100P_white.h"

lv_obj_t* working_widget_init()
{
    //主题初始化
    theme_R1100P_white_init();
    theme_style_init();
    //主窗口
    lv_obj_t *widget = lv_obj_create(lv_scr_act());

    uint16_t parent_width, parent_height;
    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);
    static lv_style_t main_style;
    static lv_style_t main_style1;

    lv_style_init(&main_style);
    lv_style_set_bg_color(&main_style, lv_color_make(255, 255, 255));
    lv_style_set_bg_opa(&main_style, LV_OPA_COVER);
    lv_style_set_radius(&main_style,0);
    lv_style_set_pad_all(&main_style,0);

    lv_obj_set_size(widget, parent_width, parent_height);
    lv_obj_set_pos(widget, 0, 0);
    //lv_obj_add_style(widget ,&main_style, 0);
    lv_obj_clear_flag(widget, LV_OBJ_FLAG_SCROLLABLE);

    //页头
    irc_lcd_header_t *header = working_header_create(widget);

    //页尾
    irc_lcd_footer_t *footer = working_footer_create(widget);

    return widget;
}
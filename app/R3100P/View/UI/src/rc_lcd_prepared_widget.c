#include "../inc/rc_lcd_prepared_widget.h"
#include <stdlib.h>
#include <string.h>
#include "../inc/prepared_header.h"
#include "../inc/prepared_footer.h"

lv_obj_t* prepared_widget_init()
{
    lv_obj_t *widget = lv_obj_create(lv_scr_act());
    uint16_t parent_width, parent_height;
    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    static lv_style_t main_style;

    lv_style_init(&main_style);
    lv_style_set_bg_color(&main_style, lv_color_make(17, 17, 17));
    lv_style_set_bg_opa(&main_style, LV_OPA_COVER);

    lv_obj_set_size(widget, parent_width, parent_height);
    lv_obj_set_pos(widget, 0, 0);
    lv_obj_add_style(widget, &main_style, 0);
    lv_obj_clear_flag(widget, LV_OBJ_FLAG_SCROLLABLE);

    //页头
    irc_lcd_header_t *header = prepared_header_create(widget);

    //页尾
    irc_lcd_footer_t *footer = prepared_footer_create(widget);

    return widget;
}

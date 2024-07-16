#include "../inc/irc_lcd_header.h"
#include <stdlib.h>
//#include "../GUI_APP/gui_user.h"
#include "../../../Model/inc/data_info_v4_0.h"
#include "../../User/inc/images_v4_0.h"
#include "../res/fonts/gui_fonts.h"

void irc_lcd_header_init( irc_lcd_header_t *h, lv_obj_t *parent )
{
    if (!h)
    {
        return ;
    }
    uint16_t parent_width, parent_height;

    // parent_width = lv_obj_get_width(parent);
    // parent_height = lv_obj_get_height(parent);

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    static lv_style_t header_style;
    lv_style_init(&header_style);
    lv_style_set_bg_color(&header_style, lv_color_make(0xf5, 0xf5, 0xf5));
    lv_style_set_bg_opa(&header_style, LV_OPA_COVER);
    lv_style_set_radius(&header_style,0);
    lv_style_set_pad_all(&header_style,0);

    static lv_style_t title_style;
    lv_style_init(&title_style);
    lv_style_set_bg_opa(&title_style, LV_OPA_TRANSP);
    lv_style_set_text_color(&title_style, lv_color_black());
    lv_style_set_text_font(&title_style, &working_mode_28px);
    lv_style_set_text_align(&title_style, LV_TEXT_ALIGN_CENTER);

    //创建基层
    h->obj = lv_obj_create(parent);
    lv_obj_add_style(h->obj, &header_style, 0);
    lv_obj_set_size(h->obj, parent_width, 60);
    lv_obj_set_pos(h->obj, 0, 0);
    lv_obj_clear_flag(h->obj, LV_OBJ_FLAG_SCROLLABLE);

    //logo
    h->bg = lv_img_create(h->obj);
    lv_img_set_src(h->bg, &zoomlion);
    lv_obj_set_pos(h->bg, 0, 0);

    //创建Title
    h->title = lv_label_create(h->obj);
    lv_label_set_text(h->title, "未归零");
    lv_obj_add_style(h->title, &title_style, 0);
    lv_obj_set_pos(h->title, 596, 9);
}

void irc_lcd_header_refresh( irc_lcd_header_t* h, void *data )
{
    if ( h && h->refresh)
    {
        h->refresh( h, data );
    }
    
}
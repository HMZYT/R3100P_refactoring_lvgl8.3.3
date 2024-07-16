#include "../inc/irc_lcd_footer.h"
#include "../res/fonts/gui_fonts.h"

extern void irc_lcd_footer_refresh(irc_lcd_footer_t *h, void *data);

#include <stdlib.h>

void irc_lcd_footer_init(irc_lcd_footer_t *footer, lv_obj_t *parent)
{

    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    // lv_obj_get_self_width

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_radius(&style,0);
    lv_style_set_pad_all(&style,0);
    // lv_style_set_bg_color(&style, lv_color_white());

    static lv_style_t title_style;
    lv_style_init(&title_style);
    lv_style_set_bg_opa(&title_style, LV_OPA_TRANSP);
    lv_style_set_text_color(&title_style, lv_color_black());
    //lv_style_set_text_font(&title_style, &working_mode_24px);

    footer->obj = lv_obj_create(parent);
    lv_obj_add_style(footer->obj, &style, 0);
    lv_obj_set_size(footer->obj, parent_width, 60);
    lv_obj_set_pos(footer->obj, 0, parent_height - 60);
    lv_obj_clear_flag(footer->obj, LV_OBJ_FLAG_SCROLLABLE);
		
		//Title
    footer->title = lv_label_create(footer->obj);
    lv_label_set_text(footer->title, "");
    lv_obj_add_style(footer->title, &title_style, 0);
    lv_obj_set_pos(footer->title, 359, 8);
}

void irc_lcd_footer_refresh(irc_lcd_footer_t *h, void *data)
{
    if (h && h->refresh)
    {
        h->refresh(h, data);
    }
}

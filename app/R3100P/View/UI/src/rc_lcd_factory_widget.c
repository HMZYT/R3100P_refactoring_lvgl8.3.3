#include "../inc/rc_lcd_factory_widget.h"
#include <stdlib.h>
#include <string.h>
#include "lvgl.h"
#include "../inc/fact_page_align.h"
#include "../inc/fact_page_full_color.h"
#include "../inc/fact_page_touch.h"
#include "../inc/fact_page_version.h"
#include "../inc/fact_page_align_displacement.h"

lv_obj_t* rc_lcd_factory_widget_init()
{
    //主窗口
    lv_obj_t *widget = lv_obj_create(lv_scr_act());

    uint16_t parent_width, parent_height;
    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    static lv_style_t main_style;
    lv_style_init(&main_style);
    lv_style_set_bg_color(&main_style, lv_color_make(17, 17, 17));
    lv_style_set_bg_opa(&main_style, LV_OPA_COVER);
    lv_style_set_radius(&main_style,0);
    lv_style_set_pad_all(&main_style,0);

    lv_obj_set_size(widget, parent_width, parent_height);
    lv_obj_set_pos(widget, 0, 0);
    lv_obj_add_style(widget, &main_style, 0);
    lv_obj_clear_flag(widget, LV_OBJ_FLAG_SCROLLABLE);
}

//bool gui_ctrl_backlight = true;
//
//static void _refresh(irc_lcd_widget_t *w, uint8_t dtype, void *data)
//{
//    // 1. 转换数据
//  rc_lcd_fact_input_data_t *indata = (rc_lcd_fact_input_data_t *)data;
//  if (indata->mode >= 4)
//  {
//    return;
//  }
//
//  if ( indata->backlight )
//  {//打开背光
//    gui_ctrl_backlight = true;
//  }
//  else{//关闭背光
//    gui_ctrl_backlight = false;
//  }
//
//	//如果当前没有显示某个页面，就不再刷新了
//	if( w->cur_page_idx== indata->page_idx )
//  {
//    irc_lcd_page_refresh(w->cur_page, &indata->data);
//  }
//}


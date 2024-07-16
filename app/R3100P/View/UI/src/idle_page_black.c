#include "../inc/idle_page_black.h"
#include <stdlib.h>

lv_obj_t* idle_page_black_init(lv_obj_t *page)
{
    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_make(17, 17, 17));
    lv_style_set_bg_opa(&bg_style, LV_OPA_COVER);
    lv_style_set_radius(&bg_style,0);
    lv_style_set_pad_all(&bg_style,0);
    lv_style_set_border_opa(&bg_style, 0);

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height - 40 - 40);
    lv_obj_set_pos(obj, 0, 41);
    lv_obj_add_style(obj, &bg_style, 0);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

#if 0 // for testing
    static lv_style_t style_test;
    lv_style_init(&style_test);
    lv_style_set_text_color(&style_test, lv_color_white());

    lv_obj_t *test_label = lv_label_create( obj );
    lv_label_set_text( test_label, "RC-BLACK-qqqqqqqqqqqqqqqqqqqqqqqqqqq" );
    lv_obj_set_pos( test_label, 0, 0 );
    lv_obj_add_style( test_label, &style_test, 0 );
#endif
    return  obj;
}

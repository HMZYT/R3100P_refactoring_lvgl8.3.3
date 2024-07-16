#include "../inc/fact_page_touch.h"
#include "../inc/working_page_home.h"

static lv_style_t style_line;

static void _touch( lv_event_t *e )
{
    static uint8_t cur_idx = 0;
    fact_page_touch_t *page = lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    static lv_point_t last_pnts;
    if ( code == LV_EVENT_PRESSED )
    {
        page->pnts[ page->cur_line ] = lv_mem_alloc( sizeof( lv_point_t ) * 128 );
        lv_indev_get_point(lv_event_get_indev(e), page->pnts[ page->cur_line ]);
        cur_idx = 1;
        if ( page->cur_line > FACT_PAGE_TOUCH_MAX_LINES )
        {
            return;
        }
        //创建一个Line
        page->lines[ page->cur_line ] = lv_line_create( page->parent);
        lv_obj_add_style( page->lines[ page->cur_line ], &style_line, 0 );
        lv_line_set_points( page->lines[ page->cur_line ], (lv_point_t *)page->pnts[ page->cur_line ], 1 );
        
    }
    else if ( code == LV_EVENT_RELEASED)
    {        
        last_pnts.x = 0;
        last_pnts.y = 0;
        
        //一条线画完
        lv_point_t *ps = page->pnts[ page->cur_line ];
        if (ps)
        {
            if ( cur_idx >= 128 )
            {
                return;
            }
            lv_indev_get_point(lv_event_get_indev(e), &ps[cur_idx]);
            cur_idx++;
            lv_line_set_points( page->lines[ page->cur_line ], (lv_point_t*)ps, cur_idx );
        }
        page->cur_line = ( page->cur_line + 1 ) % FACT_PAGE_TOUCH_MAX_LINES;        
    }
    else if ( code == LV_EVENT_PRESSING )
    {
        //给当前line增加点
        lv_point_t *ps = page->pnts[ page->cur_line ];
        if (ps)
        {
            if ( cur_idx >= 128 )
            {
                return;
            }
            lv_indev_get_point(lv_event_get_indev(e), &ps[cur_idx]);
            if ( ps[ cur_idx ].x == last_pnts.x && ps[ cur_idx ].y == last_pnts.y )
            {

            }
            else{
                cur_idx++;
                lv_line_set_points( page->lines[ page->cur_line ], (lv_point_t *)ps, cur_idx );
            }
            last_pnts.x = ps[ cur_idx ].x;
            last_pnts.y = ps[ cur_idx ].y;            
        }
    }
#if 0
    else if ( code == LV_EVENT_CLICKED )
    {
        //清屏
        for ( int i = 0; i < FACT_PAGE_TOUCH_MAX_LINES; ++i )
        {
            if ( page->lines[ i ] )
            {                
                lv_obj_del( page->lines[ i ] );
                page->lines[ i ] = NULL;
                lv_point_t *ps = page->pnts[ i ];
                if ( ps )
                {
                    lv_free( ps );
                }
            }
        }
    }
#endif
}
//extern lv_group_t *default_group;
lv_obj_t* fact_page_touch_init(lv_obj_t *page)
{
    fact_page_touch_t *p = lv_mem_alloc(sizeof (fact_page_touch_t));
    p->parent = page;
    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 4);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_line_rounded(&style_line, true);

    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_make(17, 17, 17));
    lv_style_set_bg_opa(&bg_style, LV_OPA_COVER);
    lv_style_set_text_color(&bg_style, lv_color_white());
    lv_style_set_text_font( &bg_style, &working_mode_28px );

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height);
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_add_style(obj, &bg_style, 0);

    //lv_group_add_obj( default_group, obj );
    lv_obj_add_event_cb(obj, _touch, LV_EVENT_PRESSED, page );
    lv_obj_add_event_cb(obj, _touch, LV_EVENT_PRESSING, page );
    lv_obj_add_event_cb(obj, _touch, LV_EVENT_RELEASED, page );
    lv_obj_add_event_cb(obj, _touch, LV_EVENT_CLICKED, page );
    
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    p->tips = lv_label_create( obj );
    lv_label_set_text( p->tips, "触屏检测" );
    lv_obj_add_style( p->tips, &bg_style, 0 );
    lv_obj_center( p->tips );
    

#if 0 // for testing

    static lv_style_t style_test;
    lv_style_init(&style_test);
    lv_style_set_text_color(&style_test, lv_color_white());

    lv_obj_t *test_label = lv_label_create(obj);
    lv_label_set_text(test_label, "FACT-TOUCH");
    lv_obj_set_pos(test_label, 0, 0);
    lv_obj_add_style(test_label, &style_test, 0);
#endif
    return obj;
}

extern bool key_factory;
//static void _show(irc_lcd_page_t *ipage, bool v)
//{
//    if (!key_factory)
//    {//命令进入的工厂模式
//        return;
//    }
//    fact_page_touch_t *page = (fact_page_touch_t *)ipage;
//    if( v )
//    {
//        //删除所有线和点
//        for ( int i = 0; i < FACT_PAGE_TOUCH_MAX_LINES; ++i )
//        {
//            if ( page->lines[ i ] )
//            {
//                lv_obj_del( page->lines[ i ] );
//                page->lines[ i ] = NULL;
//                lv_point_t *ps = page->pnts[ i ];
//                if ( ps )
//                {
//                    lv_free( ps );
//                }
//            }
//        }
//    }
//}

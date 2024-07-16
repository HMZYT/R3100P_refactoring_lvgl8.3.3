#include "../inc/fact_page_version.h"
#include "../inc/working_page_home.h"

static void _set_rf_version(lv_obj_t *label, uint32_t vv) //信道设置
{
    uint8_t temp[4];

    char name0[10];
    char name1[10];
    char name2[10];
    char name3[10];
    char name[20];
    strcpy(name, "");
    int i;
    for (i = 0; i < 4; i++)
    {
        temp[i] = (vv >> (4*2*(3-i))) % 32 ;
    }
    sprintf(name0,"%x",temp[0]);
    sprintf(name1,"%x",temp[1]);
    sprintf(name2,"%x",temp[2]);
    sprintf(name3,"%x",temp[3]);
    strcat(name, "v");
    strcat(name, name0);
    strcat(name, ".");
    strcat(name, name1);
    strcat(name, ".");
    strcat(name, name2);
    strcat(name, ".");
    strcat(name, name3);

    lv_label_set_text(label, name);
}

static void _set_rf_address(lv_obj_t *label, uint32_t vv) //信道设置
{
    char name[20];
    strcpy(name, "");
    sprintf(name,"%x",vv);
    lv_label_set_text(label, name);
}

lv_obj_t* fact_page_version_init(lv_obj_t *page)
{
    fact_page_version_t *p = lv_mem_alloc(sizeof (fact_page_version_t));
    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_make(17, 17, 17));
    lv_style_set_bg_opa(&bg_style, LV_OPA_COVER);
    lv_style_set_text_color(&bg_style, lv_color_white());


    static lv_style_t style_font;
    lv_style_init(&style_font);
    lv_style_set_text_color(&style_font, lv_color_white());
    lv_style_set_text_font( &style_font, &working_mode_28px);

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height - 40 - 40);
    lv_obj_set_pos(obj, 0, 41);
    lv_obj_add_style(obj, &bg_style, 0);

#if 0 // for testing

    static lv_style_t style_test;
    lv_style_init(&style_test);
    lv_style_set_text_color(&style_test, lv_color_white());

    lv_obj_t *test_label = lv_label_create(obj);
    lv_label_set_text(test_label, "FACT-VERSION");
    lv_obj_set_pos(test_label, 0, 0);
    lv_obj_add_style(test_label, &style_test, 0);
#endif

    lv_obj_t *title_lcd_boot_version = lv_label_create( obj );
    lv_label_set_text( title_lcd_boot_version, "LCD-BOOT固件版本号:" );
    lv_obj_add_style( title_lcd_boot_version, &style_font, 0 );
    
    lv_obj_t *title_lcd_version = lv_label_create( obj );
    lv_label_set_text( title_lcd_version, "LCD-APP固件版本号:" );
    lv_obj_add_style( title_lcd_version, &style_font, 0 );

    lv_obj_t *title_t_boot_version = lv_label_create( obj );
    lv_label_set_text( title_t_boot_version, "发射机BOOT固件版本号:" );
    lv_obj_add_style( title_t_boot_version, &style_font, 0 );

    lv_obj_t *title_t_update_version = lv_label_create( obj );
    lv_label_set_text( title_t_update_version, "发射机UPDATE固件版本号:" );
    lv_obj_add_style( title_t_update_version, &style_font, 0 );


    lv_obj_t *title_t_app_version = lv_label_create( obj );
    lv_label_set_text( title_t_app_version, "发射机APP固件版本号:" );
    lv_obj_add_style( title_t_app_version, &style_font, 0 );

    lv_obj_t *title_t_back_mcu_version = lv_label_create( obj );
    lv_label_set_text( title_t_back_mcu_version, "发射机备用MCU固件版本号:" );
    lv_obj_add_style( title_t_back_mcu_version, &style_font, 0 );

    lv_obj_t *title_rf_version = lv_label_create( obj );
    lv_label_set_text( title_rf_version, "射频固件版本号:" );
    lv_obj_add_style( title_rf_version, &style_font, 0 );
    
    lv_obj_t *title_dev_addr = lv_label_create( obj );
    lv_label_set_text( title_dev_addr, "设备地址:" );
    lv_obj_add_style( title_dev_addr, &style_font, 0 );


    p->content_lcd_boot_version = lv_label_create( obj );
    lv_obj_add_style( p->content_lcd_boot_version, &style_font, 0 );

    p->content_lcd_version = lv_label_create( obj );
    lv_obj_add_style( p->content_lcd_version, &style_font, 0 );

    p->content_t_boot_version = lv_label_create( obj );
    lv_obj_add_style( p->content_t_boot_version, &style_font, 0 );

    p->content_t_update_version = lv_label_create( obj );
    lv_obj_add_style( p->content_t_update_version, &style_font, 0 );


    p->content_t_app_version = lv_label_create( obj );
    lv_obj_add_style( p->content_t_app_version, &style_font, 0 );

    p->content_t_back_mcu_version = lv_label_create( obj );
    lv_obj_add_style( p->content_t_back_mcu_version, &style_font, 0 );

    p->content_rf_version = lv_label_create( obj );
    lv_obj_add_style( p->content_rf_version, &style_font, 0 );

    p->content_dev_addr = lv_label_create( obj );
    lv_obj_add_style( p->content_dev_addr, &style_font, 0 );


    lv_obj_set_pos(title_lcd_boot_version, 60, 20);
    lv_obj_set_pos(title_lcd_version, 60, 70);
    lv_obj_set_pos(title_t_boot_version, 60, 120);
    lv_obj_set_pos(title_t_update_version, 60, 170);
    lv_obj_set_pos(title_t_app_version, 60, 220);
    lv_obj_set_pos(title_t_back_mcu_version, 60, 270);
    lv_obj_set_pos(title_rf_version, 60, 320);
    lv_obj_set_pos(title_dev_addr, 60, 370);


    lv_obj_set_pos(p->content_lcd_boot_version, 450, 20);
    lv_obj_set_pos(p->content_lcd_version, 450, 70);
    lv_obj_set_pos(p->content_t_boot_version, 450, 120);
    lv_obj_set_pos(p->content_t_update_version, 450, 170);
    lv_obj_set_pos(p->content_t_app_version, 450, 220);
    lv_obj_set_pos(p->content_t_back_mcu_version, 450, 270);
    lv_obj_set_pos(p->content_rf_version, 450, 320);
    lv_obj_set_pos(p->content_dev_addr, 450, 370);
    return obj;
}

//static void _show(irc_lcd_page_t *page, bool v)
//{
//    fact_page_version_t *ipage = (fact_page_version_t *)page;
//		lv_label_set_text( ip->content_lcd_boot_version, LCD_BOOT_VERSION );
//		lv_label_set_text( ip->content_lcd_version, PROJECT_VERSION );
//		//_set_rf_version(ip->content_lcd_boot_version, version_data.lcd_boot) ;
//		//_set_rf_version(ip->content_lcd_version, version_data.lcd_app) ;
//		_set_rf_version(ip->content_t_boot_version, version_data.trans_boot) ;
//		_set_rf_version(ip->content_t_update_version , version_data.trans_update) ;
//		_set_rf_version(ip->content_t_app_version  , version_data.trans_app) ;
//		_set_rf_version(ip->content_t_back_mcu_version   , version_data.trans_standby_mcu) ;
//		_set_rf_version(ip->content_rf_version , version_data.rf_app) ;
//		_set_rf_address(ip->content_dev_addr, version_data.trans_address) ;
//
//
//}
#include "../inc/prepared_page_rc.h"
#include "../inc/working_page_home.h"


static rocker_t *_create_rocker(lv_obj_t *parent);
static rc_lcd_button_t *_create_button(lv_obj_t *parent);
static void _button_set_v(rc_lcd_button_t *btn, uint8_t v);                //二选一或三选一开关设置
static void _button_side_set_clicked(lv_obj_t *btn, bool clicked);         //侧边按键设置
static void _button_lock_arm_set_v(lv_obj_t *btn, lv_obj_t *l, uint8_t v); //锁臂按键设置
static void _set_displacement(lv_obj_t *btn, lv_obj_t *label, uint8_t v);  //排量设置
static void _set_rocker(rocker_t *rocker, uint8_t v);

char string_show[80];

lv_obj_t* prepared_page_rc_create(lv_obj_t *page)
{
    prepared_page_rc_t *p = lv_mem_alloc(sizeof (prepared_page_rc_t));
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_text_color(&style, lv_color_black());
    lv_style_set_bg_opa(&style, LV_OPA_TRANSP);
    lv_style_set_text_font(&style, &working_mode_24px);
    lv_style_set_text_align(&style, LV_TEXT_ALIGN_CENTER );

    static lv_style_t style0;
    lv_style_init(&style0);
    lv_style_set_bg_color(&style0, lv_color_make(0xde, 0xde, 0xde));
    lv_style_set_bg_opa(&style0, LV_OPA_COVER);
    lv_style_set_border_width(&style0, 2);
    lv_style_set_border_color(&style0,  lv_color_make(0xde, 0xde, 0xde));
    lv_style_set_border_width(&style0, 2);
    lv_style_set_border_color(&style0,  lv_color_make(0xde, 0xde, 0xde));

    static lv_style_t alert_bg_style;
    lv_style_init(&alert_bg_style);
    lv_style_set_bg_color(&alert_bg_style, lv_color_hex(0xffffff));
    lv_style_set_bg_opa( &alert_bg_style, 50 );

    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    static lv_style_t style02;
    lv_style_init(&style02);
    lv_style_set_text_color(&style02, lv_color_black());
    lv_style_set_text_font(&style02, &working_mode_24px);
    lv_style_set_text_align(&style02, LV_TEXT_ALIGN_CENTER);

    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_white());
    lv_style_set_bg_opa(&bg_style, 255);
    lv_style_set_border_width(&bg_style, 2);
    lv_style_set_border_color(&bg_style,  lv_color_make(0xde, 0xde, 0xde));

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height - 40 - 40);
    lv_obj_set_pos(obj, 0, 40);
    lv_obj_add_style(obj, &bg_style, 0);

    int i = 0;
    for (i = 0; i < 6; ++i)
    {
        p->rockers[i] = _create_rocker(obj);
        lv_obj_set_size(p->rockers[i]->ibase, 63, 113);
        lv_obj_set_pos(p->rockers[i]->ibase, 95 + 108 * i, 113 - 40);
        lv_obj_add_style(p->rockers[i]->ibase, &style, 0);

        p->up[i] = lv_label_create(obj);
        p->down[i] = lv_label_create(obj);

        // lv_obj_set_size(p->up[i], 63, 113);
        lv_obj_set_pos(p->up[i], 149 + 108 * i, 57);
        lv_obj_add_style(p->up[i], &style, 0);
        lv_obj_add_flag( p->up[i], LV_OBJ_FLAG_HIDDEN );
        lv_label_set_text( p->up[i], "127" );

        // lv_obj_set_size(p->down[i], 63, 113);
        lv_obj_set_pos(p->down[i], 149 + 108 * i, 180);
        lv_obj_add_style(p->down[i], &style, 0);
        lv_obj_add_flag( p->down[i], LV_OBJ_FLAG_HIDDEN );
        lv_label_set_text( p->down[i], "-127" );
    }

    for (i = 0; i < 5; ++i)
    {
        p->btns[i] = _create_button(obj);
        lv_obj_set_size(p->btns[i]->ibase, 55, 51);
        lv_obj_set_pos(p->btns[i]->ibase, 53 + 72 * i, 329 - 40 +3);
        lv_obj_add_style(p->btns[i]->ibase, &style, 0);
        _button_set_v(p->btns[i], 0);
    }

    p->btn_lock_arms = lv_img_create(obj);
    lv_img_set_src(p->btn_lock_arms, &control_cycle_Sbtn);
    lv_obj_set_pos(p->btn_lock_arms, 500 + 20, 337 + 10- 30);
    lv_obj_set_size(p->btn_lock_arms, 44, 44);
    
    lv_obj_t *btn_displacement_bg = lv_img_create(obj);
    lv_img_set_src(btn_displacement_bg, &control_cycle_Sbtn_bg);
    lv_obj_set_pos(btn_displacement_bg, 616 + 15, 325 - 30);
    lv_obj_set_size(btn_displacement_bg, 60, 60);

    p->btn_replacement = lv_img_create(obj);
    lv_img_set_src(p->btn_replacement, &control_cycle_Bbtn2);
    lv_obj_set_pos(p->btn_replacement, 616+15, 325 - 30);
    lv_obj_set_size(p->btn_replacement, 60, 60);

    p->btn_whistle = lv_img_create(obj);
    lv_img_set_src(p->btn_whistle, &control_margin_02);
    lv_obj_set_pos(p->btn_whistle, parent_width - 20, 108 - 40);
    lv_obj_set_size(p->btn_whistle, 20, 54);

    p->btn_emergency = lv_img_create(obj);
    lv_img_set_src(p->btn_emergency, &control_margin_02);
    lv_obj_set_pos(p->btn_emergency, parent_width - 20, 68 + 240 + 30 );
    lv_obj_set_size(p->btn_emergency, 20, 54);

    p->label_emergency = lv_label_create(obj);
    lv_obj_set_pos( p->label_emergency, parent_width - 75, 68 + 250 + 35 );
    lv_label_set_text( p->label_emergency, "急停" );
    lv_obj_add_style(p->label_emergency, &style, 0);

    p->btn_stop = lv_img_create(obj);
    lv_img_set_src(p->btn_stop, &control_margin_02);
    lv_obj_set_pos(p->btn_stop, 0, 108 - 40);
    lv_obj_set_size(p->btn_stop, 20, 54);

    lv_obj_t *tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_stop );
    lv_obj_set_pos( tmp_label, 20, 108 - 35);

    p->btn_start = lv_img_create(obj);
    lv_img_set_src(p->btn_start, &control_margin_02);
    lv_obj_set_pos(p->btn_start, 0, 158);
    lv_obj_set_size(p->btn_start, 20, 54);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_start );
    lv_obj_set_pos( tmp_label, 20, 163 );

    p->label_lock = lv_label_create(obj);
    lv_label_set_text(p->label_lock, "0");
    lv_obj_set_pos(p->label_lock, 512 + 8, 309 - 45);
    lv_obj_add_style(p->label_lock, &style, 0);

    p->label_displacement = lv_label_create(obj);
    lv_label_set_text(p->label_displacement, "0");
    lv_obj_set_pos(p->label_displacement, 611 + 10, 309 - 50);
    lv_obj_set_width( p->label_displacement, 66 );
    lv_obj_add_style(p->label_displacement, &style, 0);
    
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &control_cycle_Bbtn1 );
    lv_obj_set_pos( tmp_label, 616 + 15, 325 - 30 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump );
    lv_obj_set_pos( tmp_label, 616 + 30, 355 );

    //锁臂
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_arm_lock );
    lv_obj_set_pos( tmp_label, 512 + 10, 347 );
    lv_img_set_zoom( tmp_label, 200 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &control_cycle_Sbtn_bg );
    lv_obj_set_pos( tmp_label, 500 + 2, 337 -55 + 3 );

    p->label_rig = lv_label_create( obj );
    lv_label_set_text(p->label_rig, "");
    lv_obj_set_pos(p->label_rig, 620 + 40 +20 +40 + 5 , 109 + 40 -15);
    lv_obj_add_style(p->label_rig, &style, 0);

    p->label_dow = lv_label_create( obj );
    lv_label_set_text(p->label_dow, "");
    lv_obj_set_pos(p->label_dow, 655 , 109 + 50 +20 + 5  );
    lv_obj_add_style(p->label_dow, &style, 0);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_a0);
    lv_obj_set_pos( tmp_label, 98 + 108 * 0, 18 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_b0);
    lv_obj_set_pos( tmp_label, 98 + 108 * 1 , 18 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_c0);
    lv_obj_set_pos( tmp_label, 98 + 108 * 2 , 18 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_d0);
    lv_obj_set_pos( tmp_label, 98 + 108 * 3 , 18 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_e0);
    lv_obj_set_pos( tmp_label, 98 + 108 * 4 , 18 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_f0);
    lv_obj_set_pos( tmp_label, 98 + 108 * 5 , 18 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_a1);
    lv_obj_set_pos( tmp_label, 98 + 108 * 0, 190 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_b1);
    lv_obj_set_pos( tmp_label, 98 + 108 * 1 , 190 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_c1);
    lv_obj_set_pos( tmp_label, 98 + 108 * 2 , 190 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_d1);
    lv_obj_set_pos( tmp_label, 98 + 108 * 3 , 190 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_e1);
    lv_obj_set_pos( tmp_label, 98 + 108 * 4 , 190 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_f1);
    lv_obj_set_pos( tmp_label, 98 + 108 * 5 , 190 );
    lv_img_set_zoom( tmp_label, 220 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump_down);
    lv_obj_set_pos( tmp_label, 56, 255 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_swing_left);
    lv_obj_set_pos( tmp_label, 122, 250 );
    lv_img_set_zoom( tmp_label, 200 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &fast_mode);
    lv_obj_set_pos( tmp_label, 194 , 255 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_up);
    lv_obj_set_pos( tmp_label, 265, 255 );
    lv_img_set_zoom( tmp_label, 200 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump);
    lv_obj_set_pos( tmp_label, 340, 255 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_strong);
    lv_obj_set_pos( tmp_label, 345, 255 );
    lv_img_set_zoom( tmp_label, 200 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump_up);
    lv_obj_set_pos( tmp_label, 56, 255 + 87 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_swing_right);
    lv_obj_set_pos( tmp_label, 122 , 255 + 87);
    lv_img_set_zoom( tmp_label, 200 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &slow_mode);
    lv_obj_set_pos( tmp_label, 194, 255 + 87);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_down);
    lv_obj_set_pos( tmp_label, 265, 255 + 87);
    lv_img_set_zoom( tmp_label, 200 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump);
    lv_obj_set_pos( tmp_label, 340, 255 + 87);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_eco);
    lv_obj_set_pos( tmp_label, 345, 255 + 87);
    lv_img_set_zoom( tmp_label, 200 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &horn_rc);
    lv_obj_set_pos( tmp_label, parent_width - 82, 68);

    p->btn_off = lv_img_create(obj);
    lv_img_set_src(p->btn_off, &control_margin_02);
    lv_obj_set_pos(p->btn_off, parent_width - 20, 288 - 50);
    lv_obj_set_size(p->btn_off, 20, 54);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_power_red);
    lv_obj_set_pos( tmp_label, parent_width - 70, 288 - 40);

    //背景透明图
    p->alert_bg = lv_obj_create(obj);
    lv_obj_add_style(p->alert_bg, &alert_bg_style, 0);
    lv_obj_set_size(p->alert_bg, parent_width, parent_height);
    //感叹号图片
    for (i = 0; i < 3; i++)
    {
        p->alert_icon[i] = lv_img_create(obj);
        lv_img_set_src(p->alert_icon[i], &alert_icon);
        lv_obj_set_style_img_recolor_opa(p->alert_icon[i], 80 , 0);
        lv_img_set_zoom(p->alert_icon[i], 200);
        lv_obj_add_flag(p->alert_icon[i], LV_OBJ_FLAG_HIDDEN);
    }
    lv_obj_align_to(p->alert_icon[0], p->btns[0]->ibase, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align_to(p->alert_icon[1], p->btns[1]->ibase, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align_to(p->alert_icon[2], p->btns[3]->ibase, LV_ALIGN_CENTER, 0, 0);

    for (i = 3; i < 9; i++)
    {
        p->alert_icon[i] = lv_img_create(obj);
        lv_img_set_src(p->alert_icon[i], &alert_icon);
        lv_obj_set_style_img_recolor_opa(p->alert_icon[i], 80 , 0);
        lv_obj_align_to(p->alert_icon[i], p->rockers[i-3]->ibase, LV_ALIGN_CENTER, 0, 0);
        lv_img_set_zoom(p->alert_icon[i], 200);
        lv_obj_add_flag(p->alert_icon[i], LV_OBJ_FLAG_HIDDEN);
    }

    p->alert_icon[10] = lv_img_create(obj);
    lv_img_set_src(p->alert_icon[10], &alert_icon);
    lv_obj_set_style_img_recolor_opa(p->alert_icon[10], 80 , 0);
    lv_obj_align_to(p->alert_icon[10], p->btn_emergency, LV_ALIGN_CENTER, 0, 0);
    lv_img_set_zoom(p->alert_icon[10], 200);
    lv_obj_add_flag(p->alert_icon[10], LV_OBJ_FLAG_HIDDEN);


#if 0 //测试用
    static lv_style_t style_test;
    lv_style_init(&style_test);
    lv_style_set_text_color(&style_test, lv_color_white());

    lv_obj_t *test_label = lv_label_create( obj );
    lv_label_set_text( test_label, "RC-PAGE" );
    lv_obj_set_pos( test_label, 0, 0 );
    lv_obj_add_style( test_label, &style_test, 0 );
#endif
    return obj;
}

static rc_lcd_button_t *_create_button(lv_obj_t *parent)
{
    rc_lcd_button_t *btn = (rc_lcd_button_t *)malloc(sizeof(rc_lcd_button_t));
    if (!btn)
    {
        return NULL;
    }
    btn->ibase = lv_obj_create(parent);
    btn->v = lv_img_create(btn->ibase);
    lv_img_set_src(btn->v, &control_s_btn02);
    lv_obj_set_pos(btn->v, 0, 0);
    lv_obj_set_size(btn->v, 55, 51);

    return btn;
}

//二选一或三选一开关设置
static void _button_set_v(rc_lcd_button_t *btn, uint8_t v)
{
    if (v == 0)
    { //中间
        lv_img_set_src(btn->v, &control_s_btn02);
    }
    else if (v == 1)
    { //上
        lv_img_set_src(btn->v, &control_s_btn01);
    }
    else if (v == 2)
    { //下
        lv_img_set_src(btn->v, &control_s_btn03);
    }
    else
    {
        lv_img_set_src(btn->v, &control_s_btn02);
    }
}

//侧边按键设置
static void _button_side_set_clicked(lv_obj_t *btn, bool clicked)
{
    if (clicked)
    {
        lv_img_set_src(btn, &control_margin_01);
    }
    else
    {
        lv_img_set_src(btn, &control_margin_02);
    }
}

//锁臂按键设置
static void _button_lock_arm_set_v(lv_obj_t *btn, lv_obj_t *l, uint8_t v)
{
    static const char *texts[] = {
        "0",
        "1",
        "1+2",
        "1+2+3",
        "2",
        "3",
        "2+3"};
    if (v > 6)
    {
        v = 6;
    }
    lv_label_set_text(l, texts[v]);
    //图片旋转
    lv_img_set_angle(btn, v * 257);
}

static void _set_displacement(lv_obj_t *btn, lv_obj_t *label, uint8_t v) //排量设置
{
    if (v > 127)
    {
        v = 127;
    }
    char temp[10];
    float tv = v / 12.7;
    sprintf(temp, "%.1f", tv);
    lv_label_set_text(label, temp);
    //图片旋转
    lv_img_set_angle(btn, tv * 285);
}

static void _set_rocker(rocker_t *rocker, uint8_t v)
{
    if (v == 0x00)
    { //在中间
        lv_img_set_src(rocker->v, &control_btn02);
        lv_obj_set_pos(rocker->v, 0, 34);
    }
    else if (v <= 0x7F)
    { //下降
        lv_img_set_src(rocker->v, &control_btn04);
        lv_obj_set_pos(rocker->v, 0, 34 + 25);
    }
    else
    { //上升
        lv_img_set_src(rocker->v, &control_btn03);
        lv_obj_set_pos(rocker->v, 0, 34 - 25);
    }
}

rocker_t *_create_rocker(lv_obj_t *parent)
{
    rocker_t *r = (rocker_t *)malloc(sizeof(rocker_t));
    if (!r)
    {
        return NULL;
    }

    r->ibase = lv_obj_create(parent);
    lv_obj_t *bg_img = lv_img_create(r->ibase);
    lv_img_set_src(bg_img, &control_btn01);
    lv_obj_set_pos(bg_img, 0, 0);
    lv_obj_set_size(bg_img, 63, 113);

    r->v = lv_img_create(bg_img);
    lv_img_set_src(r->v, &control_btn02);
    lv_obj_set_pos(r->v, 0, 34);
    lv_obj_set_size(r->v, 63, 42);


    return r;
}
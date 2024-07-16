#include "../inc/working_page_setting.h"
#include "../inc/working_page_home.h"

static setting_lcd_button_t *_create_button(lv_obj_t *parent);
static void _button_set_v(setting_lcd_button_t *btn, uint8_t v);                //二选一或三选一开关设置

lv_obj_t* working_page_setting_init(lv_obj_t *page)
{
    working_page_setting_t *p = lv_mem_alloc(sizeof (working_page_setting_t));

    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height - 60 - 60);
    lv_obj_set_pos(obj, 0, 60);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    //背景
    lv_obj_t *temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_page_bg);
    lv_obj_set_pos(temp_state, 0,60);

    //上1
    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0c0);
    lv_obj_set_pos(temp_state, 532,149 - 60);

    //上2
    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0d0);
    lv_obj_set_pos(temp_state, 680,149 - 60);

    //下1
    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0c1);
    lv_obj_set_pos(temp_state, 532,314 - 60);

    //下2
    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0d1);
    lv_obj_set_pos(temp_state, 680,314 - 60);

    //背光图标
    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0i0);
    lv_obj_set_pos(temp_state, 380,419 - 60);

    //语言图标
    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0j0);
    lv_obj_set_pos(temp_state, 380,494 - 60);

    temp_state = lv_label_create(obj);
    lv_obj_set_pos(temp_state,  423, 497 - 60);
    lv_label_set_text(temp_state, "语言：");
    lv_obj_add_style(temp_state, theme_style_get_label_normal_20px_0(), 0);

    temp_state = lv_label_create(obj);
    lv_obj_set_pos(temp_state,  480, 497 - 60);
    lv_label_set_text(temp_state, "中文");
    lv_obj_add_style(temp_state, theme_style_get_label_normal_20px_green(), 0);

    p->backlight_bar = lv_bar_create( obj);
    lv_bar_set_range(p->backlight_bar, 0, 100);
    lv_obj_set_pos(p->backlight_bar, 420, 419 - 60);
    lv_obj_set_size(p->backlight_bar, 445, 32);
    lv_obj_set_style_radius(p->backlight_bar, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(p->backlight_bar, 0, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(p->backlight_bar, lv_color_hex(0x979797), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(p->backlight_bar, LV_OPA_100, LV_PART_MAIN);
    lv_obj_set_style_bg_color(p->backlight_bar, lv_color_hex(0x69C00D), LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(p->backlight_bar, LV_OPA_100, LV_PART_INDICATOR);
    lv_bar_set_value(p->backlight_bar, 70, LV_ANIM_ON);

    p->backlight_value = lv_label_create(obj);
    lv_obj_set_pos(p->backlight_value,  870, 425 - 60);
    lv_label_set_text(p->backlight_value, "70%");
    lv_obj_add_style(p->backlight_value, theme_style_get_label_normal_20px_0(), 0);

    static lv_point_t line_points1[] ={{379, 398 - 60}, {902, 398 - 60}};
    temp_state = lv_line_create(obj);
    lv_obj_add_style(temp_state,theme_style_get_line_green(), 0);
    lv_line_set_points(temp_state, line_points1, 2);

    static lv_point_t line_points2[] ={{379, 474 - 60}, {902, 474 - 60}};
    temp_state = lv_line_create(obj);
    lv_obj_add_style(temp_state,theme_style_get_line_green(), 0);
    lv_line_set_points(temp_state, line_points2, 2);

    static lv_point_t line_point3[] ={{379, 550 - 60}, {902, 550 - 60}};
    temp_state = lv_line_create(obj);
    lv_obj_add_style(temp_state,theme_style_get_line_green(), 0);
    lv_line_set_points(temp_state, line_point3, 2);

    for (int i = 0; i < 2; ++i)
    {
        p->btns[i] = _create_button(obj);
        lv_obj_set_size(p->btns[i]->ibase, 88, 82);
        lv_obj_set_pos(p->btns[i]->ibase, 527 + 146 * i, 214 - 60);
        _button_set_v(p->btns[i], 0);
    }

    //观察者模式
    //lv_subject_add_observer_obj(&subject_note_all, note_observer_list_cb, page, NULL);

    return obj;
}

static setting_lcd_button_t *_create_button(lv_obj_t *parent)
{
    setting_lcd_button_t *btn = (setting_lcd_button_t *)malloc(sizeof(setting_lcd_button_t));
    if (!btn)
    {
        return NULL;
    }

    btn->ibase = lv_label_create(parent);
    lv_label_set_text(btn->ibase, "");
    btn->v = lv_img_create(btn->ibase);
    lv_img_set_src(btn->v, &control_s_btn02);
    lv_obj_set_pos(btn->v, 0, 0);
    lv_obj_set_size(btn->v, 88, 82);
    lv_obj_clear_flag(btn->ibase, LV_OBJ_FLAG_SCROLLABLE);

    return btn;
}

//二选一或三选一开关设置
static void _button_set_v(setting_lcd_button_t *btn, uint8_t v)
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

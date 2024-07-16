#include "../inc/prepared_header.h"
#include <stdlib.h>

//static void _header_refresh(irc_lcd_header_t *ih, void *data);

irc_lcd_header_t *prepared_header_create(lv_obj_t *parent)
{
    prepared_header_t *h = (prepared_header_t *)malloc(sizeof(prepared_header_t));
    if (!h)
    {
        return NULL;
    }
    irc_lcd_header_t *ih = (irc_lcd_header_t *)h;
    irc_lcd_header_init(&h->base, parent);

    return ih;
}

//static void _header_refresh(irc_lcd_header_t *ih, void *data)
//{
//    if (data == NULL)
//    {
//        return;
//    }
//    prepared_header_t *h = (prepared_header_t *)ih;
//    rc_lcd_header_data_t *d = (rc_lcd_header_data_t *)data;
//
//    static char *_titles[] = {
//        "PREPARED-BLACK",
//        "PREPARED-RC",
//    };
//
//    lv_label_set_text(ih->title, _titles[d->title_type]);
//}
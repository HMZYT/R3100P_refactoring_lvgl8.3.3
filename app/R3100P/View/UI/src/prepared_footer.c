#include "../inc/prepared_footer.h"
#include <stdlib.h>

irc_lcd_footer_t *prepared_footer_create(lv_obj_t *parent)
{
    prepared_footer_t *h = (prepared_footer_t *)malloc(sizeof(prepared_footer_t));
    if (!h)
    {
        return NULL;
    }
    irc_lcd_footer_t *ih = (irc_lcd_footer_t *)h;
    irc_lcd_footer_init(&h->base, parent);

    return ih;
}
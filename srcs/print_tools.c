#include "../includes/header.h"

void    print_crist(t_all *all)
{
    int x;
    int y;
    int i;

    x = all->resolution->width / 2 - 10;
    y = all->resolution->height / 2 - 10;
    i = -1;
    while (++i < 20)
        if (i < 8 || i > 12)
            pixel_put(all, x + i, all->resolution->height / 2, 0x777777);
    i = -1;
    while (++i < 20)
        if (i < 8 || i > 12)
            pixel_put(all, all->resolution->width / 2, y + i, 0x777777);
}
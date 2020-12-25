#include "../includes/header.h"

void    ray(t_all *all, float dir)
{
    float x;
    float y;

    x = all->plr->x;
    y = all->plr->y;
    while (all->map[(int)floor(y)][(int)floor(x)] != '1')
    {
        x += (cos(dir)/10);
        y += (sin(dir)/10);
        pixel_put(all, x * SCALE, y * SCALE, 0xbbbbbb);
    }
}

void    draw_rays(t_all *all)
{
    float dstart;
    float dstop;

    dstart = all->plr->dir - PI / 4;
    dstop = dstart + PI / 2;
    while (dstart < dstop)
    {
        dstart += 0.001;
        ray(all, dstart);
    }

}

void    put_map_in_window(t_all *all)
{
    int x;
    int y;

    all->win->img = mlx_new_image(all->win->mlx, all->resolution->width,
                                        all->resolution->height);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bpp,
										&all->win->line_l, &all->win->en);
    y = -1;
    while (all->map[++y])
    {
        x = -1;
        while (all->map[y][++x])
        {
            if (all->map[y][x] == '1')
                pixel_put(all, x, y, 0xffaaff);
        }
    }
    y = all->plr->y;
    x = all->plr->x;
    pixel_put(all, x, y, 0xbbbbbb);
    draw_rays(all);
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
    mlx_destroy_image(all->win->mlx, all->win->img);
}

void    put_line(t_all *all, char *line, int y, int scl)
{
    int     x;
    int     sc;

    x = 0;
    sc = 0;
    while (line[x])
    {
        if (line[x] == '1')
            pixel_put(all, x * scl + sc, y, 0xffaaff);
        sc++;
        if (sc == scl)
        {
            x++;
            sc = 0;
        }
    }
}

int     put_map(t_all *all, int scl)
{
    int     y;
    int     sc;
    
    all->win->img = mlx_new_image(all->win->mlx, all->resolution->width,
                                        all->resolution->height);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bpp,
										&all->win->line_l, &all->win->en);
    y = 0;
    sc = 0;
    while (all->map[y])
    {
        put_line(all, all->map[y], y * scl + sc, scl);
        sc++;
        if (sc == scl)
        {
            y++;
            sc = 0;
        }
    }
    pixel_put(all, all->plr->x * scl, all->plr->y * scl, 0xbbbbbb);
    draw_rays(all);
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
    mlx_destroy_image(all->win->mlx, all->win->img);
    return (0);
}
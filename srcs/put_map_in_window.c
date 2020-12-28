#include "../includes/header.h"

void    ray(t_all *all, t_vec *dir)
{
    t_vec   ray;
    float   res;
    float   ddx;
    float   ddy;

    res = 0;
    ray.x = all->plr->pos->x;
    ray.y = all->plr->pos->y;
    ddx = fabs(1/dir->x);
    ddy = fabs(1/dir->y);
    while (all->map[(int)ray.y][(int)ray.x] != '1')
    {
        add_vector(&ray, dir, 100);
        pixel_put(all, ray.x * SCALE, ray.y * SCALE, 0xbbbbbb);
    }
}

void    draw_rays(t_all *all)
{
    int     i;
    t_vec   start;

    i = 0;
    sub_three(&start, all->plr->dir, all->plr->plane, 1);
    while (i < all->resolution->width)
    {
        ray(all, &start);
        add_vector(&start, all->plr->plane, all->resolution->width / 2);
        i++;
    }
    //ray(all, all->plr->dir);
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
    pixel_put(all, all->plr->pos->x * scl, all->plr->pos->y * scl, 0xbbbbbb);
    draw_rays(all);
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
    mlx_destroy_image(all->win->mlx, all->win->img);
    return (0);
}
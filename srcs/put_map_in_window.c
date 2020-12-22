#include "../includes/header.h"

void    ray(t_all *all, float dir)
{
    float x;
    float y;

    x = all->plr->x;
    y = all->plr->y;
    while (all->map[(int)y][(int)x] != '1')
    {
        x += (cos(dir));
        y += (sin(dir));
        pixel_put(all, round(x), round(y), 0xbbbbbb);
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
        dstart += 0.005;
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

char    *scale_line(char *line, int scl)
{
    int     x;
    int     sc;
    char    *res;

    if (!(res = (char *)ft_calloc(ft_strlen(line) * scl + 1, sizeof(char))))
        return (NULL);
    x = 0;
    sc = 0;
    while (line[x])
    {
        res[(scl * x) + sc] = line[x];
        sc++;
        if (sc == scl)
        {
            x++;
            sc = 0;
        }
    }
    res[x * scl + 1] = '\0';
    return (res);
}

int     scale_map(t_all *all, int scl)
{
    int     y;
    int     sc;
    char    **res;

    if (!(res = (char **)ft_calloc((map_size(all->map) * scl) + 1, sizeof(char *))))
        return (puterror("allocation error in scale_map"));
    y = 0;
    sc = 0;
    while (all->map[y])
    {
        if (!(res[(scl * y) + sc] = scale_line(all->map[y], scl)))
            return (puterror("allocation error in scale_map"));
        sc++;
        if (sc == scl)
        {
            y++;
            sc = 0;
        }
    }
    res[y * scl + 1] = NULL;
    all->map = res;
    return (0);
}
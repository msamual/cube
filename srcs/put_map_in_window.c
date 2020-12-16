#include "../includes/header.h"

void    put_map_in_window(t_all *all)
{
    int x;
    int y;

    y = -1;
    while (all->map[++y])
    {
        x = -1;
        while (all->map[y][++x])
        {
            if (all->map[y][x] == '1')
                mlx_pixel_put(all->win->mlx, all->win->win, x, y, 0xffaaff);
        }
    }
    y = all->plr->y;
    x = all->plr->x;
    mlx_pixel_put(all->win->mlx, all->win->win, x, y, 0xbbbbbb);
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
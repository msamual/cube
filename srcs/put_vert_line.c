/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_vert_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:10:25 by msamual           #+#    #+#             */
/*   Updated: 2021/01/02 12:10:27 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void    print_f_c(t_all *all)
{
    int x;
    int y;
    int flor;
    int ceiling;

    y = 0;
    flor = all->color->fred * 65536 + all->color->fgreen * 256 + all->color->fblue;
    ceiling = all->color->cred * 65536 + all->color->cgreen * 256 + all->color->cblue;
    while (y < all->resolution->height / 2 + all->plr->view && y < all->resolution->height)
    {
        x = 0;
        while (x < all->resolution->width)
            pixel_put(all, x++, y, ceiling);
        y++;
    }
    while (y < all->resolution->height)
    {
        x = 0;
        while (x < all->resolution->width)
            pixel_put(all, x++, y, flor);
        y++;
    }
}

int     get_color(t_img tex, double j, int x)
{
    char    *img;
    int     color;

    img = tex.addr;
    color = *(int *)(img + (tex.width * 4 * (int)j) + x * 4);
    return (color);
}

void    print_line(t_all *all, t_img tex, t_line line, t_ray *ray)
{
    double  step;
    int     color;
    int     x;
    double  j;

    step = 1.0 * tex.height / line.height;
    j = (line.start - all->resolution->height / 2 + line.height / 2 - all->plr->view) * step;
    x = (int)(ray->wallx * tex.width);
    if (ray->side == 0 && ray->dirx < 0)
        x = tex.width - x - 1;
    if (ray->side == 1 && ray->diry > 0)
        x = tex.width - x - 1;
    while (line.start < line.end)
    {
        color = get_color(tex, j, x);
        pixel_put(all, line.i, line.start, color);
        line.start++;
        j += step;
    }
}

void    put_vert_line(t_all *all, t_ray *ray, int i)
{
    t_line  line;
    
    line.i = i;
    line.height = (int)(all->resolution->height / ray->perp);
    line.start = -line.height / 2 + all->resolution->height / 2 + all->plr->view;
    if (line.start < 0)
        line.start = 0;
    line.end = line.height / 2 + all->resolution->height / 2 + all->plr->view;
    if (line.end >= all->resolution->height)
        line.end = all->resolution->height - 1;
    if (ray->side && ray->diry > 0) /* Южная сторона */
        print_line(all, all->textures->south, line, ray);
    if (ray->side && ray->diry <= 0) /* Северная сторона */
        print_line(all, all->textures->north, line, ray);
    if (!ray->side && ray->dirx > 0) /* запад */
        print_line(all, all->textures->west, line, ray);
    if (!ray->side && ray->dirx <= 0) /* Восток */
        print_line(all, all->textures->east, line, ray);
}
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

void    put_vert_line(t_all *all, t_ray *ray, int i)
{
    int     height;
    int     start;
    int     end;
    int     color;
    
    height = (int)(all->resolution->height / ray->perp);
    start = -height / 2 + all->resolution->height / 2 + all->plr->view;
    if (start < 0)
        start = 0;
    end = height / 2 + all->resolution->height / 2 + all->plr->view;
    if (end >= all->resolution->height)
        end = all->resolution->height - 1;
    if (ray->side && ray->diry > 0) /* Южная сторона */
        color = 0x201033;
    if (ray->side && ray->diry <= 0) /* Северная сторона */
        color = 0x005540;
    if (!ray->side && ray->dirx > 0) /* запад */
        color = 0x030335;
    if (!ray->side && ray->dirx <= 0) /* Восток */
        color = 0x404015;
    while(start < end)
    {
        pixel_put(all, i, start, color);
        start++;
    }   
}
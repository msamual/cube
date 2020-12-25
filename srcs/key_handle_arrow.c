/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_arrow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:02:48 by msamual           #+#    #+#             */
/*   Updated: 2020/12/25 16:02:52 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int    quit(t_win *win)
{
    mlx_destroy_window(win->mlx, win->win);
    exit(0);
    return (0);
}

void    rotate_left(t_all *all)
{
    float x;
    float y;

    x = all->plr->dirx * cos(-0.1) - sin(-0.1) * all->plr->diry;
    y = all->plr->dirx * sin(-0.1) + cos(-0.1) * all->plr->diry;
    all->plr->dirx = x;
    all->plr->diry = y;
}

void    rotate_right(t_all *all)
{
    float x;
    float y;

    x = all->plr->dirx * cos(0.1) - sin(0.1) * all->plr->diry;
    y = all->plr->dirx * sin(0.1) + cos(0.1) * all->plr->diry;
    all->plr->dirx = x;
    all->plr->diry = y;
}

void		key_handle_arrow(int keycode, t_all *all)
{
    if (keycode == 123)
        rotate_left(all);
    if (keycode == 124)
        rotate_right(all);

    mlx_clear_window(all->win->mlx, all->win->win);
    put_map(all, SCALE);
}
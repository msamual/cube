/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:16:51 by msamual           #+#    #+#             */
/*   Updated: 2020/12/18 15:16:56 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int    quit(t_win *win)
{
    mlx_destroy_window(win->mlx, win->win);
    exit(0);
    return (0);
}

void    move_forward(t_all *all)
{
        all->plr->y += sin(all->plr->dir) * 4;
        all->plr->x += cos(all->plr->dir) * 4;
}

void    move_back(t_all *all)
{
        all->plr->y -= sin(all->plr->dir) * 4;
        all->plr->x -= cos(all->plr->dir) * 4;
}

void    move_left(t_all *all)
{
    all->plr->y += sin(all->plr->dir - PI / 2) * 4;
    all->plr->x += cos(all->plr->dir - PI / 2) * 4;
}

void    move_right(t_all *all)
{
    all->plr->y += sin(all->plr->dir + PI / 2) * 4;
    all->plr->x += cos(all->plr->dir + PI / 2) * 4;
}

int		key_handle(int keycode, t_all *all)
{
    if (keycode == 53)
    	return (quit(all->win));
    if (keycode == 13)
        move_forward(all);
    if (keycode == 1)
        move_back(all);
    if (keycode == 123)
        all->plr->dir -= 0.1;
    if (keycode == 124)
        all->plr->dir += 0.1;
    if (keycode == 0)
        move_left(all);
    if (keycode == 2)
        move_right(all);
    mlx_clear_window(all->win->mlx, all->win->win);
    put_map_in_window(all);
    return (0);
}
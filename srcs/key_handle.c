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


void    move_forward(t_all *all)
{
        add_vector(all->plr->pos, all->plr->dir, 5);
}

void    move_back(t_all *all)
{
        sub_vector(all->plr->pos, all->plr->dir, 5);
}

void    move_left(t_all *all)
{
    all->plr->pos->y -= all->plr->dir->x * 0.15;
    all->plr->pos->x += all->plr->dir->y * 0.15;
}

void    move_right(t_all *all)
{
    all->plr->pos->y += all->plr->dir->x * 0.15;
    all->plr->pos->x -= all->plr->dir->y * 0.15;
}

int		key_handle(int keycode, t_all *all)
{
    if (keycode == 53)
    	return (quit(all->win));
    if (keycode == 13)
        move_forward(all);
    if (keycode == 1)
        move_back(all);
    if (keycode == 0)
        move_left(all);
    if (keycode == 2)
        move_right(all);
    if (keycode == 123)
        rotate_left(all);
    if (keycode == 124)
        rotate_right(all);
    return (0);
}

int     to_window(t_all **all)
{
    mlx_clear_window((*all)->win->mlx, (*all)->win->win);
    put_map((*all), 16);
    return (0);
}
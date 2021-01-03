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
        add_vector(all->plr->pos, all->plr->dir, 15);
}

void    move_back(t_all *all)
{
        sub_vector(all->plr->pos, all->plr->dir, 15);
}

void    move_left(t_all *all)
{
    all->plr->pos->y -= all->plr->dir->x * 0.10;
    all->plr->pos->x += all->plr->dir->y * 0.10;
}

void    move_right(t_all *all)
{
    all->plr->pos->y += all->plr->dir->x * 0.10;
    all->plr->pos->x -= all->plr->dir->y * 0.10;
}

int		key_handle(int keycode, t_all *all)
{
    if (keycode == 53)
    	all->move->exit = 1;
    if (keycode == 13)
        all->move->forward = 1;
    if (keycode == 1)
        all->move->back = 1;
    if (keycode == 0)
        all->move->left = 1;
    if (keycode == 2)
        all->move->right = 1;
    if (keycode == 123)
        all->move->turn_left = 1;
    if (keycode == 124)
        all->move->turn_right = 1;
    return (0);
}

int    move(t_all *all)
{
    if (all->move->exit)
        return (quit(all->win->win));
    if (all->move->forward)
        move_forward(all);
    if (all->move->back)
        move_back(all);
    if (all->move->left)
        move_left(all);
    if (all->move->right)
        move_right(all);
    if (all->move->turn_left)
        rotate_left(all);
    if (all->move->turn_right)
        rotate_right(all);
    return (0);
}

int     to_window(t_all **all)
{
    move(*all);
    mlx_clear_window((*all)->win->mlx, (*all)->win->win);
    put_map((*all), 16);
    return (0);
}
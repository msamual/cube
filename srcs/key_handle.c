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
    double x;
    double y;

    x = all->plr->pos->x + all->plr->dir->x * 0.01 * SPEED;
    y = all->plr->pos->y + all->plr->dir->y * 0.01 * SPEED;
    if (all->map[(int)all->plr->pos->y][(int)x] != '1')
        all->plr->pos->x = x;
    if (all->map[(int)y][(int)all->plr->pos->x] != '1')
        all->plr->pos->y = y;
}

void    move_back(t_all *all)
{
    double x;
    double y;

    x = all->plr->pos->x - all->plr->dir->x * 0.01 * SPEED;
    y = all->plr->pos->y - all->plr->dir->y * 0.01 * SPEED;
    if (all->map[(int)all->plr->pos->y][(int)x] != '1')
        all->plr->pos->x = x;
    if (all->map[(int)y][(int)all->plr->pos->x] != '1')
        all->plr->pos->y = y;
}

void    move_left(t_all *all)
{
    double x;
    double y;

    x = all->plr->pos->x + all->plr->dir->y * 0.01 * SPEED;
    y = all->plr->pos->y - all->plr->dir->x * 0.01 * SPEED;
    if (all->map[(int)all->plr->pos->y][(int)x] != '1')
        all->plr->pos->x = x;
    if (all->map[(int)y][(int)all->plr->pos->x] != '1')
        all->plr->pos->y = y;
}

void    move_right(t_all *all)
{
    double x;
    double y;

    x = all->plr->pos->x - all->plr->dir->y * 0.01 * SPEED;
    y = all->plr->pos->y + all->plr->dir->x * 0.01 * SPEED;
    if (all->map[(int)all->plr->pos->y][(int)x] != '1')
        all->plr->pos->x = x;
    if (all->map[(int)y][(int)all->plr->pos->x] != '1')
        all->plr->pos->y = y;
}

int		key_handle(int keycode, t_all *all)
{
    if (keycode == 126)
        all->move->up = 1;
    if (keycode == 125)
        all->move->down = 1;
    if (keycode == 257)
        all->move->run = 1;
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
    if (all->move->up)
        all->plr->view += 10;
    if (all->move->down)
        all->plr->view -= 10;
    return (0);
}

int     to_window(t_all **all)
{
    move(*all);
    if ((*all)->move->run)
        move((*all));
    mlx_clear_window((*all)->win->mlx, (*all)->win->win);
    put_map((*all), (*all)->resolution->width / 200);
    return (0);
}
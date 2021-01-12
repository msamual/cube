/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:51:32 by msamual           #+#    #+#             */
/*   Updated: 2021/01/10 13:52:01 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void    move_forward(t_all *all)
{
    double  x;
    double  y;

    x = all->plr->pos->x + all->plr->dir->x * 0.01 * SPEED;
    y = all->plr->pos->y + all->plr->dir->y * 0.01 * SPEED;
    if (!ft_strchr("12", all->map[(int)all->plr->pos->y][(int)x]))
        all->plr->pos->x = x;
    if (!ft_strchr("12", all->map[(int)y][(int)all->plr->pos->x]))
        all->plr->pos->y = y;
}

void    move_back(t_all *all)
{
    double  x;
    double  y;
    
    x = all->plr->pos->x - all->plr->dir->x * 0.01 * SPEED;
    y = all->plr->pos->y - all->plr->dir->y * 0.01 * SPEED;
    if (all->map[(int)all->plr->pos->y][(int)x] != '1')
        all->plr->pos->x = x;
    if (all->map[(int)y][(int)all->plr->pos->x] != '1')
        all->plr->pos->y = y;
}

void    move_left(t_all *all)
{
    double  x;
    double  y;

    x = all->plr->pos->x + all->plr->dir->y * 0.01 * SPEED;
    y = all->plr->pos->y - all->plr->dir->x * 0.01 * SPEED;
    if (all->map[(int)all->plr->pos->y][(int)x] != '1')
        all->plr->pos->x = x;
    if (all->map[(int)y][(int)all->plr->pos->x] != '1')
        all->plr->pos->y = y;
}

void    move_right(t_all *all)
{
    double  x;
    double  y;

    x = all->plr->pos->x - all->plr->dir->y * 0.01 * SPEED;
    y = all->plr->pos->y + all->plr->dir->x * 0.01 * SPEED;
    if (all->map[(int)all->plr->pos->y][(int)x] != '1')
        all->plr->pos->x = x;
    if (all->map[(int)y][(int)all->plr->pos->x] != '1')
        all->plr->pos->y = y;
}

int     move(t_all *all)
{
    if (all->move->exit)
        return (quit(all->win));
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
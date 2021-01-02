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
    double x;
    double y;

    x = all->plr->dir->x * cos(-0.1) - sin(-0.1) * all->plr->dir->y;
    y = all->plr->dir->x * sin(-0.1) + cos(-0.1) * all->plr->dir->y;
    all->plr->dir->x = x;
    all->plr->dir->y = y;
    x = all->plr->plane->x * cos(-0.1) - sin(-0.1) * all->plr->plane->y;
    y = all->plr->plane->x * sin(-0.1) + cos(-0.1) * all->plr->plane->y;
    all->plr->plane->x = x;
    all->plr->plane->y = y;
}

void    rotate_right(t_all *all)
{
    double x;
    double y;

    x = all->plr->dir->x * cos(0.1) - sin(0.1) * all->plr->dir->y;
    y = all->plr->dir->x * sin(0.1) + cos(0.1) * all->plr->dir->y;
    all->plr->dir->x = x;
    all->plr->dir->y = y;
    x = all->plr->plane->x * cos(0.1) - sin(0.1) * all->plr->plane->y;
    y = all->plr->plane->x * sin(0.1) + cos(0.1) * all->plr->plane->y;
    all->plr->plane->x = x;
    all->plr->plane->y = y;
}
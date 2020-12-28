/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:57:04 by msamual           #+#    #+#             */
/*   Updated: 2020/12/25 15:57:06 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void    init_plane(t_all *all)
{
    all->plr->plane->x = ANGLE;
    all->plr->plane->y = 0;
}

void    init_player(t_all *all, int posx, int posy)
{
    all->plr->pos->x = posx + 0.5;
    all->plr->pos->y = posy + 0.5;
    if (all->map[posy][posx] == 'N')
    {
        all->plr->dir->x = 0;
        all->plr->dir->y = -1;
    }
    if (all->map[posy][posx] == 'E')
    {
        all->plr->dir->x = 1;
        all->plr->dir->y = 0;
    }
    if (all->map[posy][posx] == 'S')
    {
        all->plr->dir->x = 0;
        all->plr->dir->y = 1;
    }
    if (all->map[posy][posx] == 'W')
    {
        all->plr->dir->x = -1;
        all->plr->dir->y = 0;
    }
    all->map[posy][posx] = '0';
    init_plane(all);
}
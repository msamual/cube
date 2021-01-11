/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:12:39 by msamual           #+#    #+#             */
/*   Updated: 2021/01/09 14:13:03 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int     mouse_handle(t_all *all)
{
    int x = 0;
    int y = 0;

    mlx_mouse_get_pos(all->win->win, &x, &y);
    //mlx_mouse_move(all->win->win, x, y);
    //printf("x = %d y = %d\n", x ,y);

    return (0);
}
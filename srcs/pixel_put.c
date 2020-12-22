/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:42:25 by msamual           #+#    #+#             */
/*   Updated: 2020/12/22 11:42:28 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void    pixel_put(t_all *all, int x, int y, int color)
{
    int *adr;

    adr = all->win->addr;
    adr[(y * all->resolution->width) + x] = color;
}
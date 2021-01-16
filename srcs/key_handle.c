/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:12:35 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:13:54 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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

void	draw(t_all **all)
{
	(*all)->win->img = mlx_new_image((*all)->win->mlx,
			(*all)->resolution->width, (*all)->resolution->height);
	(*all)->win->addr = mlx_get_data_addr((*all)->win->img, &(*all)->win->bpp,
										&(*all)->win->line_l, &(*all)->win->en);
	mlx_clear_window((*all)->win->mlx, (*all)->win->win);
	put_map((*all), (*all)->resolution->width / 200);
	sprites(*all);
	print_crist(*all);
	mlx_put_image_to_window((*all)->win->mlx, (*all)->win->win,
										(*all)->win->img, 0, 0);
	mlx_destroy_image((*all)->win->mlx, (*all)->win->img);
}

int		to_window(t_all **all)
{
	mouse_handle(*all);
	move(*all);
	if ((*all)->move->run)
		move(*all);
	draw(all);
	return (0);
}

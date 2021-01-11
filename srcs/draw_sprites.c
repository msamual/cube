/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:40:23 by msamual           #+#    #+#             */
/*   Updated: 2021/01/11 12:40:43 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_sprite(t_all *all, int i, t_sprite *sprite)
{
	t_line  line;
    
    line.i = i;
    line.height = (int)(all->resolution->height / sprite->dist);
    line.start = -line.height / 2 + all->resolution->height / 2 + all->plr->view;
    if (line.start < 0)
        line.start = 0;
    line.end = line.height / 2 + all->resolution->height / 2 + all->plr->view;
	if (sprite->dist < all->z_buffer[i])
	{
		while (line.start < line.end)
		{
			pixel_put(all, i, line.start, 0xffffff);
			line.start++;
		}
	}
}

double	get_angle(double dirx, double diry, t_all *all)
{
	double	angle;
	double	x;
	double	y;

	x = all->plr->dir->x;
	y = all->plr->dir->y;
	angle = (dirx * x + diry * y);
	angle = angle / (sqrt(dirx * dirx + diry * diry) * sqrt(x * x + y * y));
	return (angle);
}

int		get_index(t_all *all, double angle)
{
	int		res;

	angle = PI / 4 + angle;
	angle = PI / 2 / angle;
	angle = (double)all->resolution->width / angle;
	res = (int)angle;
	return (res);
}

void	put_sprite(t_all *all, t_sprite *sprite)
{
	double		dirx;
	double		diry;
	double		angle;
	int			i;

	i = 0;
	dirx = sprite->pos.x - all->plr->pos->x;
	diry = sprite->pos.y - all->plr->pos->y;
	angle = acos(get_angle(dirx, diry, all));
	if (angle < 0.78539816339)
	{
		if ((dirx < all->plr->dir->x && diry < all->plr->dir->y)
			|| (dirx > all->plr->dir->x && diry > all->plr->dir->y))
			angle = -angle;
		i = get_index(all, angle);
		print_sprite(all, i, sprite);
		printf("angle = %lf i = %d\n", angle, i);
	}

}

void	draw_sprites(t_all *all)
{
	t_list		*lst;
	t_sprite	*sprite;

	lst = all->sprites;
	while(lst)
	{
		sprite = (t_sprite *)lst->data;
		put_sprite(all, sprite);
		lst = lst->next;
	}
}
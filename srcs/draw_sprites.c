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

void	print_line_sprite(t_all *all, int i, t_line line, t_sprite *sprite)
{
	int		color;
	int		*img;
	double	step;
	double	j;
	

	img = (int *)all->textures->sprite.addr;
	if (sprite->dist < all->z_buffer[i])
	{
		step =  1.0 * all->textures->sprite.height / line.height;
		j = (line.start - all->resolution->height / 2 + line.height / 2 - all->plr->view) * step;
		while (line.start < line.end && line.start < all->resolution->height)
		{
			color = (int)img[(int)(j) * all->textures->sprite.width + (int)line.i];
			if (color != 0)
				pixel_put(all, i, line.start, color);
			line.start++;
			j += step;
		}
	}
}

void	print_sprite(t_all *all, int i, t_sprite *sprite)
{
	t_line	line;
	double	view;
	int		j;
	double	step;

	view = all->plr->view;
	line.height = (int)(all->resolution->height / sprite->dist);
	line.width = line.height;
	line.start = -line.height / 2 + all->resolution->height / 2 + view;
	if (line.start < 0)
        line.start = 0;
    line.end = line.height / 2 + all->resolution->height / 2 + view;
	if (line.end >= all->resolution->height)
        line.end = all->resolution->height - 1;
	line.i = 0;
	step = 1.0 * all->textures->sprite.width / line.width;
	i -= line.width / 2;
	j = line.width;
	while (j--)
	{
		print_line_sprite(all, i++, line, sprite);
		line.i += step;
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
	angle = angle / (sqrt(pow(dirx, 2) + pow(diry, 2) * sqrt(pow(x, 2) + pow(y, 2))));
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

double	c_dist(double angle)
{
	double a;

	if (!angle)
		return (1);
	a = angle / (PI / 2 - angle);
	return (sqrt(pow(a, 2) + 1));

}

void	put_sprite(t_all *all, t_sprite *sprite)
{
	t_vec		sdir;
	double		angle;
	int			i;
	double		cameradist;

	i = 0;
	sdir.x = sprite->pos.x - all->plr->pos->x;
	sdir.y = sprite->pos.y - all->plr->pos->y;
	angle = acos(get_angle(sdir.x, sdir.y, all));
	if (angle < PI / 4)
	{
		cameradist = c_dist(angle);
		sprite->dist = sprite->dist + 1 - cameradist;
		if (mul_scl(*all->plr->dir, sdir, 1) < 0)
			angle = -angle;
		i = get_index(all, angle);
		print_sprite(all, i, sprite);
		//printf("angle = %lf i = %d\n", angle, i);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:44:45 by msamual           #+#    #+#             */
/*   Updated: 2020/12/10 15:03:51 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define SCALE 64 // условный размер каждого квадратика в карте
# define PI 3.1415926535

typedef struct		s_win //структура для окна
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				line_l;
	int				bpp;
	int				en;
}					t_win;

typedef struct		s_point // структура для точки
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_plr //структура для игрока и луча
{
	float			x;
	float			y;
	float			dirx;
	float			diry;
	float			plane_x;
	float			plane_y;
}					t_plr;

typedef struct		s_res //разрешение окна
{
	int				width;
	int				height;
}					t_res;

typedef struct		s_tex //текстурки
{
	char			*north;
	char			*west;
	char			*south;
	char			*east;
	char			*sprite;
}					t_tex;

typedef struct		s_color // цвет пола и потолка
{
	unsigned char	fred;
	unsigned char	fgreen;
	unsigned char	fblue;
	unsigned char	cred;
	unsigned char	cgreen;
	unsigned char	cblue;
}					t_color;


typedef struct	s_all // структура для всего вместе
{
	t_res		*resolution;
	t_tex		*textures;
	t_color		*color;
	t_win		*win;
	t_plr		*plr;
	char		**map;
	char		**smap;
}				t_all;

int		parse(char *filename, t_all *all);
int     parse_info(t_all *all, t_list **lst);
int		puterror(char *error_message);
int     init_all(t_all **all);
int     check_map(t_all *all);
int		print_map(char **map);
int     map_size(char **map);
int		scale_map(t_all *all, int scl);
int		key_handle(int keycode, t_all *all);
void    pixel_put(t_all *all, int x, int y, int color);
int     put_map(t_all *all, int scl);
void		key_handle_arrow(int keycode, t_all *all);
void    init_player(t_all *all, int posx, int posy);
int		quit(t_win *win);

#endif

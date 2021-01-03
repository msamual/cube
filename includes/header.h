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
# define ANGLE 1

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

typedef struct		s_ray //структура для луча
{
	int				mapx;
	int				mapy;
	int				side;
	double			dirx;
	double			diry;
	double			x;
	double			y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			step_x;
	double			step_y;
	double			perp;
}					t_ray;


typedef struct		s_vec // структура для точки
{
	double				x;
	double				y;
}					t_vec;

typedef struct		s_plr //структура для игрока и луча
{
	t_vec			*pos;
	t_vec			*dir;
	t_vec			*plane;
}					t_plr;

typedef struct		s_res //разрешение окна
{
	int				width;
	int				height;
}					t_res;

typedef struct		s_texp //текстурки
{
	char			*north;
	char			*west;
	char			*south;
	char			*east;
	char			*sprite;
}					t_texp;

typedef struct		s_img
{
	void			*img;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				en;
	int				*addr;
}					t_img;

typedef struct		s_tex //загруженные текстурки
{
	t_img			north;
	t_img			west;
	t_img			south;
	t_img			east;
	t_img			sprite;
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
	t_texp		*path;
	t_tex		*textures;
	t_color		*color;
	t_win		*win;
	t_plr		*plr;
	char		**map;
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
int		key_handle_arrow(int keycode, t_all *all);
void    init_player(t_all *all, int posx, int posy);
int		quit(t_win *win);
void    add_vector(t_vec *v1, t_vec *v2, double q);
void	sub_vector(t_vec *v1, t_vec *v2, double q);
void    rotate_right(t_all *all);
void    rotate_left(t_all *all);
void    add_three(t_vec *dest, t_vec *v1, t_vec * v2, double q);
void    sub_three(t_vec *dest, t_vec *v1, t_vec * v2, double q);
void    add_vector1(t_vec *v1, t_vec *v2, double q);
void	put_vert_line(t_all *all, t_ray *ray, int i);
void    print_f_c(t_all *all);
int		load_textures(t_all *all);
int		key_release(int keycode, t_all *all);
void    move_forward(t_all *all);
void    move_back(t_all *all);
void    move_left(t_all *all);
void    move_right(t_all *all);
int     to_window(t_all **all);

#endif

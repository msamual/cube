/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:42:46 by msamual           #+#    #+#             */
/*   Updated: 2020/12/10 14:42:48 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		puterror(char *error_message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_message, 2);
	return (-1);
}

int		print_map(char **map)
{
	while (*map)
		ft_putendl(*map++);
	return (0);
}

int     cube(void *mlx, char *filename)
{
	t_all	*all;
	int		scl;

	if (init_all(&all) == -1)
		return (-1);
	if (parse(filename, all) == -1)
		return (-1);
	scl = SCALE;
	all->win->mlx = mlx;
	all->win->win = mlx_new_window(mlx, all->resolution->width,
		all->resolution->height, "Return to castle Wolfestein");
	if (scale_map(all, scl) == -1)
		return (-1);
	put_map_in_window(all);
	mlx_hook(all->win->win, 2, 1L<<0, key_handle, all);
	mlx_loop(all->win->mlx);

	return (0);
}

int main(int ac, char **av)
{
    void    *mlx;

    mlx = mlx_init();
    if (ac > 1)
        return (cube(mlx, av[1]));
	else
		return (puterror("insert path_to map as argument"));
	
    return (0);
}
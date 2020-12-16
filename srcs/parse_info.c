/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:16:43 by msamual           #+#    #+#             */
/*   Updated: 2020/12/14 17:16:47 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int     parse_resolution(char *str, t_all *all)
{
    char    **args;
    int     i;

    if (!(args = ft_split(str, ' ')))
        return (puterror("allocation error, resolution"));
    if (!args[1] || !args[2])
        return (puterror("invalid resolution"));
    all->resolution->width = ft_atoi(args[1]);
    all->resolution->height = ft_atoi(args[2]);
    i = -1;
    while (args[++i])
        free(args[i]);
    free(args);
    return (1);  
}

int     parse_textures(char *str, t_all *all, int code)
{
    if ((ft_strlen(str) < 4) || ((ft_strlen(str) < 3 && code == 5)))
		return (puterror("invalid texture path"));
	if (code == 1)
		all->textures->north = ft_strdup(str + 4);
	if (code == 2)
		all->textures->west = ft_strdup(str + 4);
	if (code == 3)
		all->textures->east = ft_strdup(str + 4);
	if (code == 4)
		all->textures->south = ft_strdup(str + 4);
	if (code == 5)
		all->textures->sprite = ft_strdup(str + 3);
	return (1);
}

int		parse_color(char *str, t_all *all, int code)
{
	char	**color;

	if (!(color = ft_split(str, ',')))
		return (puterror("allocation error, color"));
	if (!color[0] || !color[1] || !color[2])
		return (puterror("invalid color"));
	if (code == 1)
	{
		all->color->fred = ft_atoi(color[0]);
		all->color->fgreen = ft_atoi(color[1]);
		all->color->fblue = ft_atoi(color[2]);
	}
	if (code == 2)
	{
		all->color->cred = ft_atoi(color[0]);
		all->color->cgreen = ft_atoi(color[1]);
		all->color->cblue = ft_atoi(color[2]);
	}
	return (1);
}

int     find(char *str, t_all *all)
{
    if (ft_strnstr(str, "R", 5) == str)
        return (parse_resolution(str, all));
    if (ft_strnstr(str, "NO", 5) == str)
        return (parse_textures(str, all, 1));
    if (ft_strnstr(str, "WE", 5) == str)
        return (parse_textures(str, all, 2));
    if (ft_strnstr(str, "EA", 5) == str)
        return (parse_textures(str, all, 3));
    if (ft_strnstr(str, "SO", 5) == str)
        return (parse_textures(str, all, 4));
    if (ft_strnstr(str, "F", 5) == str)
        return (parse_color(str + 2, all, 1));
    if (ft_strnstr(str, "C", 1) == str)
        return (parse_color(str + 2, all, 2));
    if (ft_strnstr(str, "S", 1) == str)
        return (parse_textures(str, all, 5));
    if (str[0] == '\n' || str[0] == '\0')
        return (1);
    return (0);
}

int     parse_info(t_all *all, t_list **lst)
{
    t_list  *tmp;
    int     i;

    tmp = *lst;
    while (tmp && (i = (find(tmp->data, all))))
    {
        if (i == -1)
            return (-1);
        *lst = (*lst)->next;
        free(tmp->data);
        free(tmp);
        tmp = *lst;
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:14:18 by msamual           #+#    #+#             */
/*   Updated: 2020/12/10 16:14:21 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <stdio.h>

char	**make_map(t_list *tmp, int size)
{
	char	**map;
	int		i;

	if (!(map = (char **)ft_calloc(size + 1, sizeof(char *))))
		return (NULL);
    i = 0;
	while (tmp)
	{
		map[i] = tmp->data;
		tmp = tmp->next;
        i++;
	}
    map[i] = NULL;
	return (map);
}

int		parse(char *filename, t_all *all)
{
	int		fd = open(filename, O_RDONLY);
	char	*line = NULL;
	t_list	*head = NULL;

	while (get_next_line(fd, &line))
        ft_list_push_back(&head, line);
	if (parse_info(all, &head) == -1)
		return (-1);
	if (!(all->map = make_map(head, ft_list_size(head))))
		return (-1);
	init_sprites(all);
	if (!(all->z_buffer = ft_calloc(all->resolution->width, sizeof(double))))
		return (puterror("allocation failed for z_buffer"));
	return (check_map(all));
}
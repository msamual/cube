/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:31:31 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:32:52 by msamual          ###   ########.fr       */
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
		map[i] = ft_strdup(tmp->data);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		parse(char *filename, t_all *all)
{
	int		fd;
	char	*line;
	t_list	*head;
	t_list	*lst;

	line = NULL;
	head = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (puterror("Can't open file map"));
	while (get_next_line(fd, &line))
		ft_list_push_back(&head, line);
	lst = head;
	if (parse_info(all, &head) == -1)
		return (-1);
	if (!(all->map = make_map(head, ft_list_size(head))))
		return (-1);
	ft_list_clear(&lst);
	free(line);
	init_sprites(all);
	if (!(all->z_buffer = ft_calloc(all->resolution->width, sizeof(double))))
		return (puterror("allocation failed for z_buffer"));
	return (check_map(all));
}

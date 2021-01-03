/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 19:41:36 by msamual           #+#    #+#             */
/*   Updated: 2021/01/02 19:41:38 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int    load_textures(t_all *all)
{
    int     *addr;

    all->textures->north.img = mlx_xpm_file_to_image(all->win->mlx,
                                                all->path->north,
                                                &all->textures->north.width,
                                                &all->textures->north.height);
    if (all->textures->north.img == NULL)
        return (puterror("failed to open file north texture"));
    addr = (int *)mlx_get_data_addr(all->textures->north.img, &all->textures->north.bpp,
                                                &all->textures->north.size_line,
                                                &all->textures->north.en);
    all->textures->north.addr = addr;
    printf("%x\n", addr[780]);
    return (0);
}
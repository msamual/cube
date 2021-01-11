/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:45:05 by msamual           #+#    #+#             */
/*   Updated: 2021/01/11 12:45:28 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int     load_textures(t_all *all)
{
    
    if (load_north(all) || load_west(all) || load_south(all)
    || load_east(all) || load_sprite(all))
        return (-1);
    return (0);
}

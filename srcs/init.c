/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:31:03 by msamual           #+#    #+#             */
/*   Updated: 2020/12/15 16:31:05 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int     init_all(t_all **all)
{
    *all = (t_all *)ft_calloc(1, sizeof(t_all));
    (*all)->resolution = (t_res *)ft_calloc(1, sizeof(t_res));
    (*all)->textures = (t_tex *)ft_calloc(1, sizeof(t_tex));
    (*all)->color = (t_color *)ft_calloc(1, sizeof(t_color));
    (*all)->win = (t_win *)ft_calloc(1, sizeof(t_win));
    (*all)->plr = (t_plr *)ft_calloc(1, sizeof(t_plr));
    (*all)->plr->pos = (t_vec *)ft_calloc(1, sizeof(t_vec));
    (*all)->plr->dir = (t_vec *)ft_calloc(1, sizeof(t_vec));
    (*all)->plr->plane = (t_vec *)ft_calloc(1, sizeof(t_vec));
    if (!(*all) || !(*all)->resolution || !(*all)->textures ||
        !(*all)->win || !(*all)->plr || !(*all)->color ||
        !(*all)->plr->pos || !(*all)->plr->dir || !(*all)->plr->plane)
        return (puterror("allocation error in init_all"));
    return (0);
}

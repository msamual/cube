/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:00:01 by msamual           #+#    #+#             */
/*   Updated: 2020/12/28 13:00:03 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void    add_vector(t_vec *v1, t_vec *v2, double q)
{
    v1->x += v2->x / q;
    v1->y += v2->y / q;
}

void    add_vector1(t_vec *v1, t_vec *v2, double q)
{
    v1->x += v2->x * q;
    v1->y += v2->y * q;
}

void    sub_vector(t_vec *v1, t_vec *v2, double q)
{
    v1->x -= v2->x / q;
    v1->y -= v2->y / q;
}

void    add_three(t_vec *dest, t_vec *v1, t_vec * v2, double q)
{
    dest->x = (v1->x + v2->x) / q;
    dest->y = (v1->y + v2->y) / q;
}

void    sub_three(t_vec *dest, t_vec *v1, t_vec * v2, double q)
{
    dest->x = (v1->x - v2->x) / q;
    dest->y = (v1->y - v2->y) / q;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:02:01 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 01:11:44 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_a(int argb)
{
	return (argb & 0xFF);
}

int	get_r(int argb)
{
	return ((argb >> 24) & 0xFF);
}

int	get_g(int argb)
{
	return ((argb >> 16) & 0xFF);
}

int	get_b(int argb)
{
	return ((argb >> 8) & 0xFF);
}

int	get_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}
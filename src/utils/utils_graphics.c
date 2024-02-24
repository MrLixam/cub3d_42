/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:23:31 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 01:13:59 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_graphic	*get_graph(void)
{
	static t_graphic	graphics;

	return (&graphics);
}

void	reset_graph(void)
{
	t_graphic	*graphics;

	graphics = get_graph();
	if (graphics->north)
		free(graphics->north);
	if (graphics->south)
		free(graphics->south);
	if (graphics->west)
		free(graphics->west);
	if (graphics->east)
		free(graphics->east);
	if (graphics->map)
		ft_free_arr(graphics->map);
	if (graphics->floor)
		free(graphics->floor);
	if (graphics->ceiling)
		free(graphics->ceiling);
	graphics->floor = NULL;
	graphics->ceiling = NULL;
}

static void	init_colors(void)
{
	t_graphic	*graphics;

	graphics = get_graph();
	graphics->ceiling->red = 115;
	graphics->ceiling->green = 115;
	graphics->ceiling->blue = 115;
	graphics->floor->red = 127;
	graphics->floor->green = 127;
	graphics->floor->blue = 127;
}

int	check_graph(void)
{
	t_graphic	*graphics;

	graphics = get_graph();
	if (graphics->floor == NULL)
		return (1);
	if (graphics->ceiling == NULL)
		return (1);
	return (0);
}

void	init_graph(void)
{
	t_graphic	*graphics;

	graphics = get_graph();
	graphics->north = NULL;
	graphics->south = NULL;
	graphics->west = NULL;
	graphics->east = NULL;
	graphics->floor = ft_calloc(1, sizeof(t_color));
	graphics->ceiling = ft_calloc(1, sizeof(t_color));
	if (check_graph())
		return ;
	init_colors();
}

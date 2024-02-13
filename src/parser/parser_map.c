/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:32:25 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/13 20:33:13 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_tile(t_game game, size_t y, size_t x)
{
	if ((!x || !y) || (x == game.map_width || y == game.map_height))
		return (1);
	if (is_wspace(game.map[y][x + 1]) || is_wspace(game.map[y][x - 1]))
		return (1);
	if ((is_wspace(game.map[y + 1][x]) || is_wspace(game.map[y - 1][x])))
		return (1);
	return (0);
}

int	parse_map(t_game game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game.map_height)
	{
		x = 0;
		while (x < game.map_width)
		{
			if (!is_in_set("01NSWE ", game.map[y][x]))
				return (1);
			if (is_in_set("0NSWE", game.map[y][x]) && check_tile(game, y, x))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
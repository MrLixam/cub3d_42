/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:11:04 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/05 14:53:58 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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
			if (!is_in_set("01NSWE", game.map[y][x]))
				return (1);
			if (is_in_set("0NSWE", game.map[y][x]) && check_tile(game, y, x))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	base_tests(char *path)
{
	errno = 0;
	if (gnl_count_lines(path) == 0)
	{
		if (errno)
			ft_perror(path);
		else
			ft_error(path, "file is empty");
		return (1);
	}
	return (0);
}

int	index_paths(char **file)
{
	int	i;

	i = 0;
	while (1)
	{
		if (ft_strlen(file[i]) < 3)
		{
			i++;
			continue;
		}
		if (is_in_set("NSEW", file[i][0]))
		
	}
}

int	valid_config(char *path)
{

	if (base_tests(path))
		return (1);
	
}
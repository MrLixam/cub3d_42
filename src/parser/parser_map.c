/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:32:25 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/15 21:20:59 by lvincent         ###   ########.fr       */
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

size_t	get_max_length(char **foo, size_t start)
{
	size_t	max_length;
	size_t	buffer;

	max_length = 0;
	while (foo[start])
	{
		buffer = ft_strlen(foo[start]);
		if (buffer > max_length)
			max_length = buffer;
		start++;
	}
	return (max_length);
}

char **normalize_map(char **file, size_t start)
{
	size_t	max_length;
	size_t	i;
	size_t	j;
	char	**result;

	max_length = get_max_length(file, start);
	result = ft_calloc(ft_len_arr(file) - start + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (file[start])
	{
		result[i] = ft_calloc(max_length + 1, 1);
		if (!result[i])
		{
			ft_free_arr(result);
			return (NULL);
		}
		ft_memset(result[i], 32, max_length);
		j = 0;
		while (file[start][j])
		{
			result[i][j] = file[start][j];
			j++;
		}
		i++;
		start++;
	}
	return (result);
}

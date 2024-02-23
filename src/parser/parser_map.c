/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:32:25 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/23 16:36:59 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_tile(char **map, size_t y, size_t x)
{
	if ((!x || !y) || (map[y][x + 1] == '\0' || map[y + 1] == NULL))
		return (1);
	if (is_wspace(map[y][x + 1]) || is_wspace(map[y][x - 1]))
		return (1);
	if ((is_wspace(map[y + 1][x]) || is_wspace(map[y - 1][x])))
		return (1);
	return (0);
}

static int	parse_map_loop(char **map, size_t y, size_t x, int *found)
{
	int	retval[3];

	retval[0] = is_in_set("01NSWE ", map[y][x]);
	retval[1] = 0;
	retval[2] = is_in_set("0NSWE", map[y][x]);
	if (!retval[0])
		ft_error(NULL, "invalid character in the map, use NSWE01");
	else if (retval[0] && retval[2])
		retval[1] = check_tile(map, y, x);
	if ((retval[0] && retval[2]) && retval[1])
		ft_error(NULL, "the map is not surrounded by walls");
	if (!retval[0] || ((retval[0] && retval[2]) && retval[1]))
		return (1);
	if (retval[2] && map[y][x] != '0')
	{
		*found += 1;
		get_graph()->spawn_x = x;
		get_graph()->spawn_y = y;
	}
	return (0);
}

int	parse_map(char **map)
{
	size_t	y;
	size_t	x;
	int		found;

	y = 0;
	found = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (parse_map_loop(map, y, x, &found))
				return (1);
			x++;
		}
		y++;
	}
	if (!found)
		ft_error(NULL, "the map has no player spawn");
	if (found > 1)
	{
		ft_error(NULL, "the map has multiple player spawns");
		return (1);
	}
	return (!found);
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

char	**normalize_map(char **file, size_t start)
{
	size_t	max_length;
	size_t	index[2];
	char	**result;

	max_length = get_max_length(file, start);
	result = ft_calloc(ft_len_arr(file) - start + 1, sizeof(char *));
	if (!result)
		return (NULL);
	index[0] = 0;
	while (file[start])
	{
		result[index[0]] = ft_calloc(max_length + 1, 1);
		if (!result[index[0]])
		{
			ft_free_arr(result);
			return (NULL);
		}
		ft_memset(result[index[0]], 32, max_length);
		index[1] = 0;
		while (file[start][++index[1] - 1])
			result[index[0]][index[1] - 1] = file[start][index[1] - 1];
		index[0]++;
		start++;
	}
	return (result);
}

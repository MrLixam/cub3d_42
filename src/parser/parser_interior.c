/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:11:04 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/13 19:07:01 by lvincent         ###   ########.fr       */
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

int	index_path(char *line, char **storage)
{
	char	*path;
	int		start;

	start = 2;
	while (ft_isspace(line[start]))
		start++;
	path = ft_substr(line, start, ft_strlen(line));
	if (!path)
		ft_error(NULL, "allocation error");
	if (!path)
		return (1);
	if (name_parser(path, ".xpm"))
	{
		ft_error(path, "Invalid file type, use .xpm only");
		free(path);
		return (1);
	}
	if (not_valid_file(path))
	{
		ft_perror(path);
		free(path);
		return (1);
	}
	*storage = path;
	return (0);
}

int	is_path(char *line)
{
	int			rv;
	t_graphic	*graphics;

	rv = 0;
	graphics = get_graph();
	if (ft_strlen(line) < 3)
		return (1);
	if ((line[0] == 'N' && line[1] == 'O') && ft_isspace(line[2]))
		rv = index_path(line, &graphics->north);
	else if ((line[0] == 'S' && line[1] == 'O') && ft_isspace(line[2]))
		rv = index_path(line, &graphics->south);
	else if ((line[0] == 'W' && line[1] == 'E') && ft_isspace(line[2]))
		rv = index_path(line, &graphics->west);
	else if ((line[0] == 'E' && line[1] == 'A') && ft_isspace(line[2]))
		rv = index_path(line, &graphics->east);
	else
		return (1);
	return (rv);
}

int	index_color(char *line, t_color *color)
{
	int		value;
	int		i;
	char	**result;

	while (ft_isspace(*line))
		*line++;
	result = ft_split(line, ',');
	if (ft_len_arr(result) != 3)
		ft_free_arr(result);
	if (!result)
		return (1);
	i = 0;
	while (i < 3)
	{
		value = ft_atoi(result[i]);
		
	}
	return (0);
}

int	is_color(char *line)
{
	int			rv;
	t_graphic	*graphics;

	rv = 0;
	graphics = get_graph();
	if (ft_strlen(line) < 2)
		return (1);
	if (line[0] == 'F' && ft_isspace(line[1]))
		rv = index_color(line, graphics->floor);
	else if (line[0] == 'C' && ft_isspace(line[1]))
		rv = index_color(line, graphics->ceiling);
	else
		return (1);
	return (rv);
}

int	valid_config(char *path)
{
	if (base_tests(path))
		return (1);
	return (0);
}

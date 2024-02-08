/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:11:04 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/08 09:00:13 by lvincent         ###   ########.fr       */
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
		return (1);
	}
	if (not_valid_file(path))
	{
		ft_perror(path);
		return (1);
	}
	*storage = path;
	return (0);
}

int	is_path(char *line)
{
	int	rv;


	rv = 0;
	if (ft_strlen(line) < 3)
		return (1);
	if ((line[0] == 'N' && line[1] == 'O') && ft_isspace(line[2]))
		rv = index_path(line, 1);
	else if ((line[0] == 'S' && line[1] == 'O') && ft_isspace(line[2]))
		rv = index_path(line, 2);
	else if ((line[0] == 'W' && line[1] == 'E') && ft_isspace(line[2]))
		rv = index_path(line, 3);
	else if ((line[0] == 'E' && line[1] == 'A') && ft_isspace(line[2]))
		rv = index_path(line, 4);
	else
		return (1);
	return (rv);
}

int	valid_config(char *path)
{

	if (base_tests(path))
		return (1);
	
}
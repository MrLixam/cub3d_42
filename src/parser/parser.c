/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:43:10 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/20 12:53:19 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	name_parser(char *name)
{
	char	*extension;

	if (ft_strlen(name) <= 4)
		return (1);
	extension = &name[ft_strlen(name) - 4];
	if (!ft_strncmp(extension, ".cub", 4))
		return (0);
	return (1);
}

int	is_valid_file(char *name)
{
	int	fd;

	fd = open(name, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

int	parse_ext(char *name)
{
	int	i;

	i = is_valid_file(name);
	if (i == 1)
		ft_error(name, "is a directory");
	if (i == -1)
	{
		if (errno == EACCES)
			ft_error(name, "file does not exist");
		else if (errno == EACCES)
			ft_error(name, "permission denied");
	}
	if (i)
		return (1);
	i = name_parser(name);
	if (i)
		ft_error(name,
			"invalid file name: must be a .cub and name musn't be empty");
	if (i)
		return (1);
	return (0);
}

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
			if (is_in_set("0NSWE", game.map[y][x]) && check_tile(game, y, x))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

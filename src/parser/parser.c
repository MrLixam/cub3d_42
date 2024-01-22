/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:43:10 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/22 17:47:27 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	ext_parser(char *name, char *ext)
{
	char	*extension;
	int		len;

	len = ft_strlen(ext);
	if (ft_strlen(name) <= len)
		return (1);
	extension = &name[ft_strlen(name) - len];
	if (!ft_strncmp(extension, ext, len))
		return (0);
	return (1);
}

int	not_valid_file(char *name)
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

int	parse_extern(char *name)
{
	if (not_valid_file(name) == 1)
		ft_error(name, "is a directory");
	if (not_valid_file(name) == -1)
	{
		if (errno == ENOENT)
			ft_error(name, "file does not exist");
		else if (errno == EACCES)
			ft_error(name, "permission denied");
	}
	if (not_valid_file(name))
		return (1);
	if (ext_parser(name, ".cub"))
		ft_error(name,
			"invalid file name: must be a .cub and name musn't be empty");
	if (ext_parser(name, ".cub"))
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

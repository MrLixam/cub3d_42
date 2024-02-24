/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_index_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:33:52 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 15:55:41 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	len_wspace(char *line)
{
	size_t	i;

	i = ft_strlen(line) - 1;
	while (is_wspace(line[i]))
		i--;
	return (i + 1);
}

int	index_path(char *line, char **storage)
{
	char	*path;
	int		start;

	start = 2;
	while (ft_isspace(line[start]))
		start++;
	path = ft_substr(line, start, len_wspace(line) - start);
	if (!path)
		ft_error(NULL, "allocation error");
	if (!path)
		return (-1);
	if (not_valid_file(path))
	{
		free(path);
		return (-1);
	}
	if (name_parser(path, ".png"))
	{
		ft_error(path, "Invalid file type, use .png only");
		free(path);
		return (-1);
	}
	*storage = path;
	return (1);
}

static int	is_path(char *line)
{
	int			rv;
	t_graphic	*graphics;

	rv = 0;
	graphics = get_graph();
	if ((line[0] == 'N' && line[1] == 'O') && ft_isspace(line[2]))
		rv = index_path(line, &graphics->north);
	else if ((line[0] == 'S' && line[1] == 'O') && ft_isspace(line[2]))
		rv = index_path(line, &graphics->south);
	else if ((line[0] == 'W' && line[1] == 'E') && ft_isspace(line[2]))
		rv = index_path(line, &graphics->west);
	else if ((line[0] == 'E' && line[1] == 'A') && ft_isspace(line[2]))
		rv = index_path(line, &graphics->east);
	else
		return (0);
	return (rv);
}

int	get_texture_paths(char **file, int max)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while ((file[i] && i < max) && res < 4)
	{
		j = is_path(file[i]);
		if (j == -1)
			return (-1);
		res += j;
		i++;
	}
	if (res != 4)
		return (-1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:33:52 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/13 20:49:10 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		return (-1);
	if (name_parser(path, ".xpm"))
	{
		ft_error(path, "Invalid file type, use .xpm only");
		free(path);
		return (-1);
	}
	if (not_valid_file(path))
	{
		ft_perror(path);
		free(path);
		return (-1);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_index_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:33:47 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 11:07:07 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	remove_wspace(char **array)
{
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while(is_wspace(array[i][j]))
			j++;
		buffer = ft_substr(array[i], j, len_wspace(array[i]) - j);
		if (!buffer)
			ft_free_arr(array);
		if (!buffer)
			return ;
		free(array[i]);
		array[i] = buffer;
		i++;
	}
}

static void	set_color(t_color *color, int index, int value)
{
	if (index == 0)
		color->red = value;
	else if (index == 1)
		color->green = value;
	else
		color->blue = value;
}

static int	color_check(char **result)
{
	int	i;
	int	val;

	if (ft_len_arr(result) != 3)
		return (1);
	i = 0;
	while (i < 3)
	{
		val = ft_atoi(result[i]);
		if (val < 0 || val > 255 || *atoi_error())
		{
			ft_error(NULL, "value out of range [0-255]");
			return (1);
		}
		if (*atoi_error())
		{
			ft_error(NULL, "invalid formatting");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	index_color(char *line, t_color *color)
{
	int		i;
	char	**result;

	line++;
	while (ft_isspace(*line))
		line++;
	result = ft_split(line, ',');
	if (!result)
		return (-1);
	remove_wspace(result);
	if (color_check(result))
	{
		ft_free_arr(result);
		return (-1);
	}
	i = 0;
	while (i < 3)
	{
		set_color(color, i, ft_atoi(result[i]));
		i++;
	}
	ft_free_arr(result);
	return (0);
}

int	is_color(char *line)
{
	int			rv;
	t_graphic	*graphics;

	if (!line)
		return (1);
	if (line[0] == 0)
		return (0);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:11:04 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 09:19:01 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	base_tests(char **file, char *path)
{
	if (!file || file[0] == NULL)
	{
		ft_error(path, "file is empty");
		if (file)
			ft_free_arr(file);
		return (1);
	}
	return (0);
}

static int	no_empty_line(char **file, int i)
{
	if (!file[i])
	{
		ft_error(NULL, "there is no map");
		return (0);
	}
	while (file[i])
	{
		if (file[i][0] == 0)
		{
			ft_error(NULL, "there are empty lines in map definition");
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid_config(char *path)
{
	char	**file;
	int		ret[2];
	int		i;

	i = 0;
	file = gnl_full_file(path);
	if (base_tests(file, path))
		return (1);
	while (file[i])
	{
		ret[0] = is_path(file[i]);
		ret[1] = is_color(file[i]);
		if (ret[0] == -1 || ret[1] == -1)
			ft_free_arr(file);
		if (ret[0] == -1 || ret[1] == -1)
			return (1);
		if (ret[0] == 1 && ret[1] == 1)
			break ;
		i++;
	}
	if (no_empty_line(file, i))
		get_graph()->map = normalize_map(file, i);
	ft_free_arr(file);
	return (0);
}

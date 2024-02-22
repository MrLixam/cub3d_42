/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:11:04 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/22 04:10:21 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	base_tests(char **file, char *path)
{
	if (file[0] == NULL)
	{
		ft_error(path, "file is empty");
		ft_free_arr(file);
		return (1);
	}
	return (0);
}

int	valid_config(char *path)
{
	char	**file;
	int		ret[2];
	int		i;

	i = 0;
	file = gnl_full_file(path);
	if (!file || base_tests(file, path))
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
	get_graph()->map = normalize_map(file, i);
	ft_free_arr(file);
	return (0);
}

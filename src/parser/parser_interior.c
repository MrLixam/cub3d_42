/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:11:04 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/13 21:00:18 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	valid_config(char *path)
{
	char **file;
	int		path_ret;
	int		color_ret;
	int 	i;

	if (base_tests(path))
		return (1);
	i = 0;
	file = gnl_full_file(path);
	if (!file)
		return (1);
	while (file[i])
	{
		path_ret = is_path(file[i]);
		color_ret = is_color(file[i]);
		if (path_ret == -1 || color_ret == -1)
			ft_free_arr(file);
		if (path_ret == -1 || color_ret == -1)
			return (1);
		if (path_ret == 1 && color_ret == 1)
			break ;
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:11:04 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/19 18:43:19 by lvincent         ###   ########.fr       */
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
	int		ret[2];
	int 	i;

	if (base_tests(path))
		return (1);
	i = 0;
	file = gnl_full_file(path);
	if (!file)
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

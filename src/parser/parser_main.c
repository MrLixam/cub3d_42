/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:32:59 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 15:54:45 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	valid_config(char *path)
{
	char	**file;
	int		i;
	int		max;

	i = 0;
	file = gnl_full_file(path);
	max = base_tests(file, path);
	if (!max)
		if (file)
			ft_free_arr(file);
	if (!max)
		return (1);
	i = get_texture_paths(file, max);
	if (i != -1)
		i = get_colors_path(file, max);
	if (i != -1 && no_empty_line(file, max))
		get_graph()->map = normalize_map(file, max);
	ft_free_arr(file);
	return (i == -1);
}

static int	parser_file(char *path)
{
	if (parse_extern(path, ".cub"))
		return (1);
	init_graph();
	if (check_graph())
	{
		reset_graph();
		ft_error(NULL, "struct init failed");
		return (1);
	}
	if (valid_config(path) || get_graph()->map == NULL)
	{
		reset_graph();
		return (1);
	}
	if (parse_map(get_graph()->map))
	{
		reset_graph();
		return (1);
	}
	return (0);
}

void	parser(char *path)
{
	int	error_val;

	error_val = parser_file(path);
	if (error_val)
		gnl_release();
	if (error_val)
		exit(1);
	error_val = check_images();
	if (error_val)
	{
		gnl_release();
		reset_graph();
		exit(1);
	}
	return ;
}

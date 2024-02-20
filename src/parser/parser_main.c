/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:32:59 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/21 00:29:33 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parser_file(char *path)
{
	if (parse_extern(path, ".cub"))
		return (1);
	init_graph();
	if (valid_config(path))
	{
		reset_graph();
		return (1);
	}
	if (get_graph()->map == NULL)
	{
		ft_error(path, "no map in the configuration");
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

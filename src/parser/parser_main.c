/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:32:59 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/22 16:57:18 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parser_file(char *path)
{
	if (parse_extern(path, ".cub"))
		return (1);
	init_graph();
	if  (check_graph())
	{
		reset_graph();
		ft_error(NULL, "struct init failed");
		return(1);
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

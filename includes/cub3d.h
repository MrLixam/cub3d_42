/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:02:09 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/19 12:37:24 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "utils.h"
# include "parser.h"
# include "render.h"
# include "../MacroLibX/includes/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>

/*
	struct containing data passed by the parsing
	contains:
	-the parsed map
	-textures -> path to the texture currently, might replace by the opened texture directly, any way, this input will be parsed
*/

typedef struct s_data
{
	char	**map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;

}	t_data;


#endif
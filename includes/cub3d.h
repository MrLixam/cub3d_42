/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:02:09 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/01 22:09:34 by lvincent         ###   ########.fr       */
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
# include <stdio.h>

typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_img
{
	void	*img;
	t_data	data;
	int		width;
	int		height;
}			t_img;

typedef struct s_texture
{
	t_img	tile;
	t_img	player;
	t_img	collectible;
}			t_txt;

typedef struct s_playable_character
{
	size_t	x;
	size_t	y;
	int		move;
	int		collected;
	char	footprint;
}			t_pc;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	size_t		map_width;
	size_t		map_height;
	t_img		frame;
	t_txt		texture;
	t_pc		player;
	int			collectible;
}			t_game;


#endif
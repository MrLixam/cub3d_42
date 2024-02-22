/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:52:56 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/21 19:21:25 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}			t_color;

typedef struct s_graphic_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_color	*floor;
	t_color	*ceiling;
	char	**map;
}			t_graphic;

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
	int		X;
	int		Y;
	float	view;
}			t_pc;

typedef struct s_raycast_line
{
	float	ray;
	float	ray_dist_x;
	float	ray_dist_y;
	float	side_dist_x;
	float	side_dist_y;
}			t_line;

typedef struct s_raycast
{
	float	ray;
	t_line	*horizontal;
	t_line	*vertical;
	float	dist;
}			t_ray;

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
	t_ray		raycast;
}			t_game;

#endif

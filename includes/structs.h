/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:52:56 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 05:05:23 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
	int		hex;
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
	size_t	spawn_x;
	size_t	spawn_y;
}			t_graphic;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}			t_img;

typedef struct s_texture
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	t_color	*ceiling;
	t_color	*floor;
}			t_txt;

typedef struct s_playable_character
{
	size_t	x;
	size_t	y;
	float	sub_x;
	float	sub_y;
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
	int		side;
	float	dist;
	float	wall_hit;
}			t_ray;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	size_t	map_width;
	size_t	map_height;
	t_img	frame;
	t_txt	texture;
	t_pc	player;
	t_ray	raycast;
	bool	events[6];
}			t_game;

#endif

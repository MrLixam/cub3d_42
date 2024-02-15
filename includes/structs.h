/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:52:56 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/15 21:07:40 by lvincent         ###   ########.fr       */
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
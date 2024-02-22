/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_to_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:41:18 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/22 18:12:21 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_orientation(t_game *game)
{
	char orientation;

	orientation = game->map[game->player.y][game->player.x];
	if (orientation == 'N')
		game->player.view = PI;
	if (orientation == 'S')
		game->player.view = 3 * PI;
	if (orientation == 'E')
		game->player.view = 0;
	if (orientation == 'W')
		game->player.view = 2 * PI;
}

t_game	*set_game(void *mlx)
{
	t_game		*game;
	t_graphic	*graphics;

	graphics = get_graph();
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx;
	game->map = graphics->map;
	graphics->map = NULL;
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = ft_len_arr(game->map);
	game->player.x = graphics->spawn_x;
	game->player.y = graphics->spawn_y;
	game->player.Y = RES / 2;
	game->player.X = RES / 2;
	set_textures(graphics, game);
	reset_graph();
	return (game);
}

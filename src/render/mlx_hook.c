/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:23 by r                 #+#    #+#             */
/*   Updated: 2024/02/24 07:12:58 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	update_position_x(t_game *game, float x)
{
	float	new_sub_x;
	int		tile_shift;

	new_sub_x = game->player.sub_x + 4 * x;
	tile_shift = 0;
	if (new_sub_x > RES)
	{
		tile_shift = 1;
		new_sub_x = fmod(new_sub_x, RES);
	}
	else if (new_sub_x < 0)
	{
		tile_shift = -1;
		new_sub_x = RES - fmod(-new_sub_x, RES);
	}
	if (game->map[game->player.y][game->player.x + tile_shift] == '1')
		return ;
	game->player.sub_x = new_sub_x;
	game->player.x += tile_shift;
}

static void	update_position_y(t_game *game, float y)
{
	float	new_sub_y;
	int		tile_shift;

	new_sub_y = game->player.sub_y + 4 * y;
	tile_shift = 0;
	if (new_sub_y > RES)
	{
		tile_shift = 1;
		new_sub_y = fmod(new_sub_y, RES);
	}
	else if (new_sub_y < 0)
	{
		tile_shift = -1;
		new_sub_y = RES - fmod(-new_sub_y, RES);
	}
	if (game->map[game->player.y + tile_shift][game->player.x] == '1')
		return ;
	game->player.sub_y = new_sub_y;
	game->player.y += tile_shift;
}

/*	printf("y : %f\n", game->player.sub_y + 4 * y);
	if (game->player.sub_y + 4 * y > RES)
	{
		printf("Y TRUE UP\n");
		if (game->map[game->player.y + 1][game->player.x] != '1')
		{
			game->player.sub_y = 2;
			game->player.y++;
		}
	}
	else if (game->player.sub_y + 4 * y < 1)
	{
		printf("Y TRUE DOWN\n");
		if (game->map[game->player.y - 1][game->player.x] != '1')
		{
			game->player.sub_y = RES - 1;
			game->player.y--;
		}
	}
	else
		game->player.sub_y += 4 * y;*/

static int	player_action(t_game *game, float x, float y)
{
	update_position_x(game, x);
	update_position_y(game, y);
	return (0);
}

static int	player_rotation(t_game *game, int direction)
{
	if (direction == 1)
	{
		game->player.view += 0.05;
		if (game->player.view > 2 * PI)
			game->player.view -= 2 * PI;
	}
	if (direction == 2)
	{
		game->player.view -= 0.05;
		if (game->player.view < 0)
			game->player.view += 2 * PI;
	}
	return (0);
}

int	actions(void *param)
{
	t_game *game;
	float	view;
	bool	*events;

	game = (t_game *)param;
	view = game->player.view;
	events = game->events;
	if (game->events[0])
		player_action(game, cos(view), sin(view));
	if (game->events[1])
		player_action(game, cos(view - P2), sin(view - P2));
	if (game->events[2])
		player_action(game, -cos(view), -sin(view));
	if (game->events[3])
		player_action(game, cos(view + P2), sin(view + P2));
	if (game->events[4])
		player_rotation(game, 2);
	if (game->events[5])
		player_rotation(game, 1);
	if (events[0] || events[1] || events[2] || events[3] || events[4] || events[5])
		raycast(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:23 by r                 #+#    #+#             */
/*   Updated: 2024/02/24 06:24:42 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	update_position_x(t_game *game, float x)
{
	if (game->player.sub_x + 4 * x > RES)
	{
		if (game->map[game->player.y][game->player.x + 1] != '1')
		{
			game->player.sub_x = 0;
			game->player.x++;
		}
		else
			printf("Wall!");
	}
	else if (game->player.sub_x + 4 * x < 1)
	{
		if (game->map[game->player.y][game->player.x - 1] != '1')
		{
			game->player.sub_x = RES;
			game->player.x--;
		}
	}
	else
		game->player.sub_x += 4 * x;
}

static void	update_position_y(t_game *game, float y)
{
	if (game->player.sub_y + 4 * y > RES)
	{
		if (game->map[game->player.y + 1][game->player.x] != '1')
		{
			game->player.sub_y = 0;
			game->player.y++;
		}
	}
	else if (game->player.sub_y + 4 * y < 1)
	{
		if (game->map[game->player.y - 1][game->player.x] != '1')
		{
			game->player.sub_y = RES;
			game->player.y--;
		}
	}
	else
		game->player.sub_y += 4 * y;
}

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

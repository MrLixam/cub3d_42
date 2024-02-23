/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:23 by r                 #+#    #+#             */
/*   Updated: 2024/02/23 20:22:17 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	update_position_x(t_game *game, float x)
{
	if (game->player.sub_x + 4 * x > RES)
	{
		if (game->map[game->player.y][game->player.x + 1] != '1')
		{
			game->player.sub_x = 1;
			game->player.x++;
		}
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
			game->player.sub_y = 1;
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
	raycast(game);
	return (0);
}

static int	player_rotation(t_game *game, int direction)
{
	if (direction == 1)
	{
		game->player.view += 0.1;
		if (game->player.view > 2 * PI)
			game->player.view -= 2 * PI;
	}
	if (direction == 2)
	{
		game->player.view -= 0.1;
		if (game->player.view < 0)
			game->player.view += 2 * PI;
	}
	raycast(game);
	return (0);
}

int	hook_handler(int keycode, void *game)
{
	t_game	*tmp;
	float	view;

	tmp = (t_game *)game;
	view = tmp->player.view;
	if (keycode == 41 || keycode == 0)
		mlx_loop_end(tmp->mlx);
	if (keycode == 26)
		player_action(tmp, cos(view), sin(view));
	if (keycode == 4)
		player_action(tmp, cos(view - P2), sin(view - P2));
	if (keycode == 22)
		player_action(tmp, -cos(view), -sin(view));
	if (keycode == 7)
		player_action(tmp, cos(view + P2), sin(view + P2));
	if (keycode == 80)
		player_rotation(tmp, 2);
	if (keycode == 79)
		player_rotation(tmp, 1);
	return (0);
}

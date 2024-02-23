/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:23 by r                 #+#    #+#             */
/*   Updated: 2024/02/23 19:55:40 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
/*
static void render_player(t_game game, t_pc pc)
{
    int x;
    int y;
	int	px;
	int	py;

	px = (pc.x * RES) + pc.sub_x;
	py = (pc.y * RES) + pc.sub_y;
    x = -1;
    while (++x < 16)
    {
        y = -1;
        while (++y < 16)
        {
			mlx_pixel_put(game.mlx, game.win,1100+ x + px , y + py, 0xC5BCAA);
        }
    }
	x = -1;
	while (++x < 32)
	{
		mlx_pixel_put(game.mlx, game.win,1100+ 8 + px + (-x * cos(pc.view)), 8 + py + (-x * sin(pc.view)), 0xC5BCAA);
	}
}
*/
void update_position_x(t_game *game, float x)
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

void update_position_y(t_game *game, float y)
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

int	player_action(t_game *game, float x, float y)
{
	update_position_x(game, x);
	update_position_y(game, y);
//	render_map(game, game->map);
//	render_player(*game, game->player);
	raycast(game);
	return (0);
}

int	player_rotation(t_game *game, int direction)
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
//	render_map(game, game->map);
//	render_player(*game, game->player);
	raycast(game);
	return (0);
}

int hook_handler(int keycode, void *game)
{
	t_game *tmp;

	tmp = (t_game *)game;
	if (keycode == 41 || keycode == 0)
		mlx_loop_end(tmp->mlx);
	if (keycode == 26)//w
		player_action(tmp, cos(tmp->player.view), sin(tmp->player.view));
	if (keycode == 4)//a
		player_action(tmp, cos(tmp->player.view - P2), sin(tmp->player.view - P2));
	if (keycode == 22)//s
		player_action(tmp, -cos(tmp->player.view), -sin(tmp->player.view));
	if (keycode == 7)//d
		player_action(tmp, cos(tmp->player.view + P2), sin(tmp->player.view + P2));
	if (keycode == 80)//left
		player_rotation(tmp, 2);
	if (keycode == 79)//right
		player_rotation(tmp, 1);
	return (0);
}

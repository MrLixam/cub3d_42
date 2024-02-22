/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r <marvin@42.fr>                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:23 by r                 #+#    #+#             */
/*   Updated: 2024/02/22 12:40:42 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static void render_player(t_game game, t_pc pc)
{
    int x;
    int y;
	int	px;
	int	py;

	px = (pc.x * RES) + pc.X;
	py = (pc.y * RES) + pc.Y;
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
		mlx_pixel_put(game.mlx, game.win,1100+ 8 + px + (x * cos(pc.view)), 8 + py + (x * sin(pc.view)), 0xC5BCAA);
	}
}

int	player_action(t_game *game, int i)
{
	if (i == 4)
	{
		game->player.X += 4;
		if (game->player.X > RES)
		{
			game->player.X = 1;
			game->player.x++;
		}
	}
	if (i == 1)
	{
		game->player.Y -= 4;
		if (game->player.Y < 1)
		{
			game->player.Y = RES;
			game->player.y--;
		}
	}
	if (i == 2)
	{
		game->player.X -= 4;
		if (game->player.X < 1)
		{
			game->player.X = RES;
			game->player.x--;
		}
	}
	if (i == 3)
	{
		game->player.Y += 4;
		if (game->player.Y > RES)
		{
			game->player.Y = 1;
			game->player.y++;
		}
	}
	render_map(game, game->map);
	render_player(*game, game->player);
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
	render_map(game, game->map);
	render_player(*game, game->player);
	raycast(game);
	return (0);
}

int hook_handler(int keycode, void *game)
{
	if (keycode == 41 || keycode == 0)
		mlx_loop_end(((t_game *)game)->mlx);
	if (keycode == 26)//w
		player_action((t_game *)game, 1);
	if (keycode == 4)//a
		player_action((t_game *)game, 2);
	if (keycode == 22)//s
		player_action((t_game *)game, 3);
	if (keycode == 7)//d
		player_action((t_game *)game, 4);
	if (keycode == 80)//left
		player_rotation((t_game *)game, 2);
	if (keycode == 79)//right
		player_rotation((t_game *)game, 1);
	return (0);
}

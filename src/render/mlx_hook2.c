/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:47:07 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 09:57:34 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	hook_window(int keycode, void *game)
{
	t_game	*tmp;

	tmp = (t_game *)game;
	if (keycode == 0)
		mlx_loop_end(tmp->mlx);
	return (0);
}

int	keyboard_engage(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 41)
		mlx_loop_end(game->mlx);
	if (keycode == 26)
		game->events[0] = 1;
	if (keycode == 4)
		game->events[1] = 1;
	if (keycode == 22)
		game->events[2] = 1;
	if (keycode == 7)
		game->events[3] = 1;
	if (keycode == 80)
		game->events[4] = 1;
	if (keycode == 79)
		game->events[5] = 1;
	return (0);
}

int	keyboard_disengage(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 26)
		game->events[0] = 0;
	if (keycode == 4)
		game->events[1] = 0;
	if (keycode == 22)
		game->events[2] = 0;
	if (keycode == 7)
		game->events[3] = 0;
	if (keycode == 80)
		game->events[4] = 0;
	if (keycode == 79)
		game->events[5] = 0;
	return (0);
}

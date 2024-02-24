/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:38:55 by r                 #+#    #+#             */
/*   Updated: 2024/02/24 00:40:46 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	mlx_end(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	destroy_game(game);
	return (1);
}

static int	mlx_start(t_game *game)
{
	game->win = mlx_new_window(game->mlx, 1080, 720, "cub3d");
	if (game->win == NULL)
	{
		free(game->mlx);
		return (1);
	}
	return (0);
}

int	cub3d(t_game *game)
{
	if (mlx_start(game))
		return (1);
	mlx_on_event(game->mlx, game->win, MLX_KEYDOWN, hook_keyboard, game);
	mlx_on_event(game->mlx, game->win, MLX_WINDOW_EVENT, hook_window, game);
	raycast(game);
	mlx_loop(game->mlx);
	mlx_end(game);
	return (0);
}

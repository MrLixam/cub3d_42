/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:38:55 by r                 #+#    #+#             */
/*   Updated: 2024/02/23 20:21:03 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	mlx_end(t_game *game)
{
	ft_free_arr(game->map);
	mlx_destroy_image(game->mlx, game->frame.img);
	mlx_destroy_window(game->mlx, game->win);
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
	game->frame.img = mlx_new_image(game->mlx, 1080, 720);
	if (game->frame.img == NULL)
	{
		mlx_end(game);
		return (1);
	}
	return (0);
}

int	cub3d(t_game *game)
{
	if (mlx_start(game))
		return (1);
	mlx_on_event(game->mlx, game->win, MLX_KEYDOWN, hook_handler, game);
	mlx_on_event(game->mlx, game->win, MLX_WINDOW_EVENT, hook_handler, game);
	mlx_loop(game->mlx);
	mlx_end(game);
	return (0);
}

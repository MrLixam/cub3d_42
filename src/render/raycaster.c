/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:49:08 by r                 #+#    #+#             */
/*   Updated: 2024/02/24 11:43:39 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	trigo_circle(float *value)
{
	if (*value < 0)
		*value += 2 * PI;
	if (*value > 2 * PI)
		*value -= 2 * PI;
}

static int	get_ray(t_game *game)
{
	game->raycast.horizontal = ft_calloc(1, sizeof(t_line));
	if (game->raycast.horizontal == NULL)
		return (1);
	game->raycast.vertical = ft_calloc(1, sizeof(t_line));
	if (game->raycast.vertical == NULL)
	{
		free(game->raycast.horizontal);
		return (1);
	}
	horizontal_line(game, game->raycast.horizontal);
	vertical_line(game, game->raycast.vertical);
	shortest_line(game);
	free(game->raycast.horizontal);
	free(game->raycast.vertical);
	return (0);
}

int	raycast(t_game *game)
{
	int		i;
	float	ca;

	i = -1;
	game->raycast.ray = game->player.view - DEG * 30;
	while (++i < 1080)
	{
		if (get_ray(game))
			return (1);
		trigo_circle(&game->raycast.ray);
		ca = game->player.view - game->raycast.ray;
		trigo_circle(&ca);
		game->raycast.dist = game->raycast.dist * cos(ca);
		draw_line(game, i, game->raycast);
		game->raycast.ray += DEG / 18;
	}
	return (0);
}

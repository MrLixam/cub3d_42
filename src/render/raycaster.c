/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:49:08 by r                 #+#    #+#             */
/*   Updated: 2024/02/22 18:41:09 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	horizontal_line(t_game *game, t_line *hor)
{
	float	atan;
	int		px;
	int		py;

	px = game->player.x * RES + game->player.sub_x;
	py = game->player.y * RES + game->player.sub_y;
	atan = -1 / tan(game->raycast.ray);
	if (game->raycast.ray > PI)
	{
		hor->ray_dist_y = (((int)py / RES) * RES) - 0.0001;
		hor->side_dist_y = -RES;
	}
	if (game->raycast.ray < PI)
	{
		hor->ray_dist_y = (((int)py / RES) * RES) + RES;
		hor->side_dist_y = RES;
	}
	hor->ray_dist_x = (py - hor->ray_dist_y) * atan + px;
	hor->side_dist_x = -hor->side_dist_y * atan;
	if (game->raycast.ray == PI || game->raycast.ray == 0)
	{
		hor->ray_dist_y = py;
		hor->ray_dist_x = px;
	}
}

void	vertical_line(t_game *game, t_line *ver)
{
	float	ntan;
	int		px;
	int		py;

	px = game->player.x * RES + game->player.sub_x;
	py = game->player.y * RES + game->player.sub_y;
	ntan = -tan(game->raycast.ray);
	if (game->raycast.ray > P2 && game->raycast.ray < P3)
	{
		ver->ray_dist_x = (((int)px / RES) * RES) - 0.0001;
		ver->side_dist_x = -RES;
	}
	if (game->raycast.ray < P2 || game->raycast.ray > P3)
	{
		ver->ray_dist_x = (((int)px / RES) * RES) + RES;
		ver->side_dist_x = RES;
	}
	ver->ray_dist_y = (px - ver->ray_dist_x) * ntan + py;
	ver->side_dist_y = -ver->side_dist_x * ntan;
	if (game->raycast.ray == PI || game->raycast.ray == 0)
	{
		ver->ray_dist_y = py;
		ver->ray_dist_x = px;
	}
}

float	distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

float	wall_hit(t_game *game, t_line *line)
{
	int	mx;
	int	my;
	int	dof;
	int	px;
	int	py;

	px = game->player.x * RES + game->player.sub_x;
	py = game->player.y * RES + game->player.sub_y;
	dof = 0;
	while (dof < 8)
	{
		mx = (int)line->ray_dist_x / RES;
		my = (int)line->ray_dist_y / RES;
		if (mx >= 0 && mx < (int)game->map_width && my >= 0 && \
			my < (int)game->map_height && game->map[my][mx] == '1')
			break ;
		line->ray_dist_x += line->side_dist_x;
		line->ray_dist_y += line->side_dist_y;
		dof++;
	}
	return (distance(px, py, line->ray_dist_x, line->ray_dist_y));
}

void	shortest_line(t_game *game)
{
	float	dist_h;
	float	dist_v;

	dist_h = wall_hit(game, game->raycast.horizontal);
	dist_v = wall_hit(game, game->raycast.vertical);
	if (dist_v <= 0 || ( dist_h >= 0 && dist_h < dist_v))
		game->raycast.dist = dist_h;
	if (dist_h <= 0 || ( dist_v >= 0 && dist_v < dist_h))
		game->raycast.dist = dist_v;
}

int	raycast(t_game *game)
{
	int	i;
	int	x;
	int	px;
	int	py;
	float	ca;

	px = game->player.x * RES + game->player.sub_x;
	py = game->player.y * RES + game->player.sub_y;

	i = -1;
	game->raycast.ray = game->player.view - DEG * 30;
	while (++i < 60)
	{
		if (game->raycast.ray < 0)
			game->raycast.ray += 2 * PI;
		if (game->raycast.ray > 2 * PI)
			game->raycast.ray -= 2 * PI;
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
		ca = game->player.view - game->raycast.ray;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		game->raycast.dist = game->raycast.dist * cos(ca);
		draw_line(game, i, game->raycast.dist);
		x = -1;
    	while (++x < (int)game->raycast.dist)
    	{   
    	    mlx_pixel_put(game->mlx, game->win,1100+ 8 + px + (x * cos(game->raycast.ray)), 8 + py + (x * sin(game->raycast.ray)), 0xC5BCFA);
    	}
		game->raycast.ray += DEG;
	}
	return (0);
}

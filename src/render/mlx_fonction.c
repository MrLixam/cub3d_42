/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:39:41 by r                 #+#    #+#             */
/*   Updated: 2024/02/23 20:22:20 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_texture_pixel(t_game *game, t_img texture, int lineh, int j)
{
	double		step;
	int			i;
	int			pixel;

	step = 1.0 * texture.height / lineh;
	i = fmod(game->raycast.wall_hit, texture.width);
	pixel = mlx_get_image_pixel(game->mlx, texture.img, i, j * step);
	return (pixel);
}


static void	wall_texture(t_game *game, t_ray ray, int i, int j, int lineh)
{
	int	pixel;
	int lineo;

	lineo = 360 - lineh / 2;
	if (ray.side == 1)
		pixel = get_texture_pixel(game, game->texture.south, lineh, j - lineo);
	else if (ray.side == 2)
		pixel = get_texture_pixel(game, game->texture.east, lineh, j - lineo);
	else if (ray.side == 3)
		pixel = get_texture_pixel(game, game->texture.north, lineh, j - lineo);
	else
		pixel = get_texture_pixel(game, game->texture.west, lineh, j - lineo);
    mlx_set_image_pixel(game->mlx, game->frame.img, i, j, pixel);
}

void	draw_line(t_game *game, int deg, t_ray ray)
{
	int	i;
	int	j;
	int	lineh;
	int	lineo;

	lineh = (RES * 720) / ray.dist;
	lineo = 360 - lineh / 2;
	i = -1;
	while (++i < 1080 / 360)
	{
		j = -1;
		while (++j < 720)
		{
			if (j < lineo)
    			mlx_set_image_pixel(game->mlx, game->frame.img, i + (3 * deg), j,\
						game->texture.ceiling->hex);
			else if (j > lineo && j < lineh + lineo)
				wall_texture(game, ray, i + (3 * deg), j, lineh);
			else
    			mlx_set_image_pixel(game->mlx, game->frame.img, i + (3 * deg), j,\
						game->texture.floor->hex);
		}
	}
	mlx_put_image_to_window(game->mlx,game->win, game->frame.img, 0, 0);
}

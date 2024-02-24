/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:39:41 by r                 #+#    #+#             */
/*   Updated: 2024/02/24 11:29:10 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_texture_pixel(t_game *game, t_img texture, int lineh, int j)
{
	double		step;
	int			colors[4];
	int			tex_x;
	int			tex_y;
	int			pixel;

	step = 1.0 * texture.height / lineh;
	if (game->raycast.side > 2)
		tex_x = fmod(game->raycast.wall_hit \
			* texture.width / RES, texture.width);
	else
		tex_x = texture.width - fmod(game->raycast.wall_hit \
			* texture.width / RES, texture.width);
	tex_y = (int)(j * step) % texture.height;
	pixel = mlx_get_image_pixel(game->mlx, texture.img, tex_x, tex_y);
	colors[0] = get_a(pixel);
	colors[1] = get_r(pixel);
	colors[2] = get_g(pixel);
	colors[3] = get_b(pixel);
	return (get_argb(colors[0], colors[1], colors[2], colors[3]));
}

static void	wall_texture(t_game *game, int i, int j, int lineh)
{
	int	pixel;
	int	lineo;

	lineo = 360 - lineh / 2;
	if (game->raycast.side == 1)
		pixel = get_texture_pixel(game, game->texture.south, \
			lineh, (j - lineo));
	else if (game->raycast.side == 2)
		pixel = get_texture_pixel(game, game->texture.west, \
			lineh, (j - lineo));
	else if (game->raycast.side == 3)
		pixel = get_texture_pixel(game, game->texture.north, \
			lineh, j - lineo);
	else
		pixel = get_texture_pixel(game, game->texture.east, \
			lineh, j - lineo);
	mlx_pixel_put(game->mlx, game->win, i, j, pixel);
}

void	draw_line(t_game *game, int deg, t_ray ray)
{
	int	j;
	int	lineh;
	int	lineo;

	lineh = (RES * 720) / ray.dist;
	lineo = 360 - lineh / 2;
	j = -1;
	while (++j < 720)
	{
		if (j <= lineo)
			mlx_pixel_put(game->mlx, game->win, deg, j, \
				game->texture.ceiling->hex);
		else if (j > lineo && j < lineh + lineo)
			wall_texture(game, deg, j, lineh);
		else
			mlx_pixel_put(game->mlx, game->win, deg, j, \
				game->texture.floor->hex);
	}
}

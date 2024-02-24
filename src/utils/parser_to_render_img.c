/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_to_render_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:02:59 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 02:08:44 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_game(t_game *game)
{
	ft_free_arr(game->map);
	if (game->texture.floor)
		free(game->texture.floor);
	if (game->texture.ceiling)
		free(game->texture.ceiling);
	if (game->texture.north.img)
		mlx_destroy_image(game->mlx, game->texture.north.img);
	if (game->texture.south.img)
		mlx_destroy_image(game->mlx, game->texture.south.img);
	if (game->texture.west.img)
		mlx_destroy_image(game->mlx, game->texture.west.img);
	if (game->texture.east.img)
		mlx_destroy_image(game->mlx, game->texture.east.img);
	mlx_destroy_display(game->mlx);
	free(game);
}

static void	check_img(t_game *game)
{
	int	i;

	i = 0;
	if (game->texture.north.img == NULL)
		i = 1;
	if (game->texture.south.img == NULL)
		i = 1;
	if (game->texture.west.img == NULL)
		i = 1;
	if (game->texture.east.img == NULL)
		i = 1;
	if (i)
	{
		ft_error(NULL, "error while setting images");
		destroy_game(game);
		reset_graph();
		exit(1);
	}
}

static void	set_img(t_img *image, char *path, void *mlx)
{
	if (path)
		image->img = mlx_png_file_to_image(mlx, path, &image->width,
				&image->height);
	else
	{
		image->img = mlx_new_image(mlx, 2, 2);
		image->height = 2;
		image->width = 2;
		if (image->img == NULL)
			return;
		mlx_set_image_pixel(mlx, image->img, 0, 0, 0xFFFF00FF);
		mlx_set_image_pixel(mlx, image->img, 1, 0, 0xFF000000);
		mlx_set_image_pixel(mlx, image->img, 0, 1, 0xFF000000);
		mlx_set_image_pixel(mlx, image->img, 1, 1, 0xFFFF00FF);
	}
}

void	set_textures(t_graphic *graphics, t_game *game)
{
	t_txt	*texture;

	texture = &game->texture;
	texture->floor = graphics->floor;
	texture->ceiling = graphics->ceiling;
	graphics->floor = NULL;
	graphics->ceiling = NULL;
	set_img(&texture->north, graphics->north, game->mlx);
	set_img(&texture->south, graphics->south, game->mlx);
	set_img(&texture->west, graphics->west, game->mlx);
	set_img(&texture->east, graphics->east, game->mlx);
	game->texture.ceiling->hex = get_argb(255, game->texture.ceiling->red, game->texture.ceiling->green, game->texture.ceiling->blue);
	game->texture.floor->hex = get_argb(255, game->texture.floor->red, game->texture.floor->green, game->texture.floor->blue);
	check_img(game);
}

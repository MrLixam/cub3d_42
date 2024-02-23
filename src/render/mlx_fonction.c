/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:39:41 by r                 #+#    #+#             */
/*   Updated: 2024/02/23 19:55:38 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int  mlx_end(t_game *game)
{
	ft_free_arr(game->map);
	mlx_destroy_image(game->mlx, game->frame.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	return (1);
}

static int  mlx_start(t_game *game)
{
	game->win = mlx_new_window(game->mlx, 1680, 720, "cub3d");
	if (game->win == NULL)
	{
		free(game->mlx);
		return (1);
	}
	game->frame.img = mlx_new_image(game->mlx, 1680, 720);
	if (game->frame.img == NULL)
	{
		mlx_end(game);
		return (1);
	}
	return (0);
}
/*
size_t	ft_tabstrlen(char **arg)
{
	size_t	i;

	i = 0;
	while (arg[i] != NULL)
		i++;
	return (i);
}

static void render_til(t_game game, int x_map, int y_map, int wall)
{
    int x;
    int y;

    x = -1;
    while (++x < RES)
    {
        y = -1;
        while (++y < RES)
        {
			if (x == RES - 1 || y == RES - 1)
				continue;
			else if (wall)
            	mlx_pixel_put(game.mlx, game.win,1100+ x + (x_map * RES), y + (y_map * RES), 0xFFFF00FF);
			else
            	mlx_pixel_put(game.mlx, game.win,1100+ x + (x_map * RES), y + (y_map * RES), 0xFF0000FF);
        }
    }
}
*/
int	get_texture_pixel(t_game *game, t_img texture, int lineh, int j)
{
	double		step;
	int			i;
	int			pixel;

	step = 1.0 * texture.height / lineh;
	i = fmod(game->raycast.wall_hit, texture.width);
	pixel = mlx_get_image_pixel(game->mlx, texture.img, i, j * step);
	return (pixel);
}


void	wall_texture(t_game *game, t_ray ray, int i, int j, int lineh)
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
    			mlx_set_image_pixel(game->mlx, game->frame.img, i + (3 * deg), j, game->texture.ceiling->hex);
			else if (j > lineo && j < lineh + lineo)
				wall_texture(game, ray, i + (3 * deg), j, lineh);
			else
    			mlx_set_image_pixel(game->mlx, game->frame.img, i + (3 * deg), j, game->texture.floor->hex);
		}
	}
	mlx_put_image_to_window(game->mlx,game->win, game->frame.img, 0, 0);
}
/*
void    render_map(t_game *game, char **map)
{
    int x;
    int y;

    y = -1;
    while (++y < (int)game->map_height)
    {
        x = -1;
        while (++x < (int)game->map_width)
            render_til(*game, x, y, map[y][x] - 48);
    }
	raycast(game);
}
*/
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

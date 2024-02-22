/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:39:41 by r                 #+#    #+#             */
/*   Updated: 2024/02/22 18:43:44 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

static int  mlx_end(t_game *game)
{
//	freetab(game->map);
	mlx_destroy_image(game->mlx, game->frame.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	return (1);
}

static int  mlx_start(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
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
/*	set_addr(&game->frame);
	if (game->frame.data.addr == NULL)
	{
		mlx_destroy_image(game->mlx, game->frame.img);
		mlx_end(game);
		return (1);
	}
*/	return (0);
}

size_t	ft_tabstrlen(char **arg)
{
	size_t	i;

	i = 0;
	while (arg[i] != NULL)
		i++;
	return (i);
}

void    my_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
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

void	draw_line(t_game *game, int deg, float dist)
{
	int	i;
	int	j;
	int	lineh;
	int	lineo;

	lineh = (RES * 720) / dist;
	lineo = 360 - lineh / 2;
	i = -1;
	while (++i < 1080 / 60)
	{
		j = -1;
		while (++j < 720)
		{
    		mlx_pixel_put(game->mlx, game->win, i+(18*deg), j, 0xFF0000FF);
			if (j > lineo && j < lineh + lineo)
    			mlx_pixel_put(game->mlx, game->win, i+(18*deg), j, 0xFFFF00FF);
		}
	}
}

void    render_map(t_game *game, char **map)
{
    int x;
    int y;

    y = -1;
    while (++y < 8/*(int)ft_tabstrlen(map)*/)
    {
        x = -1;
        while (++x < 8/*(int)ft_strlen(*map)*/)
            render_til(*game, x, y, map[y][x] - 48);
    }
	//mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	raycast(game);
}

int	cub3d(void)
{
	t_game	game;
	game.map = (char *[]){"11111111", "10000001", "10010001", "10010001", 
						  "10000001", "10000101", "10000001", "11111111"};
	game.map_width = 8;
	game.map_height = 8;
	game.player.x = 2;
	game.player.y = 2;
	game.player.sub_x = 40;
	game.player.sub_y = 10;
	game.player.view = 0;

	if (mlx_start(&game))
		return (1);
	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, hook_handler, &game);
	mlx_on_event(game.mlx, game.win, MLX_WINDOW_EVENT, hook_handler, &game);
	mlx_loop(game.mlx);
	mlx_end(&game);
	return (0);
}

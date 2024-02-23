/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:08:59 by gpouzet           #+#    #+#             */
/*   Updated: 2024/02/23 20:10:24 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	get_pixel_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int set_addr(t_img *img)
{
    img->data.addr = mlx_get_data_addr(img->img, &img->data.bits_per_pixel, \
            &img->data.line_length, &img->data.endian);
    if (img->data.addr == NULL)
        return (1);
    img->direction = 1;
    return (0);
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
/*
static void render_player(t_game game, t_pc pc)
{
    int x;
    int y;
	int	px;
	int	py;

	px = (pc.x * RES) + pc.sub_x;
	py = (pc.y * RES) + pc.sub_y;
    x = -1;
    while (++x < 16)
    {
        y = -1;
        while (++y < 16)
        {
			mlx_pixel_put(game.mlx, game.win,1100+ x + px , y + py, 0xC5BCAA);
        }
    }
	x = -1;
	while (++x < 32)
	{
		mlx_pixel_put(game.mlx, game.win,1100+ 8 + px + (-x * cos(pc.view)), 8 + py + (-x * sin(pc.view)), 0xC5BCAA);
	}
}
*/

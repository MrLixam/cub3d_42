/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 05:19:20 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/20 05:58:40 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_image_north(void *mlx)
{
	t_graphic	*graphics;
	void		*img;
	int			tmp[2];

	graphics = get_graph();
	if (graphics->north == NULL)
		return (0);
	img = mlx_png_file_to_image(mlx, graphics->north, &tmp[0], &tmp[1]);
	if (img == NULL)
	{
		ft_error(graphics->north, "can't get image");
		return (1);
	}
	mlx_destroy_image(mlx, img);
	return (0);
}

static int	check_image_south(void *mlx)
{
	t_graphic	*graphics;
	void		*img;
	int			tmp[2];

	graphics = get_graph();
	if (graphics->south == NULL)
		return (0);
	img = mlx_png_file_to_image(mlx, graphics->south, &tmp[0], &tmp[1]);
	if (img == NULL)
	{
		ft_error(graphics->south, "can't get image");
		return (1);
	}
	mlx_destroy_image(mlx, img);
	return (0);
}

static int	check_image_west(void *mlx)
{
	t_graphic	*graphics;
	void		*img;
	int			tmp[2];

	graphics = get_graph();
	if (graphics->west == NULL)
		return (0);
	img = mlx_png_file_to_image(mlx, graphics->west, &tmp[0], &tmp[1]);
	if (img == NULL)
	{
		ft_error(graphics->west, "can't get image");
		return (1);
	}
	mlx_destroy_image(mlx, img);
	return (0);
}

static int	check_image_east(void *mlx)
{
	t_graphic	*graphics;
	void		*img;
	int			tmp[2];
	
	graphics = get_graph();
	if (graphics->east == NULL)
		return (0);
	img = mlx_png_file_to_image(mlx, graphics->east, &tmp[0], &tmp[1]);
	if (img == NULL)
	{
		ft_error(graphics->east, "can't get image");
		return (1);
	}
	mlx_destroy_image(mlx, img);
	return (0);
}

int	check_images(void *mlx)
{
	if (check_image_north(mlx))
		return (1);
	if (check_image_south(mlx))
		return (1);
	if (check_image_west(mlx))
		return (1);
	if (check_image_east(mlx))
		return (1);
	return (0);
}
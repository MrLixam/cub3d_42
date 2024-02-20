/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:39:11 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/20 06:41:31 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//main temporaire de test, fait un autre main et met celui là en commentaire si t'a besoin de faire des tests pour l'exec please :)

int	main(int argc, char **argv)
{
	t_graphic	*graphics;
	void		*mlx;

	(void)argc;
	graphics = get_graph();

	if (parser(argv[1]))
	{
		gnl_release();
		return (1);
	}
	mlx = mlx_init();
	if (check_images(mlx))
	{
		mlx_destroy_display(mlx);
		gnl_release();
		reset_graph();
		return (1);
	}
	printf("graphics->ceiling = %d %d %d\n", graphics->ceiling->red, graphics->ceiling->green, graphics->ceiling->blue);
	printf("graphics->floor = %d %d %d\n", graphics->floor->red, graphics->floor->green, graphics->floor->blue);
	printf("graphics->north = %s\n", graphics->north);
	printf("graphics->south = %s\n", graphics->south);
	printf("graphics->east = %s\n", graphics->east);
	printf("graphics->west = %s\n", graphics->west);
	
	int i = 0;
	if (graphics->map)
	{
		while (graphics->map[i])
		{
			printf("\"%s\"\n", graphics->map[i]);
			i++;
		}
	}
	mlx_destroy_display(mlx);
	reset_graph();
	gnl_release();
	return (0);
}

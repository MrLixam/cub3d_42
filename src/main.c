/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:39:11 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 05:06:31 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include <limits.h>

void	check_argc(int argc)
{
	if (argc == 1)
		ft_error(NULL, "no file given");
	if (argc > 2)
		ft_error(NULL, "too many arguments");
	if (argc != 2)
		exit (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	void	*mlx;

	check_argc(argc);
	parser(argv[1]);
	mlx = mlx_init();
	if (!mlx)
		ft_error(NULL, "maldavid est mauvais");
	if (mlx)
	{
		game = set_game(mlx);
		if (!game)
			gnl_release();
		if (!game)
			exit(1);
		cub3d(game);
	}
	gnl_release();
	return (0);
}

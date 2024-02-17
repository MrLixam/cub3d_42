/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:39:11 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/17 17:05:04 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//main temporaire de test, fait un autre main et met celui là en commentaire si t'a besoin de faire des tests pour l'exec please :)

int	main(int argc, char **argv)
{
	t_graphic	*graphics;
	char	**test;

	(void)argc;
	init_graph();
	graphics = get_graph();

	parse_extern(argv[1], ".cub");
	valid_config(argv[1]);
	test = gnl_full_file(argv[1]);
	graphics->map = normalize_map(test, 6);

	printf("graphics->ceiling = %d %d %d\n", graphics->ceiling->red, graphics->ceiling->green, graphics->ceiling->blue);
	printf("graphics->floor = %d %d %d\n", graphics->floor->red, graphics->floor->green, graphics->floor->blue);
	printf("graphics->north = %s\n", graphics->north);
	printf("graphics->south = %s\n", graphics->south);
	printf("graphics->east = %s\n", graphics->east);
	printf("graphics->west = %s\n", graphics->west);
	
	int i = 0;
	if (graphics->map){
	while (graphics->map[i])
	{
		printf("\"%s\"\n", graphics->map[i]);
		i++;
	}
	}
	ft_free_arr(test);
	ft_free_arr(graphics->map);
	reset_graph();
	gnl_release();
	return (0);
}

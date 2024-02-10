/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:39:11 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/10 13:33:00 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//main temporaire de test, fait un autre main et met celui là en commentaire si t'a besoin de faire des tests pour l'exec please :)

int	main(void)
{
	t_graphic *graph = get_graph();
	char **file = gnl_full_file("test.cub");
	int i = 0;
	int j = 0;

	/*if (!parse_extern("..cub", ".cub"))
		printf("ok\n");
	if (!parse_extern("test.cub", ".cub"))
		printf("ok\n");
	if (!parse_extern(".cub", ".cub"))
		printf("ko\n");
	if (!parse_extern("caca.cu", ".cub"))
		printf("ko\n");
	if (!parse_extern("cu", ".cub"))
		printf("ko\n");
	if (!parse_extern("wqwqwqwqwwqwqw.cub.cub", ".cub"))
		printf("ko\n");
	if (!parse_extern("caca.cub", ".cub"))
		printf("ko\n");*/
	while (file[i])
	{
		j = is_path(file[i]);
		printf("%d\n", j);
		i++;
	}
	printf("%s\n%s\n%s\n%s\n", graph->north, graph->south, graph->west, graph->east);
	ft_free_arr(file);
	reset_graph();
	gnl_release();
	return (0);
}

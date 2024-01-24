/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:39:11 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/24 23:13:22 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/cub3d.h"

//main temporaire de test, fait un autre main et met celui là en commentaire si t'a besoin de faire des tests pour l'exec please :)

int	main(void)
{
	if (!ext_parser("..cub", ".cub"))
		printf("ok\n");
	if (!ext_parser("test.cub", ".cub"))
		printf("ok\n");
	if (!ext_parser(".cub", ".cub"))
		printf("ko\n");
	if (!ext_parser("caca.cu", ".cub"))
		printf("ko\n");
	if (!ext_parser("cu", ".cub"))
		printf("ko\n");
	if (!ext_parser("wqwqwqwqwwqwqw.cub.cub", ".cub"))
		printf("ok\n");
	
	char *test = "Hello!";
	char *output;

	output = ft_strinsert(test, " World", 5);
	printf("%s\n", output);
	free(output);
	return (0);
}

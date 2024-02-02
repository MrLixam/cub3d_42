/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:39:11 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/01 22:16:37 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//main temporaire de test, fait un autre main et met celui là en commentaire si t'a besoin de faire des tests pour l'exec please :)

int	main(void)
{
	if (!parse_extern("..cub", ".cub"))
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
		printf("ko\n");
	return (0);
}

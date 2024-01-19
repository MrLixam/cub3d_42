/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:39:11 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/19 11:40:50 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/cub3d.h"

//main temporaire de test, fait un autre main et met celui là en commentaire si t'a besoin de faire des tests pour l'exec please :)

int	main(void)
{
	if (!name_parser("..cub"))
		printf("ok\n");
	if (!name_parser("test.cub"))
		printf("ok\n");
	if (!name_parser(".cub"))
		printf("ko\n");
	if (!name_parser("caca.cu"))
		printf("ko\n");
	if (!name_parser("cu"))
		printf("ko\n");
	if (!name_parser("wqwqwqwqwwqwqw.cub.cub"))
		printf("ok\n");
	return (0);
}

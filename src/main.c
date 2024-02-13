/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:39:11 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/13 19:13:57 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//main temporaire de test, fait un autre main et met celui là en commentaire si t'a besoin de faire des tests pour l'exec please :)

int	main(void)
{
	int		test;

	test = ft_atoi("123");
	printf("%d\n", test);
	test = ft_atoi("2147483647");
	printf("%d\n", test);
	test = ft_atoi("2147483648");
	printf("%d\n", test);
	printf("%d\n", *atoi_error());
	*atoi_error() = 0;
	test = ft_atoi("-2147483648");
	printf("%d\n", test);
	test = ft_atoi("-2147483649");
	printf("%d\n", test);
	printf("%d\n", *atoi_error());
	*atoi_error() = 0;
	test = ft_atoi("0");
	printf("%d\n", test);
	return (0);
}

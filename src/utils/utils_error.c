/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:47:51 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 05:06:19 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"	

void	ft_error(char *target, char *message)
{
	write(2, "Error\n", 6);
	if (target != NULL)
	{
		write(2, target, ft_strlen(target));
		write(2, ": ", 2);
	}
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}

void	ft_perror(char *prefix)
{
	write(2, "Error\n", 6);
	perror(prefix);
}

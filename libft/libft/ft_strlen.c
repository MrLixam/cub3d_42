/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:27:44 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/22 03:59:31 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*orig;

	if (!str)
		return (0);
	orig = str;
	while (*str)
		str++;
	return (str - orig);
}

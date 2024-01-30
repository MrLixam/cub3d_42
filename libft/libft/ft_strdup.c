/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:18:26 by gpouzet           #+#    #+#             */
/*   Updated: 2024/01/30 04:04:05 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*tmp;
	char	*dest;
	size_t	i;

	i = 0;
	tmp = (char *)src;
	dest = malloc(ft_strlen(tmp) + 1);
	if (!dest)
		return (dest);
	while (i < ft_strlen(tmp) + 1)
	{
		dest[i] = tmp[i];
		i++;
	}
	return (dest);
}

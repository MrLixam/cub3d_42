/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:14:15 by gpouzet           #+#    #+#             */
/*   Updated: 2024/01/30 03:41:13 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*rv;
	size_t			size_s1;
	size_t			size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen((const char *)s1);
	size_s2 = ft_strlen((const char *)s2);
	rv = (char *)malloc(1 + size_s1 + size_s2);
	if (!rv)
		return (NULL);
	ft_memcpy(rv, (char *)s1, size_s1);
	ft_memcpy(rv + size_s1, (char *)s2, size_s2 + 1);
	return (rv);
}

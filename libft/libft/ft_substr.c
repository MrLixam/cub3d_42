/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:19:12 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/22 04:34:46 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*rv;
	unsigned int	i;
	size_t			len_str;

	len_str = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (len_str < start)
		return (ft_strdup(""));
	if (len_str >= (start + len))
		rv = malloc(len + 1);
	else
		rv = malloc(1 + len - ((start + len) - len_str));
	if (!rv)
		return (NULL);
	i = 0;
	while ((i < len) && s[start + i])
	{
		rv[i] = s[start + i];
		i++;
	}
	rv[i] = '\0';
	return (rv);
}

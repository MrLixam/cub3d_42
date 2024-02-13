/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:43:58 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/13 19:16:33 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	*atoi_error(void)
{
	static int	error = 0;

	return (&error);
}

static int	ft_atoi_loop(char c, long long res, int sign)
{
	if (((res * 10) + (c - '0')) / 10 != res)
	{
		*atoi_error() = 1;
		return (0);
	}
	res = (res * 10) + (c - '0');
	if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
	{
		*atoi_error() = 1;
		return (0);
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	res;

	*atoi_error() = 0;
	if (!nptr)
		*atoi_error() = 2;
	if (!nptr)
		return (0);
	sign = 1;
	res = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		res = ft_atoi_loop(*nptr, res, sign);
		if (*atoi_error())
			return (0);
		nptr++;
	}
	return ((int)(res * sign));
}

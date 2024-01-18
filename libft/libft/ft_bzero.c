/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:09:36 by gpouzet           #+#    #+#             */
/*   Updated: 2023/04/14 12:45:09 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

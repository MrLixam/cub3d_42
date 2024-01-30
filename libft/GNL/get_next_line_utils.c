/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 02:34:31 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/30 03:50:00 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	**gnl_storage(void)
{
	static char	*file[1024] = {NULL};

	return (file);
}

void	gnl_release(void)
{
	char	**storage;
	int		i;

	i = 0;
	storage = gnl_storage();
	while (i < 1024)
	{
		if (storage[i])
			free(storage[i]);
		i++;
	}
}

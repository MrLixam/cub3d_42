/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:56:40 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 15:57:58 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	remove_wspace(char **array)
{
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (is_wspace(array[i][j]))
			j++;
		buffer = ft_substr(array[i], j, len_wspace(array[i]) - j);
		if (!buffer)
			ft_free_arr(array);
		if (!buffer)
			return ;
		free(array[i]);
		array[i] = buffer;
		i++;
	}
}

int	check_chars(char *line, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (++i - 1)
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == line[i])
				break ;
			j++;
		}
		if (!set[j])
			return (1);
		i++;
	}
	return (0);
}

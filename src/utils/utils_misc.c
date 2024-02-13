/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:25:21 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/13 20:12:40 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_in_set(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strinsert(char *base, char *ins, size_t pos)
{
	size_t	index[2];
	char	*new;

	index[0] = 0;
	if (ft_strlen(base) <= pos)
		return (NULL);
	new = ft_calloc(ft_strlen(base) + ft_strlen(ins) + 1, 1);
	while (index[0] < pos)
		new[index[0]++] = base[index[0]];
	ft_strlcat(new, ins, ft_strlen(base) + ft_strlen(ins) + 1);
	index[1] = index[0] + ft_strlen(ins);
	while (base[index[0]])
		new[index[1]++] = base[index[0]++];
	return (new);
}

t_graphic	*get_graph(void)
{
	static t_graphic	graphics;

	return (&graphics);
}

void	reset_graph(void)
{
	t_graphic	*graphics;

	graphics = get_graph();
	if (graphics->north)
		free(graphics->north);
	if (graphics->south)
		free(graphics->south);
	if (graphics->west)
		free(graphics->west);
	if (graphics->east)
		free(graphics->east);
	free(graphics->floor);
	free(graphics->ceiling);
}

void	init_graph(void)
{
	t_graphic	*graphics;

	graphics = get_graph();
	graphics->north = NULL;
	graphics->south = NULL;
	graphics->west = NULL;
	graphics->east = NULL;
	graphics->floor = ft_calloc(1, sizeof(t_color));
	graphics->ceiling = ft_calloc(1, sizeof(t_color));
}
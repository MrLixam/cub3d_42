/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_misc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:03:14 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/31 21:01:47 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	in the name, counts the number of lines in a given file pointed by the file
	descriptor fd, because of my school, I can't use fcntl() to check if fd is
	a valid file descriptor, will add when possible

	input : fd, a valid file descriptor
	
	output: the number of lines in the file, as a size_t
*/

size_t	gnl_count_lines(char *path)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(path, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			i++;
			ft_free(line);
			continue ;
		}
		if (!line)
			break ;
	}
	gnl_release_fd(fd);
	close(fd);
	return (i);
}


char	**gnl_full_file(char *path)
{
	char	**result;
	char	*buffer;
	int		fd;
	int		i;

	i = gnl_count_lines(path);
	if (i == 0)
		return (NULL);
	result = ft_calloc(i + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		result[i++] = buffer;
	}
	close(fd);
	return (result);
}

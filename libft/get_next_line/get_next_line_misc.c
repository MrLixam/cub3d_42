/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_misc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:03:14 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/22 08:18:37 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	in the name, counts the number of lines in a given file pointed by the file
	descriptor fd, because of my school, I can't use fcntl() to check if fd is
	a valid file descriptor, will add when possible

	input : fd, a valid file descriptor
	
	output: the number of lines in the file, as a size_t

	errors: will return 0 if file cannot be opened
			if anything fails in get_next_line, function will return how many
			lines it counted before get_next_line failed
*/

size_t	gnl_count_lines(char *path)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			i++;
			free(line);
		}
		else
			break ;
	}
	gnl_release_fd(fd);
	close(fd);
	return (i);
}

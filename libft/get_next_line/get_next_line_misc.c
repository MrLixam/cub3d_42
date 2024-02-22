/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_misc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:03:14 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/22 04:43:46 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	small funtion to reset a given fd
*/

static void	gnl_reset_fd(int fd)
{
	if (fd < 0 || fd >= gnl_fd_max())
		return ;
	close(fd);
	gnl_release_fd(fd);
}

/*
	Copies a whole file as a string array (char **) 
	removing all newline characters

	in: char* corresponding to the path to a file
	out : char ** the file with newline characters removed

	error cases: returns NULL if it cannot open the file,
	or if allocation somehow fails
*/

char	**gnl_full_file(char *path)
{
	char	**result;
	char	buffer[8193];
	char	*buffer2;
	int		fd_read[2];

	fd_read[0] = open(path, O_RDONLY);
	if (fd_read[0] == -1)
		return (NULL);
	buffer2 = NULL;
	while (1)
	{
		fd_read[1] = read(fd_read[0], buffer, 8192);
		if (fd_read[1] == 0 || fd_read[1] == -1)
			break ;
		buffer[fd_read[1]] = 0;
		buffer2 = ft_strjoin_gnl(buffer2, buffer);
		if (buffer2 == NULL)
			return (NULL);
	}
	result = NULL;
	gnl_reset_fd(fd_read[0]);
	if (fd_read[1] != -1)
		result = ft_split(buffer2, '\n');
	free(buffer2);
	return (result);
}

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

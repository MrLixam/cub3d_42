/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_full_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:18:02 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 15:59:24 by lvincent         ###   ########.fr       */
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

static int	count_a_char(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

char	*gnl_full_file_str(char *path)
{
	char	buffer[8193];
	char	*result;
	int		fd_read[2];

	fd_read[0] = open(path, O_RDONLY);
	if (fd_read[0] == -1)
		return (NULL);
	result = NULL;
	while (1)
	{
		fd_read[1] = read(fd_read[0], buffer, 8192);
		if (fd_read[1] == 0 || fd_read[1] == -1)
			break ;
		buffer[fd_read[1]] = 0;
		result = ft_strjoin_gnl(result, buffer);
		if (result == NULL)
			return (NULL);
	}
	gnl_reset_fd(fd_read[0]);
	return (result);
}

static char	*gnl_ff_allocate(char *buffer, char *move)
{
	char	*buff;

	if (move)
	{
		buff = ft_substr(buffer, 0, move + 1 - buffer);
		buff[ft_strlen(buff) - 1] = 0;
		return (buff);
	}
	else
		return (ft_strdup(buffer));
}

char	**gnl_full_file(char *path)
{
	char	*buffer[2];
	char	*move;
	char	**result;
	int		i;

	buffer[0] = gnl_full_file_str(path);
	buffer[1] = buffer[0];
	if (!buffer[0])
		return (NULL);
	result = ft_calloc(count_a_char(buffer[0], '\n') + 2, sizeof(char *));
	if (result)
	{
		i = 0;
		while (*buffer[0])
		{
			move = ft_strchr(buffer[0], '\n');
			result[i] = gnl_ff_allocate(buffer[0], move);
			if (!move)
				break ;
			buffer[0] = move + 1;
			i++;
		}
	}
	free(buffer[1]);
	return (result);
}

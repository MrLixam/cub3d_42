/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 02:34:31 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 17:02:53 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

static char	*config_file(void)
{
	int		fd;
	char	*file;
	char	buffer[11];
	int		readb;

	file = NULL;
	buffer[10] = '\0';
	fd = open("/proc/self/limits", O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		readb = read(fd, buffer, 10);
		if (readb == -1 || readb == 0)
			break ;
		file = ft_strjoin_gnl(file, buffer);
	}
	if (readb == -1)
		if (file)
			free(file);
	close(fd);
	return (file);
}

static int	init_max_fd(void)
{
	char	*file;
	char	*line;
	int		retval;
	int		i;

	file = config_file();
	if (file == NULL)
		return (1024);
	line = ft_strnstr(file, "Max open files", ft_strlen(file));
	if (!line)
		return (1024);
	i = 0;
	line += 26;
	while (ft_isdigit(line[i]))
		i++;
	line[i] = '\0';
	retval = ft_atoi(line);
	line[i] = ' ';
	line -= 26;
	free(file);
	return (retval);
}

int	gnl_fd_max(void)
{
	static int	max_fd = -1;

	if (max_fd < 0)
		max_fd = init_max_fd();
	return (max_fd);
}

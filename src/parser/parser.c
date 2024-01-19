/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:43:10 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/19 11:47:15 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	name_parser(char *name)
{
	char	*extension;

	if (ft_strlen(name) <= 4)
		return (1);
	extension = &name[ft_strlen(name) - 4];
	if (!ft_strncmp(extension, ".cub", 4))
		return (0);
	return (1);
}

int	is_valid_file(char *name)
{
	int	fd;

	fd = open(name, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

int	parse_ext(char *name)
{
	int	i;

	i = is_valid_file(name);
	if (i == 1)
		ft_error(name, "is a directory");
	if (i == -1)
	{
		if (errno == EACCES)
			ft_error(name, "file does not exist");
		else if (errno == EACCES)
			ft_error(name, "permission denied");
	}
	if (i)
		return (1);
	i = name_parser(name);
	if (i)
		ft_error(name,
			"invalid file name: must be a .cub and name musn't be empty");
	if (i)
		return (1);
	return (0);
}

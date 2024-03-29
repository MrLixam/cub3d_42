/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exterior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:43:10 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 15:44:25 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	name_parser(char *name, char *ext)
{
	char		*extension;
	size_t		len;

	len = ft_strlen(ext);
	if (ft_strlen(name) <= len)
		return (1);
	extension = &name[ft_strlen(name) - len];
	if (!ft_strncmp(extension, ext, len))
		return (0);
	return (1);
}

int	not_valid_file(char *name)
{
	int	fd;

	fd = open(name, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_error(name, "Is a directory");
		return (1);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_perror(name);
		return (1);
	}
	close(fd);
	return (0);
}

int	parse_extern(char *name, char *ext)
{
	char	*error;

	if (not_valid_file(name) == 1)
		return (1);
	error = ft_strinsert(
			"invalid file name: must be a  and name musn't be empty",
			ext, 29);
	if (name_parser(name, ext))
		ft_error(name, error);
	free(error);
	if (name_parser(name, ext))
		return (1);
	return (0);
}

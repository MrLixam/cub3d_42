/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:11:04 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 15:54:28 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_texture(char *to_check)
{
	if (!ft_strncmp(to_check, "NO", 2) && is_wspace(to_check[2]))
		return (1);
	else if (!ft_strncmp(to_check, "SO", 2) && is_wspace(to_check[2]))
		return (1);
	else if (!ft_strncmp(to_check, "WE", 2) && is_wspace(to_check[2]))
		return (1);
	else if (!ft_strncmp(to_check, "EA", 2) && is_wspace(to_check[2]))
		return (1);
	else
		return (0);
}

int	check_lines(char **file)
{
	int	i;

	i = -1;
	while (file[++i])
	{
		if (file[i][0] == 0)
			continue ;
		else if (!ft_strncmp(file[i], "F", 1) && is_wspace(file[i][1]))
			continue ;
		else if (!ft_strncmp(file[i], "C", 1) && is_wspace(file[i][1]))
			continue ;
		else if (ft_strlen(file[i]) <= 2)
			return (-1);
		else if (is_texture(file[i]))
			continue ;
		else if (!check_chars(file[i], " 01NSWE"))
			break ;
		else
			return (-1);
	}
	if (!i)
		ft_error(NULL, "no format specifiers present");
	return (i);
}

static int	check_double(char **file, char *to_find, int max, int error)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(to_find);
	while (file[i] && i < max)
	{
		if (!ft_strncmp(to_find, file[i], len))
			j++;
		i++;
	}
	if (!j && !error)
		ft_error(NULL, "missing or misplaced specifier in map file");
	if (j > 1 && !error)
		ft_error(NULL, "more that one of a specifier to a texture or a color");
	return (j != 1);
}

int	base_tests(char **file, char *path)
{
	int	i;
	int	res;

	if (!file || file[0] == NULL)
		ft_error(path, "file is empty");
	if (!file || file[0] == NULL)
		return (0);
	res = check_lines(file);
	if (res == -1)
		ft_error(NULL, "Unknown format specifier");
	if (res <= 0)
		return (0);
	i = 0;
	i += check_double(file, "NO", res, i);
	i += check_double(file, "SO", res, i);
	i += check_double(file, "WE", res, i);
	i += check_double(file, "EA", res, i);
	i += check_double(file, "F", res, i);
	i += check_double(file, "C", res, i);
	if (i)
		return (0);
	return (res);
}

int	no_empty_line(char **file, int i)
{
	if (!file[i])
	{
		ft_error(NULL, "there is no map");
		return (0);
	}
	while (file[i])
	{
		if (file[i][0] == 0)
		{
			ft_error(NULL, "there are empty lines in map definition");
			return (0);
		}
		i++;
	}
	return (1);
}

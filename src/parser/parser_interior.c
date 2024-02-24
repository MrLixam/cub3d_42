/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_interior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:11:04 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 12:44:50 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	check_lines(char **file)
{
	int	i;

	i = 0;
	while (file[++i - 1])
	{
		if (file[i - 1][0] == 0)
			continue;
		else if (ft_strlen(file[i - 1]) < 1)
			return (1);
		else if (!ft_strncmp(file[i - 1], "NO", 2) && is_wspace(file[i][2]))
			continue ;
		else if (!ft_strncmp(file[i - 1], "SO", 2) && is_wspace(file[i][2]))
			continue ;
		else if (!ft_strncmp(file[i - 1], "WE", 2) && is_wspace(file[i][2]))
			continue ;
		else if (!ft_strncmp(file[i - 1], "EA", 2) && is_wspace(file[i][2]))
			continue ;
		else if (!ft_strncmp(file[i - 1], "F" , 1) && is_wspace(file[i][1]))
			continue ;
		else if (!ft_strncmp(file[i - 1], "C", 1) && is_wspace(file[i][1]))
			continue ;
		else if (!check_chars(file[i - 1], " 01NSWE"))
			break ;
		else
			return (1);
	}
	return (0);
}

int check_double(char **file, char *to_find)
{
	int		i;
	int		j;
	size_t	len;
	
	i = 0;
	j = 0;
	len = ft_strlen(to_find);
	while (file[i])
	{
		if (!ft_strncmp(to_find, file[i], len))
			j++;
		i++;
	}
	if (!j)
		ft_error(NULL, "missing info in map file");
	if (j > 1)
		ft_error(NULL, "more that one of a path to a texture or a color");
	return (j != 1);
}

int check_order2(char **file, int i)
{
	if (ft_strncmp(file[i++], "F", 1))
		return (1);
	while (file[i][0] == 0)
		i++;
	if (ft_strncmp(file[i++], "C", 1))
		return (1);
	return (0);
}

int	check_order(char **file)
{
	int	i;
	int	res;
	
	i = 0;
	while (file[i][0] == 0)
		i++;
	if (ft_strncmp(file[i++], "NO", 2))
		return (1);
	while (file[i][0] == 0)
		i++;
	if (ft_strncmp(file[i++], "SO", 2))
		return (1);
	while (file[i][0] == 0)
		i++;
	if (ft_strncmp(file[i++], "WE", 2))
		return (1);
	while (file[i][0] == 0)
		i++;
	if (ft_strncmp(file[i++], "EA", 2))
		return (1);
	while (file[i][0] == 0)
		i++;
	res = check_order2(file, i);	
	return (res);
}

int	base_tests(char **file, char *path)
{
	int	i;
	
	if (!file || file[0] == NULL)
		ft_error(path, "file is empty");
	if (!file || file[0] == NULL)
		return (1);
	if (check_lines(file))
	{
		ft_error(NULL, "Unknown identifier");
		return (1);
	}
	i = 0;
	i += check_double(file, "NO");
	i += check_double(file, "SO");
	i += check_double(file, "WE");
	i += check_double(file, "EA");
	i += check_double(file, "F");
	i += check_double(file, "C");
	if (i)
		return (1);
	if (check_order(file))
		return (1);
	return (0);
}

static int	no_empty_line(char **file, int i)
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

int	get_texture_paths(char **file)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (file[i][0] == 0)
		i++;
	j += is_path(file[i++]);
	while (file[i][0] == 0)
		i++;
	j += is_path(file[i++]);
	while (file[i][0] == 0)
		i++;
	j += is_path(file[i++]);
	while (file[i][0] == 0)
		i++;
	j += is_path(file[i++]);
	if (j)
		return (-1);
	return (i);
}

int	get_colors_path(char **file, int i)
{
	int	j;

	j = 0;
	while (file[i][0] == 0)
		i++;
	j += is_color(file[i++]);
	while (file[i][0] == 0)
		i++;
	j += is_color(file[i++]);
	while (file[i][0] == 0)
		i++;
	if (j)
		return (-1);
	return (i);
}

int	valid_config(char *path)
{
	char	**file;
	int		i;

	i = 0;
	file = gnl_full_file(path);
	if (base_tests(file, path))
	{
		if (file)
			ft_free_arr(file);
		return (1);
	}
	i = get_texture_paths(file);
	if (i == -1)
		ft_free_arr(file);
	if (i == -1)
		return (1);
	i = get_colors_path(file, i);
	if ( i != -1 && no_empty_line(file, i))
		get_graph()->map = normalize_map(file, i);
	ft_free_arr(file);
	return (i == -1);
}

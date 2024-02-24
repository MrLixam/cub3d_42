/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 05:19:20 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 16:51:35 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_error(int fd, int value, char *path)
{
	close(fd);
	if (value == -1)
		ft_perror(path);
	if (value != 8 && value != -1)
		ft_error(path, "error getting file signature");
	if (value == 8)
		ft_error(path, "invalid file signature");
}

static int	check_image(char *path)
{
	int				tmp[2];
	unsigned char	buffer[8];

	if (path == NULL)
		return (0);
	if (not_valid_file(path))
		return (1);
	tmp[0] = open(path, O_RDONLY);
	if (tmp[0] == -1)
	{
		ft_perror(path);
		return (0);
	}
	tmp[1] = read(tmp[0], buffer, 8);
	if (tmp[1] != 8)
		check_error(tmp[0], tmp[1], path);
	if (tmp[1] != 8)
		return (1);
	if (ft_memcmp(buffer, "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A", 8) != 0)
	{
		check_error(tmp[0], tmp[1], path);
		return (1);
	}
	return (0);
}

int	check_images(void)
{
	t_graphic	*graphics;

	graphics = get_graph();
	if (check_image(graphics->north))
		return (1);
	if (check_image(graphics->south))
		return (1);
	if (check_image(graphics->west))
		return (1);
	if (check_image(graphics->east))
		return (1);
	return (0);
}

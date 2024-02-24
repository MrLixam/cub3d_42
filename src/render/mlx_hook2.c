/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:47:07 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 00:47:39 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	hook_window(int keycode, void *game)
{
	t_game	*tmp;

	tmp = (t_game *)game;
	if (keycode == 0)
		mlx_loop_end(tmp->mlx);
	return (0);
}
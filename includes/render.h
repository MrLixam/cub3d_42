/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:03:16 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/23 16:44:36 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "cub3d.h"
# ifndef PI
#  define PI 3.14159265
# endif
# ifndef P2
#  define P2 PI/2
# endif
# ifndef P3
#  define P3 3*PI/2
# endif
# ifndef DEG
#  define DEG 0.0174533
# endif
# ifndef RES
#  define RES 64
# endif

int		cub3d(t_game *game);
/*			mlx			*/
int 	hook_handler(int keycode, void *game);
void    render_map(t_game *game, char **map);
void	draw_line(t_game *game, int deg, t_ray ray);
/*			raycast		*/
int	raycast(t_game *game);

#endif

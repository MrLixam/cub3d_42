/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:03:16 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 04:57:21 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "cub3d.h"
# ifndef PI
#  define PI 3.14159265f
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
int		hook_window(int keycode, void *game);
int		keyboard_engage(int keycode, void *param);
int		keyboard_disengage(int keycode, void *param);
int		actions(void *param);
void    render_map(t_game *game, char **map);
void	draw_line(t_game *game, int deg, t_ray ray);
/*			raycast		*/
int		raycast(t_game *game);
int		update(void *param);

#endif

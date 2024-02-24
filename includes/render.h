/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:03:16 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 10:12:55 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "cub3d.h"
# ifndef PI
#  define PI 3.141592653
# endif
# ifndef P2
#  define P2 1.570796326
# endif
# ifndef P3
#  define P3 4.712388980
# endif
# ifndef DEG
#  define DEG 0.0174533
# endif
# ifndef RES
#  define RES 64
# endif
# ifndef SPEED
#  define SPEED 1
# endif

int		cub3d(t_game *game);
/*			mlx			*/
int		hook_window(int keycode, void *game);
int		keyboard_engage(int keycode, void *param);
int		keyboard_disengage(int keycode, void *param);
int		actions(void *param);
void	draw_line(t_game *game, int deg, t_ray ray);
/*			ray_line	*/
void	horizontal_line(t_game *game, t_line *hor);
void	vertical_line(t_game *game, t_line *ver);
void	shortest_line(t_game *game);
/*			raycast		*/
int		raycast(t_game *game);
int		update(void *param);

#endif

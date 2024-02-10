/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:04:41 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/10 13:23:11 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "structs.h"

void		ft_error(char *target, char *message);
void		ft_perror(char *prefix);
int			is_wspace(int c);
int			is_in_set(char *set, char c);
char		*ft_strinsert(char *base, char *ins, size_t pos);
t_graphic	*get_graph(void);
void		reset_graph(void);

#endif
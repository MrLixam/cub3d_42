/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:54:58 by gpouzet           #+#    #+#             */
/*   Updated: 2024/01/30 07:29:55 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include "libft.h"
# include <unistd.h>

char	*get_next_line(int fd);
char	**gnl_storage(void);
void	gnl_release(void);
void	gnl_release_fd(int fd);
size_t	gnl_count_lines(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:02:30 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/22 05:14:29 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		name_parser(char *name, char *ext);
int		parse_extern(char *name, char *ext);
int		not_valid_file(char *name);
int		is_path(char *line);
int		is_color(char *line);
int		valid_config(char *path);
char	**normalize_map(char **file, size_t start);
size_t	get_max_length(char **foo, size_t start);
int		parse_map(char **map);
int		check_images(void);

void	parser(char *path);
#endif
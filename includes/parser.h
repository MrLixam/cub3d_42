/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:02:30 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/24 15:08:34 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		name_parser(char *name, char *ext);
int		parse_extern(char *name, char *ext);
int		not_valid_file(char *name);
int		get_texture_paths(char **file, int max);
int		get_colors_path(char **file, int max);
char	**normalize_map(char **file, size_t start);
size_t	get_max_length(char **foo, size_t start);
int		parse_map(char **map);
int		check_images(void);
size_t	len_wspace(char *line);
int		check_order(char **file);
int		no_empty_line(char **file, int i);
int		base_tests(char **file, char *path);

void	parser(char *path);
#endif
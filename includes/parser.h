/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:02:30 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/13 21:02:22 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int	name_parser(char *name, char *ext);
int	parse_extern(char *name, char *ext);
int	not_valid_file(char *name);
int	is_path(char *line);
int	is_color(char *line);
int	valid_config(char *path);

#endif
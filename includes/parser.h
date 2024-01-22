/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:02:30 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/22 16:38:30 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

int	name_parser(char *name);
int	parse_ext(char *name);
int	is_valid_file(char *name);
int	ext_parser(char *name, char *ext);

#endif
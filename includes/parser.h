/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:02:30 by lvincent          #+#    #+#             */
/*   Updated: 2024/02/10 12:50:14 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int	name_parser(char *name, char *ext);
int	parse_extern(char *name, char *ext);
int	not_valid_file(char *name);
int	is_path(char *line);

#endif
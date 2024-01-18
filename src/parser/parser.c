/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:43:10 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/18 09:08:48 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int name_parser(char *name)
{
    char *extension;

	if (ft_strlen(name) <= 4)
		return (1);
	extension = &name[ft_strlen(name) - 4];
	if (!ft_strncmp(extension, ".cub", 4))
		return (0);
	return (1);
}
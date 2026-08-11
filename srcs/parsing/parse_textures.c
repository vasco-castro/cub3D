/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:24:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/11 16:22:51 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	parse_textures(t_map_vars map_vars, t_map *map)
{
	(void)map;
	if (!check_texture(map_vars))
	{
		debug("Parsing stopped: check_texture failed\n");
		return (false);
	}
	return (true);
}

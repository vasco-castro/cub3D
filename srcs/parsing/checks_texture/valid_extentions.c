/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extentions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:16:56 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/27 17:34:31 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	valid_extention(char *path)
{
	int	len;

	len = strlen(path);
	if (len < 4 || ft_strncmp(&path[len - 4], ".xpm", 4) != 0)
	{
		debug("Error\ninvalid extension for texture\n");
		return (false);
	}
	return (true);
}

bool	valid_extentions(t_map_vars map_vars)
{
	if (!valid_extention(map_vars.north))
		return (false);
	if (!valid_extention(map_vars.south))
		return (false);
	if (!valid_extention(map_vars.west))
		return (false);
	if (!valid_extention(map_vars.east))
		return (false);
	return (true);
}

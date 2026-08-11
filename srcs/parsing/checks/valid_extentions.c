/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extentions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 19:16:56 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/11 19:23:27 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	valid_extention(char *path)
{
	int	len;

	len = strlen(path);
	if (ft_strncmp(&path[len - 4], ".xpm", 4) != 0)
	{
		debug("Parsing stopped: cannot use invalid extention '%s'\n", path);
		return (false);
	}
	return (true);
}

bool	valid_extentions(t_map_vars map_vars)
{
	if (!valid_extention(map_vars.north))
	{
		debug("Parsing stopped: invalid NO invalid extention\n");
		return (false);
	}
	if (!valid_extention(map_vars.south))
	{
		debug("Parsing stopped: invalid SO invalid extention\n");
		return (false);
	}
	if (!valid_extention(map_vars.west))
	{
		debug("Parsing stopped: invalid WE invalid extention\n");
		return (false);
	}
	if (!valid_extention(map_vars.east))
	{
		debug("Parsing stopped: invalid EA invalid extention\n");
		return (false);
	}
	return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_spacing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:42:47 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/11 19:25:31 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	check_invalid_spacing(char *map_vars)
{
	int	i;
	
	i = 0;
	while (map_vars[i])
	{
		if (map_vars[i] == ' ')
		{
			debug("Parsing stopped: space inside value '%s'\n", map_vars);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	valid_spacing(t_map_vars map_vars)
{
	if (!check_invalid_spacing(map_vars.east))
	{
		debug("Parsing stopped: invalid spacing in EA value\n");
		return (false);
	}
	if (!check_invalid_spacing(map_vars.south))
	{
		debug("Parsing stopped: invalid spacing in SO value\n");
		return (false);
	}
	if (!check_invalid_spacing(map_vars.west))
	{
		debug("Parsing stopped: invalid spacing in WE value\n");
		return (false);
	}
	if (!check_invalid_spacing(map_vars.north))
	{
		debug("Parsing stopped: invalid spacing in NO value\n");
		return (false);
	}
	return (true);
}

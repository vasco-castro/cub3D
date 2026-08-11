/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_permisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:43:33 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/11 16:42:53 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	valid_permission(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		debug("Parsing stopped: cannot open texture path '%s'\n", path);
		return (false);
	}
	close(fd);
	return (true);
}

bool	valid_permisions(t_map_vars map_vars)
{
	if (!valid_permission(map_vars.north))
	{
		debug("Parsing stopped: invalid NO texture path\n");
		return (false);
	}
	if (!valid_permission(map_vars.south))
	{
		debug("Parsing stopped: invalid SO texture path\n");
		return (false);
	}
	if (!valid_permission(map_vars.west))
	{
		debug("Parsing stopped: invalid WE texture path\n");
		return (false);
	}
	if (!valid_permission(map_vars.east))
	{
		debug("Parsing stopped: invalid EA texture path\n");
		return (false);
	}
	return (true);
}

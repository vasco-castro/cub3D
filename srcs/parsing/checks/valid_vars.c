/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:22:40 by biphuyal          #+#    #+#             */
/*   Updated: 2026/06/22 19:31:47 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	valid_vars(t_map_vars map_vars)
{
	if (!map_vars.north || !map_vars.south || !map_vars.west)
	{
		debug("Parsing stopped: missing NO, SO, or WE variable\n");
		return (false);
	}
	if (!map_vars.east || !map_vars.floor || !map_vars.ceiling)
	{
		debug("Parsing stopped: missing EA, F, or C variable\n");
		return (false);
	}
	return (true);
}

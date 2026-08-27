/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:22:40 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/21 17:41:18 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	valid_vars(t_map_vars map_vars)
{
	if (!map_vars.north)
		return (debug("Error\nmissing NO texture variable\n"), false);
	if (!map_vars.south)
		return (debug("Error\nmissing SO texture variable\n"), false);
	if (!map_vars.west)
		return (debug("Error\nmissing WE texture variable\n"), false);
	if (!map_vars.east)
		return (debug("Error\nmissing EA texture variable\n"), false);
	if (!map_vars.floor)
		return (debug("Error\nmissing floor color variable\n"), false);
	if (!map_vars.ceiling)
		return (debug("Error\nmissing ceiling color variable\n"), false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_spacing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:42:47 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/11 16:34:55 by biphuyal         ###   ########.fr       */
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
			printf("space in middle of the value");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	valid_spacing(t_map_vars map_vars)
{
	if (!check_invalid_spacing(map_vars.east))
		return (false);
	if (!check_invalid_spacing(map_vars.south))
		return (false);
	if (!check_invalid_spacing(map_vars.west))
		return (false);
	if (!check_invalid_spacing(map_vars.north))
		return (false);
	if (!check_invalid_spacing(map_vars.floor))
		return (false);
	if (!check_invalid_spacing(map_vars.ceiling))
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 13:27:55 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/27 18:07:32 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	check_floors(t_map_vars map_vars, int i)
{
	if (!ft_isdigit(map_vars.floor[i]) && map_vars.floor[i] != ','
		&& map_vars.floor[i] != ' '
		&& map_vars.floor[i] != '\t')
		return (false);
	if (map_vars.floor[i] == ',' && i == 0)
		return (false);
	return (true);
}

bool	check_ceilings(t_map_vars map_vars, int i)
{
	if (!ft_isdigit(map_vars.ceiling[i]) && map_vars.ceiling[i] != ','
		&& map_vars.ceiling[i] != ' '
		&& map_vars.ceiling[i] != '\t')
		return (false);
	if (map_vars.ceiling[i] == ',' && i == 0)
		return (false);
	return (true);
}

bool	valid_chars(t_map_vars map_vars)
{
	unsigned int	i;

	i = 0;
	while (map_vars.floor[i])
	{
		if (!check_floors(map_vars, i))
		{
			debug("Error\nInvalid character in the floor's value\n");
			return (false);
		}
		i++;
	}
	i = 0;
	while (map_vars.ceiling[i])
	{
		if (!check_ceilings(map_vars, i))
		{
			debug("Error\nInvalid character in the ceiling's value\n");
			return (false);
		}
		i++;
	}
	return (true);
}

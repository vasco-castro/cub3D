/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_values_exists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:08:32 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/27 18:09:14 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	valid_three_values(t_map_vars map_vars)
{
	unsigned int	i;

	i = 0;
	while (map_vars.floor[i])
	{
		if (map_vars.floor[i] == ',' && !ft_isdigit(map_vars.floor[i + 1])
			&& !check_floors(map_vars, i + 1))
		{
			debug("Error\nNot all value present in  the floor colors\n");
			return (false);
		}
		i++;
	}
	i = 0;
	while (map_vars.ceiling[i])
	{
		if (!map_vars.ceiling[i] && !ft_isdigit(map_vars.ceiling[i + 1])
			&& !check_ceilings(map_vars, i + 1))
		{
			debug("Error\nNot all value present in the ceiling colors\n");
			return (false);
		}
		i++;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_values_exists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 13:27:55 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/13 15:49:40 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	three_values_exists(t_map_vars map_vars)
{
	unsigned int	i;

	i = 0;
	while (map_vars.floor[i])
	{
		if (map_vars.floor[i] == ',' && !ft_isdigit(map_vars.floor[i + 1]))
		{
			debug("Error\nNot all value presentin  the floor colors\n");	
			return (false);
		}
		i++;
	}
	i =  0;
	while (map_vars.ceiling[i])
	{
		if (!map_vars.ceiling[i] && !ft_isdigit(map_vars.ceiling[i + 1]))
		{
			debug("Error\nNot all value present in the ceiling colors\n");		
			return (false);
		}
		i++;
	}
	return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 13:27:55 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/13 15:27:11 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	valid_chars(t_map_vars map_vars)
{
	unsigned int	i;

	i = 0;
	while (map_vars.floor[i])
	{
		if (!ft_isdigit(map_vars.floor[i]) && map_vars.floor[i] != ',')
		{
			debug("Error\n Invalid character in the floor colors");	
			return (false);
		}
		i++;
	}
	while (map_vars.ceiling[i])
	{
		if (!ft_isdigit(map_vars.ceiling[i]) && map_vars.ceiling[i] != ',')
		{
			debug("Error\n Invalid character in the ceiling colors");		
			return (false);
		}
		i++;
	}
	return (true);
}
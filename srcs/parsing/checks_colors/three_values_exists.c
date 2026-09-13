/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_values_exists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:08:32 by biphuyal          #+#    #+#             */
/*   Updated: 2026/09/13 18:25:51 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	valid_three_values(t_map_vars map_vars)
{
	unsigned int	i;

	i = 0;
	while (map_vars.floor[i])
	{
		if (map_vars.floor[i] == ',' && !ft_isdigit(map_vars.floor[i + 1]))
		{
			ft_error(ERR_FLOOR_MISSING);
			return (false);
		}
		i++;
	}
	i = 0;
	while (map_vars.ceiling[i])
	{
		if (map_vars.ceiling[i] == ',' && !ft_isdigit(map_vars.ceiling[i + 1]))
		{
			ft_error(ERR_CEIL_MISSING);
			return (false);
		}
		i++;
	}
	return (true);
}

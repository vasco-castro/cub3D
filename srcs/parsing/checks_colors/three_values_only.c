/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_values_only.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:07:36 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/13 16:09:16 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	three_values_only(t_map_vars map_vars)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (map_vars.floor[i])
	{
		if (map_vars.floor[i] == ',')
			count += 1;
		i++;
	}
	if (count != 3)
		return (false);
	i =  0;
	count =  0;
	while (map_vars.ceiling[i])
	{
		if (!map_vars.ceiling[i] && !ft_isdigit(map_vars.ceiling[i + 1]))
			count += 1;
		i++;
	}
	if (count != 3)
		return (false);
	return (true);
}
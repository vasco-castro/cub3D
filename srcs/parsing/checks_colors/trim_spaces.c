/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 00:10:04 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/14 00:21:34 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	trim_spaces(t_map_vars map_vars)
{
	unsigned int	i;
	unsigned int	start;

	i = 0;
	start = 0;
	while (map_vars.floor[i])
	{
		if (map_vars.floor[i] != ' ' && map_vars.floor[i] != '\t')
		{
			map_vars.floor[start] = map_vars.floor[i];
			start++;
		}
		i++;
	}
	return (true);
}
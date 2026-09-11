/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:56:56 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/20 17:21:44 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	valid_map(char **map)
{
	char	**copy;

	copy = ft_tabcpy(map);
	if (!copy)
	{
		debug("Error\nfailed to copy map for validation\n");
		return (false);
	}
	if (!flood_fill(copy, (int)player()->pos.y, (int)player()->pos.x))
	{
		ft_tabfree(copy);
		debug("Error\nmap is not closed\n");
		return (false);
	}
	ft_tabfree(copy);
	return (true);
}

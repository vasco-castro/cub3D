/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map_body.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:28:12 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/21 20:20:22 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	checks_for_map(char **map_body)
{
	if (!map_body)
	{
		ft_error(ERR_MAP_ALLOC);
		return (false);
	}
	if (!map_body[0])
	{
		ft_error(ERR_NO_MAP);
		return (false);
	}
	if (!valid_player(map_body))
	{
		ft_error(ERR_PLAYER);
		return (false);
	}
	if (!valid_map_borders(map_body))
		return (false);
	return (true);
}

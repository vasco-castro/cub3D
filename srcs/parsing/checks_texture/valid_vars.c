/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:22:40 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/21 17:41:18 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	valid_vars(t_map_vars map_vars)
{
	if (!map_vars.north)
		return (ft_error(ERR_MISSING_NO), false);
	if (!map_vars.south)
		return (ft_error(ERR_MISSING_SO), false);
	if (!map_vars.west)
		return (ft_error(ERR_MISSING_WE), false);
	if (!map_vars.east)
		return (ft_error(ERR_MISSING_EA), false);
	if (!map_vars.floor)
		return (ft_error(ERR_MISSING_F), false);
	if (!map_vars.ceiling)
		return (ft_error(ERR_MISSING_C), false);
	return (true);
}

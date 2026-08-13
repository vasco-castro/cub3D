/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:24:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/13 14:33:00 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	checks_for_colors(t_map_vars map_vars)
{
	if (!valid_vars(map_vars))
		return (false);
	if (!valid_invalid_char(map_vars))
		return (false);
	// if (!valid_three_value(map_vars))
	// 	return (false);
	// if (!valid_range(map_vars))
	// 	return (false);
	// if (!valid_separeter(map_vars))
	// 	return (false);
	// if (!trim_spaces(map_vars))
	// 	return (false);
	return (true);
}

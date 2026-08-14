/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:24:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/14 12:24:16 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	checks_for_colors(t_map_vars map_vars)
{
	if (!valid_vars(map_vars))
		return (false);
	if (!three_values_exists(map_vars))
		return (false);
	if (!three_values_only(map_vars))
		return (false);
	if (!valid_chars(map_vars))
		return (false);
	if (!valid_range(map_vars))
		return (false);
	if (!trim_spaces(map_vars))
		return (false);
	return (true);
}

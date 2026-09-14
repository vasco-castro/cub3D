/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_between_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:46:59 by biphuyal          #+#    #+#             */
/*   Updated: 2026/09/14 17:06:28 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	found_space(char *color, unsigned int i)
{
	unsigned int	next;

	if (!ft_isdigit(color[i]))
		return (false);
	next = i + 1;
	if (!is_space(color[next]))
		return (false);
	while (is_space(color[next]))
		next++;
	return (ft_isdigit(color[next]));
}

static bool	check_color_spaces(char *color)
{
	unsigned int	i;

	i = 0;
	while (color[i])
	{
		if (found_space(color, i))
			return (true);
		i++;
	}
	return (false);
}

bool	space_between_colors(t_map_vars map_vars)
{
	if (check_color_spaces(map_vars.floor))
		return (true);
	if (check_color_spaces(map_vars.ceiling))
		return (true);
	return (false);
}

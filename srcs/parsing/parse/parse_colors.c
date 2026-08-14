/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:24:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/14 12:58:30 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

unsigned int	rgb_converter(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

unsigned int	parse_rgb(char *value)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(value);
	while (*value && *value != ',')
		value++;
	g = ft_atoi(++value);
	while (*value && *value != ',')
		value++;
	b = ft_atoi(++value);
	return (rgb_converter(r, g, b));
}

bool	parse_colors(t_map_vars map_vars, t_map *map)
{
	if (!checks_for_colors(map_vars))
		return (false);
	map->floor = parse_rgb(map_vars.floor);
	map->ceiling = parse_rgb(map_vars.ceiling);
	return (true);
}

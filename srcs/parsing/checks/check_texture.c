/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:22:12 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/11 16:57:23 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	check_texture(t_map_vars map_vars)
{
	if (!valid_vars(map_vars))
	{
		debug("Parsing stopped: missing texture/color variable\n");
		return (false);
	}
	if (!valid_spacing(map_vars))
	{
		debug("Parsing stopped: invalid spacing in texture/color value\n");
		return (false);
	}
	if (!valid_permisions(map_vars))
	{
		debug("Parsing stopped: invalid texture file permissions/path\n");
		return (false);
	}
	return (true);
}

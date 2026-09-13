/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:03:27 by vsoares-          #+#    #+#             */
/*   Updated: 2026/09/13 17:30:59 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

t_player	*player(void)
{
	static t_player	player;

	return (&player);
}

t_keys	*keys(void)
{
	static t_keys	keys;

	return (&keys);
}

t_minimap	*minimap(void)
{
	static t_minimap	minimap;

	return (&minimap);
}

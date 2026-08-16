/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map_body.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:28:12 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/16 15:08:08 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	checks_for_map(char **map_body)
{
	if (!valid_player(map_body))
		return (false);
	if (!valid_closed_map(map_body))
		return (debug("Error\nmap is not closed by walls\n"), false);
	return (true);
}

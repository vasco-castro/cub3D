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
	if (!valid_player(map_body))
	{
		debug("Error\nmap need to have excatly one player");
		return (false);
	}
	if (!valid_map(map_body))
		return (false);
	return (true);
}

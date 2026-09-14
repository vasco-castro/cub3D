/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:54:29 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/14 17:28:44 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

void	free_map_vars(t_map_vars *map_vars)
{
	if (!map_vars)
		return ;
	free(map_vars->north);
	free(map_vars->south);
	free(map_vars->east);
	free(map_vars->west);
	free(map_vars->floor);
	free(map_vars->ceiling);
}

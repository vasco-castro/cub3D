/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:54:29 by biphuyal          #+#    #+#             */
/*   Updated: 2026/05/19 16:56:51 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

void	parse_error(const char *filename)
{
	ft_dprintf(STDERR_FILENO, RED "Error\n%s: %s\n" RESET,
		filename, strerror(errno));
}

void	free_map_vars(t_map *map, t_map_vars *map_vars)
{
	(void)map;
	if (!map_vars)
		return ;
	free(map_vars->north);
	free(map_vars->south);
	free(map_vars->east);
	free(map_vars->west);
	free(map_vars->floor);
	free(map_vars->ceiling);
}

void	free_map_body(t_map *map, char **map_body)
{
	(void)map;
	if (map_body)
		ft_tabfree(map_body);
}

void	parse_error_on_map(t_map *map)
{
	(void)map;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:38:41 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/11 19:13:06 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	skip_spaces(char *line, size_t *j)
{
	while (line[*j] && is_space(line[*j]))
		(*j)++;
}

bool	is_map_line(char *line, size_t j)
{
	return (line[j] == '0' || line[j] == '1');
}

void	print_map_vars(t_map_vars map_vars)
{
	ft_printf("Map variables:\n");
	ft_printf("NO: %s\n", map_vars.north);
	ft_printf("SO: %s\n", map_vars.south);
	ft_printf("WE: %s\n", map_vars.west);
	ft_printf("EA: %s\n", map_vars.east);
	ft_printf("F: %s\n", map_vars.floor);
	ft_printf("C: %s\n", map_vars.ceiling);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:38:41 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/11 16:40:19 by biphuyal         ###   ########.fr       */
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

// static void	print_map_var(char *name, char *value)
// {
// 	if (value)
// 		ft_printf("%s: %s", name, value);
// 	else
// 		ft_printf("%s: (null)\n", name);
// }

// void	print_map_vars(t_map_vars map_vars)
// {
// 	ft_printf("Map variables:\n");
// 	print_map_var("NO", map_vars.north);
// 	print_map_var("SO", map_vars.south);
// 	print_map_var("WE", map_vars.west);
// 	print_map_var("EA", map_vars.east);
// 	print_map_var("F", map_vars.floor);
// 	print_map_var("C", map_vars.ceiling);
// }

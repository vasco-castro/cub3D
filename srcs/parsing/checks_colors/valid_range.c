/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:36:15 by biphuyal          #+#    #+#             */
/*   Updated: 2026/09/14 08:27:31 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	valid_digits_range(char *digits)
{
	int	i;
	int	value;

	i = 0;
	while (digits[i])
	{
		if (ft_isdigit(digits[i]))
		{
			value = 0;
			while (ft_isdigit(digits[i]))
			{
				value = value * 10 + digits[i] - '0';
				if (value > 255)
					return (false);
				i++;
			}
		}
		else
			i++;
	}
	return (true);
}

bool	valid_range(t_map_vars map_vars)
{
	if (!valid_digits_range(map_vars.floor))
		return (ft_error(ERR_FLOOR_RANGE), false);
	if (!valid_digits_range(map_vars.ceiling))
		return (ft_error(ERR_CEIL_RANGE), false);
	return (true);
}

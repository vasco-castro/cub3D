/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:36:15 by biphuyal          #+#    #+#             */
/*   Updated: 2026/08/27 18:01:21 by biphuyal         ###   ########.fr       */
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
			value = ft_atoi(&digits[i]);
			if (value < 0 || value > 255)
				return (false);
			while (ft_isdigit(digits[i]))
				i++;
		}
		else
			i++;
	}
	return (true);
}

bool	valid_range(t_map_vars map_vars)
{
	if (!valid_digits_range(map_vars.floor))
		return (false);
	if (!valid_digits_range(map_vars.ceiling))
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:55:10 by vsoares-          #+#    #+#             */
/*   Updated: 2026/08/14 23:55:10 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Handles mouse input events.
 * @param mousecode The code of the mouse event.
 * @param x The x-coordinate of the mouse event in the window.
 * @param y The y-coordinate of the mouse event in the window.
 * @return EXIT_SUCCESS after handling the mouse event.
 */
int	mouse_click_handler(int mousecode, int x, int y)
{
	if (mousecode == 1)
		debug(PURPLE "Left Click in %d-%d\n" RESET, x, y);
	else if (mousecode == 2)
		debug(PURPLE "Middle Click in %d-%d\n" RESET, x, y);
	else if (mousecode == 3)
		debug(PURPLE "Right Click in %d-%d\n" RESET, x, y);
	else if (mousecode == 4)
		debug(PURPLE "Scroll UP in %d-%d\n" RESET, x, y);
	else if (mousecode == 5)
		debug(PURPLE "Scroll DOWN in %d-%d\n" RESET, x, y);
	else if (mousecode == 6)
		debug(PURPLE "Scroll right in %d-%d\n" RESET, x, y);
	else if (mousecode == 7)
		debug(PURPLE "Scroll left in %d-%d\n" RESET, x, y);
	else
		debug("Unkown mouse action with code: %d, in %d-%d\n",
			mousecode, x, y);
	return (EXIT_SUCCESS);
}

int	mouse_move_handler(int x, int y)
{
	debug(YELLOW "Mouse moved to: %d-%d\n" RESET, x, y);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:29:00 by vsoares-          #+#    #+#             */
/*   Updated: 2026/05/19 21:33:28 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/time.h>

/**
 * @brief Closes the game window and frees resources.
 * @return EXIT_SUCCESS on successful exit.
 */
int	close_window(void)
{
	destroy_cub3d(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

/**
 * @brief Seconds elapsed since the previous call (0 on the very first call).
 *
 * Uses wall-clock time rather than the frame count so movement/rotation
 * speed stays the same regardless of how fast the (uncapped) main loop runs.
 */
static double	get_delta_time(void)
{
	static struct timeval	last;
	struct timeval			now;
	double					delta;

	gettimeofday(&now, NULL);
	if (last.tv_sec == 0 && last.tv_usec == 0)
		last = now;
	delta = (now.tv_sec - last.tv_sec)
		+ (now.tv_usec - last.tv_usec) / 1e6;
	last = now;
	return (delta);
}

static void	handle_input(double delta)
{
	if (keys()->forward)
		move_player(FORWARD, MOVE_SPEED * delta);
	if (keys()->backward)
		move_player(BACKWARD, MOVE_SPEED * delta);
	if (keys()->left)
		move_player(LEFT, MOVE_SPEED * delta);
	if (keys()->right)
		move_player(RIGHT, MOVE_SPEED * delta);
	if (keys()->rot_left)
		rotate_player(LEFT, ROT_SPEED * delta);
	if (keys()->rot_right)
		rotate_player(RIGHT, ROT_SPEED * delta);
}

int	loop_hook(void)
{
	handle_input(get_delta_time());
	render();
	return (EXIT_SUCCESS);
}

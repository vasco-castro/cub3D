/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:03:27 by vsoares-          #+#    #+#             */
/*   Updated: 2026/09/13 17:03:27 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Recomputes the camera vectors from the angle.
 *
 * dir is the unit vector the player faces, taken straight from the angle
 * with no sign to undo: north is up on the map, and screen y grows down, so
 * the spawn angles in set_player_dir are picked to match.
 *
 * plane is perpendicular to dir, pointing to the player's right, and
 * tan(HALF_FOV) long. Its two tips are the edges of the field of view, so
 * dir + plane * camera_x sweeps the whole view as camera_x runs -1 to +1.
 */
void	update_player_vectors(void)
{
	player()->dir.x = cos(player()->angle);
	player()->dir.y = sin(player()->angle);
	player()->plane.x = -player()->dir.y * tan(HALF_FOV);
	player()->plane.y = player()->dir.x * tan(HALF_FOV);
}

void	rotate_player(t_direction d, double speed)
{
	if (d == LEFT)
		player()->angle -= speed;
	else if (d == RIGHT)
		player()->angle += speed;
	update_player_vectors();
}

/**
 * @brief Moves the player one step, unless a wall is in the way.
 *
 * Strafing is the forward vector turned a quarter turn, which swaps the two
 * components and negates one of them. Only flipping signs would mirror the
 * vector instead of turning it, and you would slide along the wrong axis.
 *
 * Backward is forward negated, and right is left negated, so the four cases
 * are one vector and two flips.
 */
void	move_player(t_direction d, double speed)
{
	t_dpoint	step;
	t_dpoint	next;

	step = get_dpoint(player()->dir.x * speed, player()->dir.y * speed);
	if (d == LEFT || d == RIGHT)
		step = get_dpoint(step.y, -step.x);
	if (d == BACKWARD || d == RIGHT)
		step = get_dpoint(-step.x, -step.y);
	next = get_dpoint(player()->pos.x + step.x, player()->pos.y + step.y);
	if (!is_wall(next.x, next.y))
		player()->pos = next;
}

/**
 * @brief Handles key-press events by flipping the matching key state on.
 * @param keycode The code of the key pressed.
 * @return EXIT_SUCCESS after handling the key event.
 */
int	key_down_handler(int keycode)
{
	if (keycode == KEY_ESCAPE)
		return (close_window());
	if (keycode == KEY_W)
		keys()->forward = true;
	else if (keycode == KEY_S)
		keys()->backward = true;
	else if (keycode == KEY_A)
		keys()->left = true;
	else if (keycode == KEY_D)
		keys()->right = true;
	else if (keycode == KEY_LEFT)
		keys()->rot_left = true;
	else if (keycode == KEY_RIGHT)
		keys()->rot_right = true;
	else if (keycode == KEY_L_SHIFT)
		keys()->run = true;
	else if (keycode == KEY_M)
		keys()->minimap = !keys()->minimap;
	else if (keycode == KEY_BACKSLASH)
		change_debug_mode(true);
	else
		debug("Key pressed: %d\n", keycode);
	return (EXIT_SUCCESS);
}

/**
 * @brief Handles key-release events by flipping the matching key state off.
 * @param keycode The code of the key released.
 * @return EXIT_SUCCESS after handling the key event.
 */
int	key_up_handler(int keycode)
{
	if (keycode == KEY_W)
		keys()->forward = false;
	else if (keycode == KEY_S)
		keys()->backward = false;
	else if (keycode == KEY_A)
		keys()->left = false;
	else if (keycode == KEY_D)
		keys()->right = false;
	else if (keycode == KEY_LEFT)
		keys()->rot_left = false;
	else if (keycode == KEY_RIGHT)
		keys()->rot_right = false;
	else if (keycode == KEY_L_SHIFT)
		keys()->run = false;
	else
		debug("Key released: %d\n", keycode);
	return (EXIT_SUCCESS);
}

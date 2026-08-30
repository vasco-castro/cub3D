
#include "cub3d.h"

/**
 * @brief Recomputes the direction and the two FOV edge rays from the angle.
 *
 * plane1 and plane2 are unit vectors sitting HALF_FOV radians either side of
 * the direction, so the angle they span is exactly FOV degrees.
 */
void	update_player_vectors(void)
{
	player()->dir.x = cos(player()->angle);
	player()->dir.y = sin(player()->angle);
	player()->plane1.x = cos(player()->angle + HALF_FOV);
	player()->plane1.y = sin(player()->angle + HALF_FOV);
	player()->plane2.x = cos(player()->angle - HALF_FOV);
	player()->plane2.y = sin(player()->angle - HALF_FOV);
}

void	rotate_player(t_direction d, double speed)
{
	if (d == LEFT)
		player()->angle -= speed;
	else if (d == RIGHT)
		player()->angle += speed;
	update_player_vectors();
}

void	move_player(t_direction d, double speed)
{
	if (d == FORWARD)
	{
		player()->pos.x -= player()->dir.x * speed;
		player()->pos.y -= player()->dir.y * speed;
	}
	else if (d == BACKWARD)
	{
		player()->pos.x += player()->dir.x * speed;
		player()->pos.y += player()->dir.y * speed;
	}
	else if (d == LEFT)
	{
		player()->pos.x -= player()->dir.y * speed;
		player()->pos.y += player()->dir.x * speed;
	}
	else if (d == RIGHT)
	{
		player()->pos.x += player()->dir.y * speed;
		player()->pos.y -= player()->dir.x * speed;
	}
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
	// else if (keycode == KEY_M)
	// 	keys()->minimap = false;
	else
		debug("Key released: %d\n", keycode);
	return (EXIT_SUCCESS);
}


#include "cub3d.h"

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

void	rotate_player(t_direction d, double speed)
{
	if (d == LEFT)
		player()->angle -= speed;
	else if (d == RIGHT)
		player()->angle += speed;
	player()->dir.x = cos(player()->angle);
	player()->dir.y = sin(player()->angle);
}

/**
 * @brief Handles key-press events by flipping the matching key state on.
 * @param keycode The code of the key pressed.
 * @return EXIT_SUCCESS after handling the key event.
 */
int	key_down_handler(int keycode)
{
	if (keycode == ESCAPE_KEY || keycode == CLOSE_KEY)
		return (close_window());
	if (keycode == W_KEY)
		keys()->forward = true;
	else if (keycode == S_KEY)
		keys()->backward = true;
	else if (keycode == A_KEY)
		keys()->left = true;
	else if (keycode == D_KEY)
		keys()->right = true;
	else if (keycode == LEFT_KEY)
		keys()->rot_left = true;
	else if (keycode == RIGHT_KEY)
		keys()->rot_right = true;
	else
		debug("Pressed key: %d\n", keycode);
	return (EXIT_SUCCESS);
}

/**
 * @brief Handles key-release events by flipping the matching key state off.
 * @param keycode The code of the key released.
 * @return EXIT_SUCCESS after handling the key event.
 */
int	key_up_handler(int keycode)
{
	if (keycode == W_KEY)
		keys()->forward = false;
	else if (keycode == S_KEY)
		keys()->backward = false;
	else if (keycode == A_KEY)
		keys()->left = false;
	else if (keycode == D_KEY)
		keys()->right = false;
	else if (keycode == LEFT_KEY)
		keys()->rot_left = false;
	else if (keycode == RIGHT_KEY)
		keys()->rot_right = false;
	return (EXIT_SUCCESS);
}

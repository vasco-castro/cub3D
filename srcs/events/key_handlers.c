
#include "cub3d.h"

/**
 * @brief Handles keyboard input events.
 * @param keycode The code of the key pressed.
 * @return EXIT_SUCCESS after handling the key event.
 */
int	key_handler(int keycode)
{
	if (keycode == ESCAPE_KEY || keycode == CLOSE_KEY)
		return (close_window());
	else if (keycode == W_KEY)
	{
		debug(CYAN "Player moved front!\n" RESET);
		player()->pos.y--;
	}
	else if (keycode == A_KEY)
	{
		debug(CYAN "Player moved left!\n" RESET);
		player()->pos.x--;
	}
	else if (keycode == S_KEY)
	{
		debug(CYAN "Player moved back!\n" RESET);
		player()->pos.y++;
	}
	else if (keycode == D_KEY)
	{
		debug(CYAN "Player moved right!\n" RESET);
		player()->pos.x++;
	}
	else if (keycode == LEFT_KEY)
	{
		debug(CYAN "Player looked left!\n" RESET);
		player()->dir.x++;
	}
	else if (keycode == RIGHT_KEY)
	{
		debug(CYAN "Player looked right!\n" RESET);
		player()->dir.y--;
	}
	else
		debug("Pressed key: %d\n", keycode);
	return (EXIT_SUCCESS);
}

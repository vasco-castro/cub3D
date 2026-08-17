
#include "cub3d.h"

void	move_player(t_direction d)
{
	debug(CYAN "Player moved!\n" RESET);
	if (d == FORWARD)
	{
		player()->pos.x-=player()->dir.x/10;
		player()->pos.y-=player()->dir.y/10;
	}
	else if (d == BACKWARD)
	{
		player()->pos.x+=player()->dir.x/10;
		player()->pos.y+=player()->dir.y/10;
	}
	else if (d == LEFT)
	{
		player()->pos.x-=player()->dir.y/10;
		player()->pos.y+=player()->dir.x/10;
	}
	else if (d == RIGHT)
	{
		player()->pos.x+=player()->dir.y/10;
		player()->pos.y-=player()->dir.x/10;
	}
}

void	rotate_player(t_direction d)
{
	debug(CYAN "Player rotated!\n" RESET);
	if (d == LEFT)
	{
		player()->angle-=0.25;
		player()->dir.x=cos(player()->angle);
		player()->dir.y=sin(player()->angle);
	}
	else if (d == RIGHT)
	{
		player()->angle+=0.25;
		player()->dir.x=cos(player()->angle);
		player()->dir.y=sin(player()->angle);
	}
}

/**
 * @brief Handles keyboard input events.
 * @param keycode The code of the key pressed.
 * @return EXIT_SUCCESS after handling the key event.
 */
int	key_handler(int keycode)
{
	if (keycode == ESCAPE_KEY || keycode == CLOSE_KEY)
		return (close_window());
	if (keycode == W_KEY)
		move_player(FORWARD);
	else if (keycode == A_KEY)
		move_player(LEFT);
	else if (keycode == S_KEY)
		move_player(BACKWARD);
	else if (keycode == D_KEY)
		move_player(RIGHT);
	else if (keycode == LEFT_KEY)
		rotate_player(LEFT);
	else if (keycode == RIGHT_KEY)
		rotate_player(RIGHT);
	else
		debug("Pressed key: %d\n", keycode);
	return (EXIT_SUCCESS);
}


#include "cub3d.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

t_player	*player(void)
{
	static t_player	player;

	return (&player);
}

t_keys	*keys(void)
{
	static t_keys	keys;

	return (&keys);
}

#include "cub3d.h"

static void	render_bg(void)
{
	int	y;

	y = 0;
	while (y < W_HEIGHT / 2)
	{
		put_line(get_point(0, y), get_point(W_WIDTH - 1, y), map()->ceiling);
		y++;
	}
	while (y < W_HEIGHT)
	{
		put_line(get_point(0, y), get_point(W_WIDTH - 1, y), map()->floor);
		y++;
	}
}

static void	render_walls(void)
{
}

void	render(void)
{
	int	minimap_low_pos;
	int	minimap_right_pos;

	clear_image(&game()->screen, 0x00000000);
	render_bg();
	render_walls();
	if (keys()->minimap)
	{
		minimap_low_pos = W_HEIGHT
			- ((2 * MINIMAP_RADIUS + 1) * map()->minimap_scale);
		minimap_right_pos = W_WIDTH
			- ((2 * MINIMAP_RADIUS + 1) * map()->minimap_scale);
		if (MINIMAP_POS == MINIMAP_UL)
			render_minimap(0, 0);
		else if (MINIMAP_POS == MINIMAP_LL)
			render_minimap(0, minimap_low_pos);
		else if (MINIMAP_POS == MINIMAP_UR)
			render_minimap(minimap_right_pos, 0);
		else if (MINIMAP_POS == MINIMAP_LR)
			render_minimap(minimap_right_pos, minimap_low_pos);
		else
			render_minimap(0, 0);
	}
	display_image(&game()->screen, 0, 0);
}

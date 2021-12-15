#include "so_long_bonus.h"

int	my_mlx_pixel_get(t_img t, int x, int y)
{
	int	color;
	int	*int_addr;

	int_addr = (int *)t.addr;
	color = int_addr[y * t.width + (x * t.width)];
	return (color);
}

int	color_trans(t_img *tex, char *color)
{
	int		transparancy;
	int		actual;
	int		background;

	background = 0xFFFFFF;
	if (!tex)
		return (background);
	transparancy = my_mlx_pixel_get(*tex, 0, 0);
	actual = *(int *)color;
	if (actual == transparancy)
		return (background);
	else
		return (actual);
}

void	draw(t_game *game, int x, int y)
{
	t_coord	pos;
	char	*color;
	t_img	*tex;

	tex = texture_choice(game, game->map[y][x]);
	pos.y = 0;
	while (pos.y < 40)
	{
		pos.x = 0;
		while (pos.x < 40)
		{
			color = "";
			if (tex)
				color = get_sprite_color(tex, pos.x, pos.y, 40);
			if (color != NULL)
				my_mlx_pixel_put(&game->img, (x * 40) + pos.x, (y * 40) + pos.y, color_trans(tex, color));
			pos.x++;
		}
		pos.y++;
	}
}

char	*get_sprite_color(t_img *tex, int x, int y, int cubesize)
{
	int		txt_x;
	int		txt_y;
	char	*color;

	txt_x = 0;
	txt_y = 0;
	txt_x = tex->width / (100 / (((double)x / cubesize) * 100.0));
	txt_y = tex->height / (100 / (((double)y / cubesize) * 100.0));
	color = tex->addr + ((4 * tex->width * txt_y) + (4 * txt_x));
	return (color);
}

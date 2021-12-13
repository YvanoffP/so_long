#include "so_long.c"

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

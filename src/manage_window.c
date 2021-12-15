#include "so_long.h"

void	my_mlx_pixel_put(t_img *sprite, int x, int y, int color)
{
	char	*dst;

	dst = sprite->addr + (y * sprite->line_length + x * (sprite->bits_pixel / 8));
	*(unsigned int*)dst = color;
}

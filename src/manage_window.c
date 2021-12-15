#include "so_long.h"

void	my_mlx_pixel_put(t_img *sprite, int x, int y, int color)
{
	char	*dst;

	//if (x && y) en gros, si x ou t vaut 0 on multiplie par 1 et pas par 0
	dst = sprite->addr + (y * sprite->line_length + x * (sprite->bits_pixel / 8));
	*(unsigned int*)dst = color;
}	iii

#include "so_long.h"

void	texture_load(t_game **game)
{
	load_one_texture(*game, &(*game)->player, "./img/player.xpm");
	load_one_texture(*game, &(*game)->wall, "./img/wall.xpm");
	load_one_texture(*game, &(*game)->door, "./img/door.xpm");
	load_one_texture(*game, &(*game)->item, "./img/item.xpm");
}

void	load_one_texture(t_game *game, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_pixel, &tex->line_length, &tex->endian);
}

t_img	*texture_choice(t_game *game, char c)
{
	if (c == 'P')
		return (&game->player);
	else if (c == '1')
		return (&game->wall);
	else if (c == 'E')
		return (&game->door);
	else if (c == 'C')
		return (&game->item);
	else if (c == '0')
		return (NULL);
	return (NULL);
}

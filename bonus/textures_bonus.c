#include "so_long_bonus.h"

void	texture_load(t_game **game)
{
	load_one_texture(*game, &(*game)->sprite.player_1, "./img/player_1.xpm");
	load_one_texture(*game, &(*game)->sprite.player_2, "./img/player_2.xpm");
	load_one_texture(*game, &(*game)->sprite.wall, "./img/wall.xpm");
	load_one_texture(*game, &(*game)->sprite.door, "./img/door.xpm");
	load_one_texture(*game, &(*game)->sprite.item, "./img/item.xpm");
	(*game)->sprite.player = (*game)->sprite.player_1;
}

void	load_one_texture(t_game *game, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_pixel, &tex->line_length, &tex->endian);
}

t_img	*texture_choice(t_game *game, char c)
{
	if (c == 'P')
		return (&game->sprite.player);
	else if (c == '1')
		return (&game->sprite.wall);
	else if (c == 'E')
		return (&game->sprite.door);
	else if (c == 'C')
		return (&game->sprite.item);
	else if (c == '0')
		return (NULL);
	return (NULL);
}

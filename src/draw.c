#include "so_long.h"

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

void	game_init(t_game *game)
{
	int x = 0, y = 0;;

	game->mlx = mlx_init();
	create_window(game);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_pixel, &game->img.line_length, &game->img.endian);
	texture_load(&game);
	hook_init(game);
	draw_frame(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, x, y);
	mlx_loop(game->mlx);
}

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

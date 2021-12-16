#include "so_long_bonus.h"

int	get_array_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_size(t_coord res, char **map)
{
	t_coord	size;
	int	len_line;
	int	len_array;

	len_line = ft_strlen(*map);
	len_array = get_array_size(map);
	size.x = res.x / len_line;
	size.y = res.y / len_array;
	if (size.x <= size.y)
	{
		if (size.y * len_line > res.x)
			size.y = size.x - 1;
	}
	else
	{
		if (size.x * len_array > res.y)
			size.x = size.y - 1;
	}
	if (size.x < size.y)
	{
		if (size.x < 1)
			return (1);
		return (size.x);
	}
	return (size.y);
}

void	create_window(t_game *game)
{
	//mlx_get_screen_size(game->mlx, &game->screen_res.x, &game->screen_res.y);
	game->screen_res.x = ft_strlen(*game->map) * 40;
	game->screen_res.y = get_array_size(game->map) * 40;
	game->size = get_size(game->screen_res, game->map);
	game->screen_res.x = game->size * ft_strlen(*game->map);
	game->screen_res.y = game->size * get_array_size(game->map);
	game->mlx_win = mlx_new_window(game->mlx, game->screen_res.x, game->screen_res.y, "so_long");
	game->img.img = mlx_new_image(game->mlx, game->screen_res.x, game->screen_res.y);
}

void	draw_frame(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			draw(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

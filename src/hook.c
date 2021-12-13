#include "so_long.h"

int	keypress(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
		exit_game(game);
	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT
		|| keycode == W || keycode == S
		|| keycode == A || keycode == D)
		move_player(game, keycode);
	return (keycode);
}

int	redraw(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (1);
}

void	hook_init(t_game *game)
{
	mlx_hook(game->mlx_win, 17, (1L << 0), exit_game, game);
	mlx_loop_hook(game->mlx, redraw, game);
	mlx_hook(game->mlx_win, 2, (1L << 0), keypress, game);
	mlx_do_key_autorepeaton(game->mlx);
}

#include "so_long_bonus.h"

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

void	anim(t_game *game, int *i)
{
	static int	flag = 0;

	if (*i >= 20)
	{
		if (flag == 0)
		{
			game->sprite.player = game->sprite.player_1;
			game->sprite.item = game->sprite.item_1;
			flag = 1;
		}
		else if (flag == 1)
		{
			game->sprite.player = game->sprite.player_2;
			game->sprite.item = game->sprite.item_2;
			flag = 0;
		}
		move_enemy(game);
		draw_frame(game);
		print_move(game);
		*i = 0;
	}
}

int	redraw(t_game *game)
{
	static int	i = 0;

	anim(game, &i);
	i++;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	print_move(game);
	return (1);
}

void	hook_init(t_game *game)
{
	mlx_hook(game->mlx_win, 17, (1L << 0), exit_game, game);
	mlx_loop_hook(game->mlx, redraw, game);
	mlx_hook(game->mlx_win, 2, (1L << 0), keypress, game);
	mlx_do_key_autorepeaton(game->mlx);
}

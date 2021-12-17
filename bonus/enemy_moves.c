#include "so_long_bonus.h"

int	enemy_next_move(t_game *game, int next_x)
{
	if (game->map[game->enemy_pos.y][next_x] == '1'
		|| game->map[game->enemy_pos.y][next_x] == 'E'
		|| game->map[game->enemy_pos.y][next_x] == 'C')
		return (0);
	else if (game->map[game->enemy_pos.y][next_x] == 'P')
	{
		ft_putstr_fd("                            \r", STDOUT_FILENO);
		ft_putstr_fd("You died, avoid the monster !\n", STDOUT_FILENO);
		exit_game(game);
	}
	return (1);
}

static void	set_enemy_pos(t_game *game, int x)
{
	game->map[game->enemy_pos.y][game->enemy_pos.x] = '0';
	game->map[game->enemy_pos.y][x] = 'M';
	game->enemy_pos.x = x;
	
}

void	move_enemy(t_game *game)
{
	static int	flag = 0;
	int		x;

	x = 0;
	if (flag == 0)
	{
		x = game->enemy_pos.x + 1;
		if (enemy_next_move(game, x) == 0)
			flag = 1;
		else
			set_enemy_pos(game, x);
	}
	else if (flag == 1)
	{
		x = game->enemy_pos.x - 1;
		if (enemy_next_move(game, x) == 0)
			flag = 0;
		else
			set_enemy_pos(game, x);
	}
}

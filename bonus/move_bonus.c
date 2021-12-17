#include "so_long_bonus.h"

void	move_player(t_game *game, int side)
{
	t_coord	pos;

	pos = (t_coord){.x = game->player_pos.x, .y = game->player_pos.y};
	if (side == LEFT || side == D)
	{
		pos.x = game->player_pos.x - 1;
		move(game, pos, "Move left");
	}
	else if (side == RIGHT || side == A)
	{
		pos.x = game->player_pos.x + 1;
		move(game, pos, "Move right");
	}
	else if (side == UP || side == W)
	{
		pos.y = game->player_pos.y - 1;
		move(game, pos, "Move up");
	}
	else if (side == DOWN || side == S)
	{
		pos.y = game->player_pos.y + 1;
		move(game, pos, "Move down");
	}
}

void	move(t_game *game, t_coord next, char *str)
{
	if (is_valid_position(game, next) == 1)
	{
		if (game->map[next.y][next.x] == 'E')
		{
			if (game->coin_count == 0)
				winning_move(game, str);
			else
				ft_putendl_fd("You must collect all coins before exiting !", STDOUT_FILENO);
		}
		if (game->map[next.y][next.x] == 'M')
			killed_move(game, str);
		if (game->map[next.y][next.x] == '0'
			|| game->map[next.y][next.x] == 'C')
			collect_coin_move(game, str, next);
	}
}

int	is_valid_position(t_game *game, t_coord next)
{
	int	out;

	out = ((next.x > 0 && next.x < (int)ft_strlen(*game->map))
			&& (next.y > 0 && next.y < (int)get_array_size(game->map)));
	return (out);
}

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
			{
				write_move(game, str);
				ft_putstr_fd("                            \r", STDOUT_FILENO);
				ft_putstr_fd("You win\n", STDOUT_FILENO);
				exit_game(game);
			}
			else
				ft_putendl_fd("You must collect all coins before exiting !", STDOUT_FILENO);
		}
		if (game->map[next.y][next.x] == 'M')
		{
			ft_putstr_fd("                            \r", STDOUT_FILENO);
			ft_putstr_fd("You died, avoid the monster !\n", STDOUT_FILENO);
			exit_game(game);
		}
		if (game->map[next.y][next.x] == '0'
			|| game->map[next.y][next.x] == 'C')
		{
			if (game->map[next.y][next.x] == 'C')
				game->coin_count--;
			if (game->coin_count == 0)
				game->sprite.door = game->sprite.door_2;
			game->map[next.y][next.x] = 'P';
			game->map[game->player_pos.y][game->player_pos.x] = '0';
			game->player_pos.x = next.x;
			game->player_pos.y = next.y;
			write_move(game, str);
		}
	}
}

int	is_valid_position(t_game *game, t_coord next)
{
	int	out;

	out = ((next.x > 0 && next.x < (int)ft_strlen(*game->map))
			&& (next.y > 0 && next.y < (int)get_array_size(game->map)));
	return (out);
}

void    print_move(t_game *game)
{
	int        color;
	char	*move_count;
	int        x;
    	int        y;

	y = 0;
	while (y < 25 && y < game->screen_res.y)
	{
		x = 0;
		while (x < 100 && x < game->screen_res.x)
			my_mlx_pixel_put(&game->img, x++, y, 0x00000000);
		y++;
	}
	move_count = ft_itoa(game->move_count);
	color = 0x00FF0000;
	mlx_string_put(game->mlx, game->mlx_win, 10, 17, color, "Moves: ");
	mlx_string_put(game->mlx, game->mlx_win, 60, 17, color, move_count);
	free(move_count);
}

void	write_move(t_game *game, char *str)
{
	ft_putstr_fd("                                ", STDOUT_FILENO);
	ft_putstr_fd("\r", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	ft_putstr_fd(", count: ", STDOUT_FILENO);
	ft_putnbr_fd(++game->move_count, STDOUT_FILENO);
	ft_putstr_fd("\r", STDOUT_FILENO);
	draw_frame(game);
	print_move(game);
	redraw(game);
}

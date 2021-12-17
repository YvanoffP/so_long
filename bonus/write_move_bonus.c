/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:44:27 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/12/17 14:54:54 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_move(t_game *game)
{
	int		color;
	char	*move_count;
	int		x;
	int		y;

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

void	winning_move(t_game *game, char *str)
{
	write_move(game, str);
	ft_putstr_fd("                            \r", STDOUT_FILENO);
	ft_putstr_fd("You win\n", STDOUT_FILENO);
	exit_game(game);
}

void	killed_move(t_game *game)
{
	ft_putstr_fd("                            \r", STDOUT_FILENO);
	ft_putstr_fd("You died, avoid the monster !\n", STDOUT_FILENO);
	exit_game(game);
}

void	collect_coin_move(t_game *game, char *str, t_coord next)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:44:02 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/12/17 14:16:49 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game, int argc, char **argv)
{
	game->screen_res.x = 0;
	game->screen_res.y = 0;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	game->coin_count = 0;
	game->move_count = 0;
	parsing_map(argc, argv, game);
}

void	game_init(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->mlx = mlx_init();
	create_window(game);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_pixel, &game->img.line_length, &game->img.endian);
	save_window(game);
	texture_load(&game);
	hook_init(game);
	draw_frame(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img.img, x, y);
	mlx_loop(game->mlx);
}

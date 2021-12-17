/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:26:43 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/12/17 16:11:16 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clear_array(char **map)
{
	int	i;

	i = 0;
	while (map[i++])
		free(map[i]);
	free(map);
}

t_game	*save_window(t_game *game)
{
	static t_game	*game_backup = NULL;

	if (game != NULL)
		game_backup = game;
	return (game_backup);
}

int	exit_game(t_game *game)
{
	game = save_window(NULL);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_image(game->mlx, game->sprite.player.img);
	mlx_destroy_image(game->mlx, game->sprite.item.img);
	mlx_destroy_image(game->mlx, game->sprite.wall.img);
	mlx_destroy_image(game->mlx, game->sprite.door.img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	clear_array(game->map);
	free(game->mlx);
	exit(0);
	return (0);
}

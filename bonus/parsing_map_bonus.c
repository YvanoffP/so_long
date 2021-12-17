/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:36:55 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/12/17 14:55:35 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	parsing_map(int argc, char **argv, t_game *game)
{
	int		i;
	int		fd;
	int		nb_lines;
	t_map	data;

	i = 0;
	nb_lines = count_lines(argc, argv);
	init(&data, nb_lines);
	fd = open(argv[1], O_RDONLY);
	game->map = malloc(sizeof(char *) * nb_lines + 1);
	if (!game->map)
		return ;
	while (nb_lines-- > 0)
	{
		game->map[i] = get_line(fd, &data, i, game);
		i++;
	}
	game->map[i] = 0;
	if (close(fd) == -1)
		exit(0);
	check_data(data);
	check_wall(game->map, data);
	game->coin_count = data.coin;
}

void	write_error(void)
{
	write(1, "Error wall\n", 11);
	exit(0);
}

void	check_wall(char **map, t_map data)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]) - 1;
	while (i != data.nb_lines)
	{
		if (len == ft_strlen(map[i]) - 1)
			i++;
		else
			write_error();
	}
	check_wall_2(map, data);
	check_wall_3(map, len);
}

void	check_wall_2(char **map, t_map data)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == '1')
			i++;
		else
			write_error();
	}
	i = 0;
	while (map[data.nb_lines][i])
	{
		if (map[data.nb_lines][i] == '1')
			i++;
		else
			write_error();
	}
}

void	check_wall_3(char **map, size_t len)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '1')
			i++;
		else
			write_error();
	}
	i = 0;
	while (map[i])
	{
		if (map[i][len] == '1')
			i++;
		else
			write_error();
	}
	if (i >= (int)len)
	{
		write(1, "Map is not rectangular\n", 23);
		exit(0);
	}
}

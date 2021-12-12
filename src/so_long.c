#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = parsing_map(argc, argv);
	draw_map(&game);
}

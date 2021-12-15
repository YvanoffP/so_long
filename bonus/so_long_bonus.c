#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_struct(&game, argc, argv);
	game_init(&game);
	return (0);
}

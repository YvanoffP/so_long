#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.player_pos.x = 0;
	game.player_pos.y = 0;

	game.map = parsing_map(argc, argv, &game);
	printf("%i, %i\n", game.player_pos.x, game.player_pos.y);
	game_init(&game);
}

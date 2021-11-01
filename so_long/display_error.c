#include "so_long.c"

int	error_map_display(t_map_checker_flags flags)
{
	printf("Error\nInvalid map.\n");
	if (flags.char_error)
		printf("An unauthorized char was sent\n");
	else if (flags.wall_error)
		printf("A missing wall has been detected\n");
	else if (flags.size_error)
		printf("The map must be rectangular\n");
	else if (!flags.e)
		printf("The map has no exit\n");
	else if (!flags.c)
		printf("\nThe map has no collectible\n");
	else if (!flags.p)
		printf("The map has no player spawn\n");
	return (-1);
}

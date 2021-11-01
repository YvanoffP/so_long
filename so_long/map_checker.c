#include "so_long.h"

int	map_checker(t_map *map, int len)
{
	int			index;
	t_map_checker_flags	flags;

	flags_struct_init(&flags);
	first_n_last_check(map->map_line, &flags);
	while (map != NULL && flags.error != 1)
	{
		index = 0;
		while (map->map_line[index] != '\0' && flags.error != 1)
		{
			is_allowed_char(map->map_line[index], &flags);
			if (index == 0 || index == (len - 2))
				wall_checker(map->map_line[index], &flags);
			index++;
		}
		if (map->next == NULL || flags.error == 1)
			break ;
		map = map->next;
		line_len_check(len, map->map_line, &flags);
	}
	if (flags.error != 1)
		first_n_last_check(map->map_line, &flags);
	if (flags.error == 1 || flags.p != 1 || flags.e != 1 || flags.c != 1)
		return (error_map_display(flags));
	return (0);
}

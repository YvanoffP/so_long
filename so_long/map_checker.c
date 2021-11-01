#include "so_long.h"

// Can only have 0 1 C E P
// The map must be surrounded my walls (11111)
// Need at least one E C P
// Map must be rectangular

int	line_len_check(int len, t_map	map)
{
	if ((int)ft_strlen(map->map_line) != len)
		return (-1);
	else	
		return (0);
}

void	ecp_struct_init(t_map_checher_flags *flags)
{
	flags->e = 0;
	flags->c = 0;
	flags->p = 0;
	flags->char_error = 0;
	flags->wall_error = 0;
	flags->size_error = 0;
}

int	is_allowed_char(char c, t_map_checher_flags *flags)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C' || c == 'P')
	{
		if (c == 'E')
			flags->e = 1;
		if (c == 'C')
			flags->c = 1;
		if (c == 'P')
			flags->p = 1;
		return (0);
	}
	else
	{
		flags->char_error = 1;
		return (-1);
	}
}

int	map_checker(t_map *map)
{
	int			index;
	int			len;
	t_map_checher_flags	flags;

	ecp_struct_init(&flags);
	len = (int)ft_strlen(map->map_line);
	while (map != NULL)
	{
		index = 0;
		while (map->map_line[index] != '\0')
		{
			if (!is_allowed_char(map->map_line[index]))
				break ; // TODO : error gestion
			index++;
		}
		line_len_check(len, map);
	}

}

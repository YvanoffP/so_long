#include "so_long.h"

// Can only have 0 1 C E P
// The map must be surrounded my walls (11111)
// Need at least one E C P
// Map must be rectangular

void	line_len_check(int len, char *line, t_map_checker_flags *flags)
{
	if ((int)ft_strlen(line) != len)
	{
		flags->error = 1;
		flags->size_error = 1;
	}
}

void	ecp_struct_init(t_map_checker_flags *flags)
{
	flags->e = 0;
	flags->c = 0;
	flags->p = 0;
	flags->error = 0;
	flags->char_error = 0;
	flags->wall_error = 0;
	flags->size_error = 0;
}

void	is_allowed_char(char c, t_map_checker_flags *flags)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C' || c == 'P' || c == '\n')
	{
		if (c == 'E')
			flags->e = 1;
		if (c == 'C')
			flags->c = 1;
		if (c == 'P')
			flags->p = 1;
	}
	else
	{
		flags->error = 1;
		flags->char_error = 1;
	}
}

void	wall_checker(char c, t_map_checker_flags *flags)
{
	if (c != '1')
	{
		flags->error = 1;
		flags->wall_error = 1;
	}
}

void	first_n_last_check(char *line, t_map_checker_flags *flags)
{
	int	index;

	index = 0;
	while (line[index] != '\n' && line[index] == '1')
		index++;
	if (line[index] != '1' && line[index] != '\n')
	{
		flags->error = 1;
		flags->wall_error = 1;
	}
}

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

int	map_checker(t_map *map)
{
	int			index;
	int			len;
	t_map_checker_flags	flags;

	ecp_struct_init(&flags);
	len = (int)ft_strlen(map->map_line);
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
	if (flags.p != 1 || flags.e != 1 || flags.c != 1)
		flags.error = 1;
	if (flags.error != 1)
		first_n_last_check(map->map_line, &flags);
	if (flags.error == 1)
		return (error_map_display(flags)); //return a func that will track what kind of error occured
	return (0);
}

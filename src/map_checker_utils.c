#include "so_long.h"

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

void	line_len_check(int len, char *line, t_map_checker_flags *flags)
{
	if ((int)ft_strlen(line) != len)
	{
		flags->error = 1;
		flags->size_error = 1;
	}
}

void	flags_struct_init(t_map_checker_flags *flags)
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

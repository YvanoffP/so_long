#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_map_checker_flags
{
	int	e;
	int	c;
	int	p;
	int	error;
	int	char_error;
	int	wall_error;
	int	size_error;
}		t_map_checker_flags;

typedef struct	s_map
{
	char		*map_line;
	struct s_map	*next;
}		t_map;

# include "get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>

// LST
t_map	*ft_lst_new(char *map_tmp);
t_map	*ft_lstlast_cust(t_map *lst);
void	ft_lst_add_line(t_map **map, t_map *new_map_line);
int		ft_lstsize(t_list *lst);

// MAP
int		map_checker(t_map *map, int len);
t_map	*map_reader(int fd);
void	map_parsing();
void	map_printer(t_map *map);
void	first_n_last_check(char *line, t_map_checker_flags *flags);
void    line_len_check(int len, char *line, t_map_checker_flags *flags);
void    flags_struct_init(t_map_checker_flags *flags);
void    is_allowed_char(char c, t_map_checker_flags *flags);
void    wall_checker(char c, t_map_checker_flags *flags);

// ERRORS
int     error_map_display(t_map_checker_flags flags);
#endif

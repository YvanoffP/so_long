#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_map
{
	char		*map_line;
	struct s_map	*next;
}		t_map;

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>

t_map	*ft_lst_new(char *map_tmp);
t_map	*ft_lstlast_cust(t_map *lst);
void	ft_lst_add_line(t_map **map, t_map *new_map_line);

#endif

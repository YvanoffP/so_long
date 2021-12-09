#include "so_long.h"

t_map	*ft_lst_new(char *map_tmp)
{
	t_map	*cell;

	cell = malloc(sizeof(t_map));
	if (!cell)
		return (NULL);
	cell->map_line = map_tmp;
	cell->next = NULL;
	return (cell);
}

t_map	*ft_lstlast_cust(t_map *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_lst_add_line(t_map **map, t_map *new_map_line)
{
	t_map	*tmp;

	if (*map)
	{
		tmp = ft_lstlast_cust(*map);
		tmp->next = new_map_line;
	}
	else
		*map = new_map_line;
}

void	ft_lst_size(

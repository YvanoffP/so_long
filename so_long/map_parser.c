#include "so_long.h"

void	map_printer(t_map *map)
{
	while (map != NULL)
	{
		printf("%s", map->map_line);
		map = map->next;
	}

}

t_map	*map_reader(int fd)
{
	char	*map_line;
	t_map	*map;
	t_map	*map_tmp;

	map_line = get_next_line(fd);
	map = ft_lst_new(map_line);
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		map_tmp = ft_lst_new(map_line);
		ft_lst_add_line(&map, map_tmp);
		map_line = get_next_line(fd);
	}
	map_printer(map);
	return (map);
}

void	map_parsing()
{
	t_map	*map;
	
	map = map_reader(open("../maps/map_error_no_e.ber", O_RDONLY));
	if (map_checker(map) != 0)
		return ;;
}
int	main(void)
{
	map_parsing();
	return(1);
}

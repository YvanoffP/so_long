#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**tab;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	t_map	map;
	int x = 100, y = 300;
	char *relative_path = "img/wall.xpm";

	tab = parsing_map(argc, argv);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024, 720, "so_long");
	map.img = mlx_new_image(mlx, 1024, 720);
	map.addr = mlx_get_data_addr(map.img, &map.bits_pixel, &map.line_length, &map.endian);
	img = mlx_xpm_file_to_image(mlx, relative_path, &x, &y);
	printf("%s\n", img);
	
	mlx_loop(mlx);
	return (0);
}

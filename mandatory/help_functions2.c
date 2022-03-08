#include "so_long.h"

int ft_close()
{
	exit(0);
}

t_window	create_new_window(void	*mlx, t_map	map)
{
	t_window window;

	window.height = map.height * 32;
	window.width = map.width * 32;
	window.ptr = mlx_new_window(mlx, window.width, window.height, "cnearing so_long :)");
	mlx_hook(window.ptr, 17, 0, ft_close, 0);
	return (window);
}
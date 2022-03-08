#include "so_long.h"

void	draw_freespace(t_programm programm, int	x, int	y)
{
	programm.image = create_image(programm.mlx, "textures/free_space.xpm");
//	programm.image.start_x = x;
//	programm.image.start_y = y;
	mlx_put_image_to_window(programm.mlx, programm.window.ptr, programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}

void	draw_exit(t_programm programm, int	x, int	y)
{
	programm.image = create_image(programm.mlx, "textures/exit.xpm");
//	programm.image.start_x = x;
//	programm.image.start_y = y;
	mlx_put_image_to_window(programm.mlx, programm.window.ptr, programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}

void	draw_wall(t_programm programm, int	x, int	y)
{
	programm.image = create_image(programm.mlx, "textures/wall.xpm");
//	programm.image.start_x = x;
//	programm.image.start_y = y;
	mlx_put_image_to_window(programm.mlx, programm.window.ptr, programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}

void	draw_collectible(t_programm programm, int	x, int	y)
{
	programm.image = create_image(programm.mlx, "textures/collectible.xpm");
//	programm.image.start_x = x;
//	programm.image.start_y = y;
	mlx_put_image_to_window(programm.mlx, programm.window.ptr, programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}

void	draw_player(t_programm programm, int	x, int	y)
{
	programm.image = create_image(programm.mlx, "textures/player.xpm");
//	programm.image.start_x = x;
//	programm.image.start_y = y;
	mlx_put_image_to_window(programm.mlx, programm.window.ptr, programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}
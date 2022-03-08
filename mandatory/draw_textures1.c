#include "so_long.h"

t_image create_image(void	*mlx, char	*path)
{
	t_image image;

	image.ptr = mlx_xpm_file_to_image(mlx, path, &image.width, &image.height);
	image.pixels = mlx_get_data_addr(image.ptr, &image.bpp, &image.line_size, &image.endian);
	return (image);
}

void	draw_empty_map(t_programm programm)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32 * programm.map.height) //координата У
	{
		j = 0;
		while (j < 32 * programm.map.width) //координата Х
		{
			draw_freespace(programm, j, i);
			j += 32;
		}
		i += 32;
	}
}

void	fill_map(t_programm programm)
{
	int	i;
	int	j;

	i = 0;
	while (i < programm.map.height) //координата У
	{
		j = 0;
		while (j < programm.map.width) //координата Х
		{
			if (programm.map.data[i][j] == '1')
				draw_wall(programm, j * 32, i * 32);
			else if (programm.map.data[i][j] == 'C')
				draw_collectible(programm, j * 32, i * 32);
			else if (programm.map.data[i][j] == 'E')
				draw_exit(programm, j * 32, i * 32);
			else if (programm.map.data[i][j] == 'P')
				draw_player(programm, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	draw_game(t_programm programm)
{
	draw_empty_map(programm); //тут все заполню нулями
	fill_map(programm); //а тут нарисую все остальное
}
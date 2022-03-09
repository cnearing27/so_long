/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:08:49 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/09 15:51:02 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemy(t_programm programm, int x, int y)
{
	programm.image = create_image(programm.mlx, "./textures/enemy.xpm");
	mlx_put_image_to_window(programm.mlx, programm.window.ptr,
		programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}

t_image	create_image(void	*mlx, char	*path)
{
	t_image	image;

	image.ptr = mlx_xpm_file_to_image(mlx, path, &image.width, &image.height);
	image.pixels = mlx_get_data_addr(image.ptr, &image.bpp,
			&image.line_size, &image.endian);
	return (image);
}

void	draw_empty_map(t_programm programm)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32 * programm.map.height)
	{
		j = 0;
		while (j < 32 * programm.map.width)
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
	while (i < programm.map.height)
	{
		j = 0;
		while (j < programm.map.width)
		{
			if (programm.map.data[i][j] == '1')
				draw_wall(programm, j * 32, i * 32);
			else if (programm.map.data[i][j] == 'C')
				draw_collectible(programm, j * 32, i * 32);
			else if (programm.map.data[i][j] == 'E')
				draw_exit(programm, j * 32, i * 32);
			else if (programm.map.data[i][j] == 'P')
				draw_player(programm, j * 32, i * 32);
			else if (programm.map.data[i][j] == 'Q')
				draw_enemy(programm, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	draw_game(t_programm programm)
{
	draw_empty_map(programm);
	fill_map(programm);
	mlx_string_put(programm.mlx, programm.window.ptr,
		0, 0, 0xFFFFFF, "0");
}

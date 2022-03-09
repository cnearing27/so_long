/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:08:56 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/09 15:50:00 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_freespace(t_programm programm, int x, int y)
{
	programm.image = create_image(programm.mlx, "./textures/free_space.xpm");
	mlx_put_image_to_window(programm.mlx, programm.window.ptr,
		programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}

void	draw_exit(t_programm programm, int x, int y)
{
	programm.image = create_image(programm.mlx, "./textures/exit.xpm");
	mlx_put_image_to_window(programm.mlx, programm.window.ptr,
		programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}

void	draw_wall(t_programm programm, int x, int y)
{
	programm.image = create_image(programm.mlx, "./textures/wall.xpm");
	mlx_put_image_to_window(programm.mlx, programm.window.ptr,
		programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}

void	draw_collectible(t_programm programm, int x, int y)
{
	programm.image = create_image(programm.mlx, "./textures/collectible.xpm");
	mlx_put_image_to_window(programm.mlx, programm.window.ptr,
		programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}

void	draw_player(t_programm programm, int x, int y)
{
	programm.image = create_image(programm.mlx, "./textures/player.xpm");
	mlx_put_image_to_window(programm.mlx, programm.window.ptr,
		programm.image.ptr, x, y);
	mlx_destroy_image(programm.mlx, programm.image.ptr);
}

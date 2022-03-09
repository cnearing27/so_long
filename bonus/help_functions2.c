/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:09:33 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/09 15:43:48 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	exit(0);
}

t_window	create_new_window(void	*mlx, t_map	map)
{
	t_window	window;

	window.height = map.height * 32;
	window.width = map.width * 32;
	window.ptr = mlx_new_window(mlx, window.width,
			window.height, "cnearing so_long :)");
	mlx_hook(window.ptr, 17, 0, ft_close, 0);
	return (window);
}

void	reload_score(t_programm	*programm)
{
	char	*new_score;

	new_score = NULL;
	new_score = ft_itoa(programm->steps);
	draw_wall(*programm, 0, 0);
	mlx_string_put(programm->mlx, programm->window.ptr,
		0, 0, 0xFFFFFF, new_score);
	free(new_score);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:09:45 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/09 15:40:53 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lose(void)
{
	ft_putstr("You were blown by Creeper. Game lost! :(\n");
	exit(0);
}

int	user_press(int keycode, void	*param)
{
	t_programm	*programm;

	programm = (t_programm *)param;
	if (keycode == 13)
		move_up(programm);
	else if (keycode == 0)
		move_left(programm);
	else if (keycode == 1)
		move_down(programm);
	else if (keycode == 2)
		move_right(programm);
	else if (keycode == 53)
	{
		ft_putstr("Game closed :)\n");
		exit(0);
	}
	return (0);
}

void	open_game(t_programm	programm)
{
	programm.mlx = mlx_init();
	programm.window = create_new_window(programm.mlx, programm.map);
	draw_game(programm);
	programm.steps = 0;
	mlx_key_hook(programm.window.ptr, *user_press, &programm);
	mlx_loop(programm.mlx);
}

int	main(int argc, char	**argv)
{
	t_programm	programm;

	init_map(&programm.map);
	if (!get_map(argc, argv, &programm.map))
	{
		exit_with_error(&programm.map);
		return (0);
	}
	open_game(programm);
}

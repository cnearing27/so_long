/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:11:48 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/09 15:15:52 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_programm	*programm, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = programm->map.player_pos_x;
	old_y = programm->map.player_pos_y;
	programm->map.data[old_y][old_x] = '0';
	programm->map.data[new_y][new_x] = 'P';
	draw_freespace(*programm, new_x * 32, new_y * 32);
	draw_player(*programm, new_x * 32, new_y * 32);
	draw_freespace(*programm, old_x * 32, old_y * 32);
	programm->map.player_pos_x = new_x;
	programm->map.player_pos_y = new_y;
}

void	move_up(t_programm *programm)
{
	int	new_x;
	int	new_y;

	new_x = programm->map.player_pos_x;
	new_y = programm->map.player_pos_y - 1;
	if (programm->map.data[new_y][new_x] == 'E' &&
		programm->map.collectibles_count == 0)
	{
		ft_putstr("Game won! :)\n");
		exit(0);
	}
	else if (programm->map.data[new_y][new_x] == 'C')
	{
		programm->map.collectibles_count--;
		move_player(programm, new_x, new_y);
	}
	else if (programm->map.data[new_y][new_x] == '0')
		move_player(programm, new_x, new_y);
	else
		return ;
	programm->steps++;
	ft_printf("Steps: %d\n", programm->steps);
}

void	move_left(t_programm *programm)
{
	int	new_x;
	int	new_y;

	new_x = programm->map.player_pos_x - 1;
	new_y = programm->map.player_pos_y;
	if (programm->map.data[new_y][new_x] == 'E' &&
		programm->map.collectibles_count == 0)
	{
		ft_putstr("Game won! :)\n");
		exit(0);
	}
	else if (programm->map.data[new_y][new_x] == 'C')
	{
		programm->map.collectibles_count--;
		move_player(programm, new_x, new_y);
	}
	else if (programm->map.data[new_y][new_x] == '0')
		move_player(programm, new_x, new_y);
	else
		return ;
	programm->steps++;
	ft_printf("Steps: %d\n", programm->steps);
}

void	move_down(t_programm *programm)
{
	int	new_x;
	int	new_y;

	new_x = programm->map.player_pos_x;
	new_y = programm->map.player_pos_y + 1;
	if (programm->map.data[new_y][new_x] == 'E' &&
		programm->map.collectibles_count == 0)
	{
		ft_putstr("Game won! :)\n");
		exit(0);
	}
	else if (programm->map.data[new_y][new_x] == 'C')
	{
		programm->map.collectibles_count--;
		move_player(programm, new_x, new_y);
	}
	else if (programm->map.data[new_y][new_x] == '0')
		move_player(programm, new_x, new_y);
	else
		return ;
	programm->steps++;
	ft_printf("Steps: %d\n", programm->steps);
}

void	move_right(t_programm *programm)
{
	int	new_x;
	int	new_y;

	new_x = programm->map.player_pos_x + 1;
	new_y = programm->map.player_pos_y;
	if (programm->map.data[new_y][new_x] == 'E' &&
		programm->map.collectibles_count == 0)
	{
		ft_putstr("Game won! :)\n");
		exit(0);
	}
	else if (programm->map.data[new_y][new_x] == 'C')
	{
		programm->map.collectibles_count--;
		move_player(programm, new_x, new_y);
	}
	else if (programm->map.data[new_y][new_x] == '0')
		move_player(programm, new_x, new_y);
	else
		return ;
	programm->steps++;
	ft_printf("Steps: %d\n", programm->steps);
}

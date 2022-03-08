#include "so_long.h"

void	move_up(t_programm *programm)
{
	int	new_x;
	int	new_y;
	
	new_x = programm->map.player_pos_x;
	new_y = programm->map.player_pos_y - 1;
	if (programm->map.data[new_x][new_y] == 'E' && programm->map.collectibles_count == 0)
	{
		ft_putstr("Game won! :)\n");
		exit(0);
	}
	else if (programm->map.data[new_x][new_y] == 'C')
	{
		programm->map.collectibles_count--;
		programm->map.data[new_x][new_y + 1] = '0';
		programm->map.data[new_x][new_y] = 'P';
		draw_freespace(*programm, new_x, new_y);
		draw_freespace(*programm, new_x, new_y - 1);
		draw_player(*programm, new_x, new_y);
		programm->map.player_pos_x = new_x;
		programm->map.player_pos_y = new_y;
	}
	else if (programm->map.data[new_x][new_y] == '0')
	{
		programm->map.data[new_x][new_y + 1] = '0';
		programm->map.data[new_x][new_y] = 'P';
		draw_freespace(*programm, new_x * 32, (new_y + 1) * 32);
		draw_player(*programm, new_x * 32, new_y * 32);
		programm->map.player_pos_x = new_x;
		programm->map.player_pos_y = new_y;
	}
	programm->steps++;
	ft_printf("Steps: %d\n", programm->steps);
}

int	user_press(int keycode, void	*param)
{
	t_programm	*programm;

	programm = (t_programm *)param;
	// W - 13
	// A - 0
	// S - 1
	// D - 2
	// ESC - 53
	if (keycode == 13) {
		move_up(programm);
//		printf("new pos player is x: %d, y: %d\n", programm->map.player_pos_x, programm->map.player_pos_y);

	}
//	else if (keycode == 0)
//		move_left(programm);
//	else if (keycode == 1)
//		move_down(programm);
//	else if (keycode == 2)
//		move_right(programm);
	else if (keycode == 53)
	{
		ft_putstr("Game closed :)\n");
		exit(0);
	}
	return(0);
} 

void	open_game(t_programm	programm)
{
	programm.mlx = mlx_init();
	programm.window = create_new_window(programm.mlx, programm.map);
	draw_game(programm);
	programm.steps = 0;
	ft_printf("Steps: %d\n", programm.steps);
	mlx_key_hook(programm.window.ptr, *user_press, &programm);
	mlx_loop(programm.mlx);
}

int main(int argc, char	**argv)
{
	t_programm	programm;

	init_map(&programm.map);
	if (!get_map(argc, argv, &programm.map))
	{
		exit_with_error(&programm.map);
		return (0);
	}
//	int i = 0;
//	while(programm.map.data[i])
//	{
//		printf("%s\n", programm.map.data[i]);
//		i++;
//	}
//	printf("heigth = %d, width = %d\n", programm.map.height, programm.map.width);
//	printf("Player position: x = %d, y = %d\n", programm.map.player_pos_x, programm.map.player_pos_y);
	open_game(programm);
}
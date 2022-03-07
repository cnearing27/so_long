#include "so_long.h"

void	open_game(t_map	*map)
{
	void	*mlx;

	mlx = mlx_init();

}

int main(int argc, char	**argv)
{
	t_map	map;

	init_map(&map);
	if (!get_map(argc, argv, &map))
	{
		exit_with_error(&map);
		printf("error");
		return (0);
	}
	int i = 0;
	while(map.data[i])
	{
		printf("%s\n", map.data[i]);
		i++;
	}
	printf("heigth = %d, width = %d\n", map.height, map.width);
	printf("Player position: x = %d, y = %d\n", map.player_pos_x, map.player_pos_y);
	open_game(&map);
}

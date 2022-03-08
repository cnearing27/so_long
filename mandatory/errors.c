#include "so_long.h"

void	exit_with_error(t_map	*map)
{
	if (!(map->data))	//карта пустая или файл с картой не открывается, или не ввели аргумент
		ft_putstr("Erorr\nNo such map file\n");
	else if (!map->height || !map->width)	//в какой-то строке меньше/больше символов
		ft_putstr("Error\nMap form is not rectangle!\n");
	else if (!map->allowed_simbols) //есть другие символы, кроме разрешенных
		ft_putstr("Erorr\nMap contain not allowed simbols!\n");
	else if (!map->walls_count) //по периметру есть дыры в стенах
		ft_putstr("Error\nToo few walls on the map!\n");
	else if (!map->exits_count) //нет хотя бы 1 выхода
		ft_putstr("Error\nToo few exits on the map!\n");
	else if (!map->players_count) //нет хотя бы одного игрока
		ft_putstr("Error\nToo few players on the map!\n");
	else if (!map->collectibles_count) //нет хотя бы одного Collectible
		ft_putstr("Error\nToo few collectibles on the map!\n");
	if (map->data)
		free_strings(map->data);
}

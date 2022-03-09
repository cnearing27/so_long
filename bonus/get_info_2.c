/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:09:16 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/09 15:47:07 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	permited_simbols(t_map	*map)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == '1' || map->data[i][j] == '0' ||
				map->data[i][j] == 'C' || map->data[i][j] == 'Q' ||
				map->data[i][j] == 'P' ||
				map->data[i][j] == 'E')
				counter++;
			j++;
		}
		i++;
	}
	map->allowed_simbols = counter;
	if (map->allowed_simbols == (map->height) * (map-> width))
		return (1);
	map->allowed_simbols = 0;
	return (0);
}

int	walls_around(t_map	*map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->data[0][i] == '1' &&
			map->data[map->height - 1][i] == '1')
			map->walls_count += 2;
		i++;
	}
	i = 1;
	while (i < map->height - 1)
	{
		if (map->data[i][0] == '1' &&
			map->data[i][map->width - 1] == '1')
			map->walls_count += 2;
		i++;
	}
	if (map->walls_count == (2 * map->width + 2 * (map->height - 2)))
		return (1);
	map->walls_count = 0;
	return (0);
}

int	entities(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == 'E')
				map->exits_count++;
			else if (map->data[i][j] == 'P')
				map->players_count++;
			else if (map->data[i][j] == 'C')
				map->collectibles_count++;
			j++;
		}
		i++;
	}
	i = 1;
	if (map->exits_count == 0 || map->players_count == 0
		|| map->collectibles_count == 0)
		return (0);
	return (1);
}

void	get_player_info(t_map	*map)
{
	int	i;
	int	j;

	i = map->height - 2;
	while (i > 0)
	{
		j = map->width - 2;
		while (j > 0)
		{
			if (map->data[i][j] == 'P' && map->players_count != 1)
			{
					map->data[i][j] = '0';
					map->players_count--;
			}
			else if (map->data[i][j] == 'P')
			{
				map->player_pos_x = j;
				map->player_pos_y = i;
				return ;
			}
			j--;
		}
		i--;
	}
}

int	get_sizes(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	map->width = ft_strlen(map->data[0]);
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
			j++;
		if (j != map->width)
		{
			map->width = 0;
			map->height = 0;
			return (0);
		}
		i++;
	}
	map->height = i;
	return (1);
}

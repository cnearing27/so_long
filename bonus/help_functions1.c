/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:09:24 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/09 15:44:46 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	free_strings(char	**data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	if (data)
		free(data);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init_map(t_map	*map)
{
	map->height = 0;
	map->width = 0;
	map->data = NULL;
	map->allowed_simbols = 0;
	map->player_pos_x = 0;
	map->player_pos_y = 0;
	map->walls_count = 0;
	map->exits_count = 0;
	map->players_count = 0;
	map->collectibles_count = 0;
	map->enemies_count = 0;
}

int	ber_file(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'r'
		&& str[i - 2] == 'e'
		&& str[i - 3] == 'b'
		&& str[i - 4] == '.')
		return (1);
	return (0);
}

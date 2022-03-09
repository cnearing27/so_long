/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:09:01 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/09 15:48:56 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_error(t_map	*map)
{
	if (!(map->data))
		ft_putstr("Erorr\nNo such map file\n");
	else if (!map->height || !map->width)
		ft_putstr("Error\nMap form is not rectangle!\n");
	else if (!map->allowed_simbols)
		ft_putstr("Erorr\nMap contain not allowed simbols!\n");
	else if (!map->walls_count)
		ft_putstr("Error\nToo few walls on the map!\n");
	else if (!map->exits_count)
		ft_putstr("Error\nToo few exits on the map!\n");
	else if (!map->players_count)
		ft_putstr("Error\nToo few players on the map!\n");
	else if (!map->enemies_count)
		ft_putstr("Error\nToo few enemies on the map!\n");
	else if (!map->collectibles_count)
		ft_putstr("Error\nToo few collectibles on the map!\n");
	if (map->data)
		free_strings(map->data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:09:12 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/09 15:47:40 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(int argc, char	**argv, t_map	*map)
{
	if (argc != 2 || open(argv[1], O_RDONLY) == -1 || !ber_file(argv[1]))
		return (0);
	else
		map->data = get_lines(open(argv[1], O_RDONLY));
	if (map->data == NULL)
		return (0);
	if (!get_sizes(map))
		return (0);
	if (!permited_simbols(map))
		return (0);
	if (!walls_around(map))
		return (0);
	if (!entities(map))
		return (0);
	if (!enemies(map))
		return (0);
	get_player_info(map);
	return (1);
}

char	*ft_strcpy(char *dest, char *src, int i)
{
	int	count;

	count = 0;
	while (count < i)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, src, i));
}

char	*ft_strcat(char	*dest, char	*src)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (dest == NULL)
		return (ft_strdup(src));
	while (dest[i])
		i++;
	while (src[j])
		j++;
	ret = malloc(sizeof(char) * (i + j + 1));
	ret = ft_strcpy(ret, dest, i + j);
	j = 0;
	while (src[j])
	{
		ret[i] = src[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	if (dest)
		free(dest);
	return (ret);
}

char	**get_lines(int fd)
{
	char	*curr_line;
	char	*outstr;
	char	**lines;
	int		i;

	outstr = NULL;
	curr_line = malloc(sizeof(char) * 2);
	lines = NULL;
	i = 1;
	while (i)
	{
		i = read(fd, curr_line, 1);
		if (i == -1)
		{
			free(curr_line);
			break ;
		}
		curr_line[i] = '\0';
		outstr = ft_strcat(outstr, curr_line);
	}
	free(curr_line);
	lines = ft_split(outstr, '\n');
	free(outstr);
	i = 0;
	return (lines);
}

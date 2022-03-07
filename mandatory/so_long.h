#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	int				height;
	int				width;
	char			**data;
	int				allowed_simbols;
	int				player_pos_x;
	int				player_pos_y;
	int				walls_count;
	int				exits_count;
	int				players_count;
	int				collectibles_count;
}	t_map;

# include <fcntl.h> //для open
# include <unistd.h> //для write, close, read
# include <stdlib.h> //для malloc, free, exit
# include <stdio.h> //для perror, strerror
# include "../minilibx_opengl_20191021/mlx.h"

int		get_map(int argc, char	**argv, t_map	*map);
void	exit_with_error(t_map	*map);
void	ft_putstr(char	*str);
void	free_strings(char	**data);
char	**ft_split(char	*s, char c);
char	*ft_strcat(char	*dest, char	*src);
char	**get_lines(int fd);
int		ft_strlen(char	*str);
int		get_sizes(t_map	*map);
int		permited_simbols(t_map	*map);
int		walls_around(t_map	*map);
int		entities(t_map	*map);
void	init_map(t_map	*map);
void	get_player_info(t_map	*map);


# endif

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

typedef struct s_window
{
	int				height;
	int				width;
	void			*ptr;
}	t_window;

typedef struct s_image
{
	void			*ptr;
	int				height;
	int				width;
//	int				start_x;
//	int				start_y;
	char			*pixels;
	int				bpp;
	int				line_size;
	int				endian;
}	t_image;

typedef struct s_programm
{
	t_map			map;
	t_window		window;
	t_image			image;
	void			*mlx;
	int				steps;
}	t_programm;

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //убрать
# include <mlx.h>

int			get_map(int argc, char	**argv, t_map	*map);
void		exit_with_error(t_map	*map);
void		ft_putstr(char	*str);
void		free_strings(char	**data);
char		**ft_split(char	*s, char c);
char		*ft_strcat(char	*dest, char	*src);
char		**get_lines(int fd);
int			ber_file(char	*str);
int			ft_strlen(char	*str);
int			get_sizes(t_map	*map);
int			permited_simbols(t_map	*map);
int			walls_around(t_map	*map);
int			entities(t_map	*map);
void		init_map(t_map	*map);
void		get_player_info(t_map	*map);
t_window	create_new_window(void	*mlx, t_map	map);
void		draw_empty_map(t_programm programm);
t_image		create_image(void	*mlx, char	*path);
void		draw_freespace(t_programm programm, int	x, int	y);
void		draw_wall(t_programm programm, int	x, int	y);
void		draw_collectible(t_programm programm, int	x, int	y);
void		draw_player(t_programm programm, int	x, int	y);
void		draw_exit(t_programm programm, int	x, int	y);
void		draw_game(t_programm programm);
void		ft_printf(const char *format, int num);

# endif

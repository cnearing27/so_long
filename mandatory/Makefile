SRCS	= 	main.c \
			get_info_1.c \
			get_info_2.c \
			help_functions1.c \
			help_functions2.c \
			ft_split.c \
			errors.c \
			draw_textures1.c \
			draw_textures2.c \
			mini_printf.c

HEADERS		= so_long.h

OBJS		= $(SRCS:.c=.o)

NAME		= so_long

CC			= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.
#FLAGS		= -I.
LINKS		= -lmlx -framework OpenGL -framework AppKit


all:	$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) $(LINKS) -o $(NAME)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) so_long

re:		fclean all

.PHONY: all clean fclean re
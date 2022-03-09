SRCS		=	mandatory/so_long.c \
				mandatory/get_info_1.c \
				mandatory/get_info_2.c \
				mandatory/help_functions1.c \
				mandatory/help_functions2.c \
				mandatory/ft_split.c \
				mandatory/errors.c \
				mandatory/draw_textures1.c \
				mandatory/draw_textures2.c \
				mandatory/mini_printf.c \
				mandatory/moves.c

SRCS_B		=	bonus/so_long.c \
				bonus/get_info_1.c \
				bonus/get_info_2.c \
				bonus/get_info_3.c \
				bonus/help_functions1.c \
				bonus/help_functions2.c \
				bonus/ft_split.c \
				bonus/errors.c \
				bonus/draw_textures1.c \
				bonus/draw_textures2.c \
				bonus/moves.c \
				bonus/ft_itoa.c

HEADERS		=	mandatory/so_long.h \
				bonus/so_long.h

OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)

NAME		= so_long
NAME_B		= so_long_bonus

CC			= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.
LINKS		= -lmlx -framework OpenGL -framework AppKit

$(NAME):		$(OBJS)
			$(CC) $(LINKS) -o $(NAME) $(OBJS) 

all:	$(NAME)

$(NAME_B):		$(OBJS_B)
			$(CC) $(LINKS) -o $(NAME_B) $(OBJS_B) 

bonus:	$(NAME_B)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
			$(RM) $(OBJS)
			$(RM) $(OBJS_B)

fclean:	clean
			$(RM) so_long
			$(RM) so_long_bonus

re:		fclean all bonus

.PHONY: all clean fclean re
SRC_FILES = sources/animations_utils.c \
			sources/draw_map.c \
			sources/get_next_line.c \
			sources/get_next_line_utils.c \
			sources/moves.c \
			sources/parse.c \
			sources/so_long.c \
			sources/ft_itoa.c \
			sources/ft_putnbr_fd.c \
			sources/moves_functions.c

SRC_FILES_B = sources_bonus/animations_utils_bonus.c \
			sources_bonus/animations_bonus.c \
			sources_bonus/draw_map_bonus.c \
			sources_bonus/get_next_line_bonus.c \
			sources_bonus/get_next_line_utils_bonus.c \
			sources_bonus/moves_bonus.c \
			sources_bonus/parse_bonus.c \
			sources_bonus/so_long_bonus.c \
			sources_bonus/ft_itoa.c \
			sources_bonus/moves_functions_bonus.c

HEAD 		= headers/so_long.h
HEAD_B 		= headers/so_long_bonus.h

NAME 		= so_long
NAME_B 		= so_long_bonus

OBJ_SRC 	= $(SRC_FILES:.c=.o)
OBJ_SRC_B 	= $(SRC_FILES_B:.c=.o)

FLAGS 		= -Wall -Wextra -Werror
LINKS 		= -lmlx -framework OpenGL -framework AppKit

$(NAME): 	$(OBJ_SRC)
			gcc $(OBJ_SRC) $(LINKS) $(LIBFT) -o $(NAME)

$(NAME_B):	$(OBJ_SRC_B)
			gcc $(OBJ_SRC_B) $(LINKS) $(LIBFT) -o $(NAME_B)

%.o:	%.c $(HEAD) $(HEAD_B)
			gcc $(FLAGS) -c $< -o $@

all: 		$(NAME_B)

bonus:		$(NAME_B)

clean:
			rm -f $(OBJ_SRC) $(OBJ_SRC_B)

fclean:		clean
			rm -f $(NAME) $(NAME_B)

re:			fclean all

re_bonus: 	fclean bonus

.PHONY: all bonus clean fclean re
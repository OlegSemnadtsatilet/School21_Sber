# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 13:00:01 by bmaya             #+#    #+#              #
#    Updated: 2022/02/22 13:00:41 by bmaya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = sources/

HEAD = ft_printf.h
NAME = libftprintf.a
LIBFT = libft/libft.a
OBJ_SRC = $(SRC_FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ_SRC)
			$(MAKE) -C ./libft
			cp $(LIBFT) $(NAME)
			ar rc $(NAME) $(OBJ_SRC)
			ranlib $(NAME)

%.o:	%.c $(HEAD)
			gcc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ_SRC)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
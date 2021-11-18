# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:14:33 by bmaya             #+#    #+#              #
#    Updated: 2021/11/13 17:12:21 by bmaya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = ft_printf_char.c \
	ft_printf_decimal_int.c \
	ft_printf_hex_number.c \
	ft_printf_percent.c \
	ft_printf_string.c \
	ft_printf_unsigned_decimal.c \
	ft_printf_void_pointer.c \
	ft_printf.c \
	printf_for_type.c

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

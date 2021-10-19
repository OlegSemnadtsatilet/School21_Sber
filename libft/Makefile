# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:14:33 by bmaya             #+#    #+#              #
#    Updated: 2021/10/19 20:50:25 by bmaya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FILES = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_split.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_striteri.c

SRC_BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c 
		

OBJ_SRC = $(SRC_FILES:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBH = libft.h

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ_SRC)
			ar rc $(NAME) $(OBJ_SRC)
			ranlib $(NAME)

%.o:	%.c $(LIBH)
			gcc $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJ_SRC) $(OBJ_BONUS)
			ar rc $(NAME) $(OBJ_SRC) $(OBJ_BONUS)
			ranlib $(NAME)

clean:
	rm -f $(OBJ_SRC) $(OBJ_BONUS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

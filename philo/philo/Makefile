# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 14:01:04 by bmaya             #+#    #+#              #
#    Updated: 2022/05/09 14:36:30 by bmaya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo.c \
	ft_atoi.c \
	lifecycle.c \
	checks.c \
	utils.c 

NAME = philo

HEAD = philo.h

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
			gcc -o $(NAME) $(OBJ)

%.o:	%.c $(HEAD)
			gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
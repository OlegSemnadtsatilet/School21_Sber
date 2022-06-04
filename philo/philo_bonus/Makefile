# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 14:01:04 by bmaya             #+#    #+#              #
#    Updated: 2022/05/19 16:53:54 by bmaya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo_bonus.c \
	ft_atoi.c \
	lifecycle_bonus.c \
	checks_bonus.c \
	utils_bonus.c 

NAME = philo_bonus

HEAD = philo_bonus.h

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
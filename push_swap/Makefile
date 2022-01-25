# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 14:01:04 by bmaya             #+#    #+#              #
#    Updated: 2022/01/20 16:40:59 by bmaya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PU = push_swap.c \
	push_swap_operations_1.c \
	push_swap_operations_2.c \
	ft_atoi.c \
	sort_operations.c \
	sorting_1.c \
	sorting_2.c \
	mini_sorting.c \
	list_operations.c \
	ab_operations_1.c \
	ab_operations_2.c \
	ab_operations_3.c 

SRCS_CH = checker.c \
	get_next_line.c \
	get_next_line_utils.c \
	checker_operations_1.c \
	checker_operations_2.c \
	push_swap_operations_2.c \
	checker_operations_3.c \
	list_operations.c \
	sort_operations.c \
	ft_atoi.c \

NAME_PU = push_swap
NAME_CH = checker

HEAD_PU = push_swap.h
HEAD_CH = checker.h

OBJ_PU = $(SRCS_PU:.c=.o)
OBJ_CH = $(SRCS_CH:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME_PU) $(NAME_CH)

$(NAME_PU): $(OBJ_PU)
			gcc -o $(NAME_PU) $(OBJ_PU)

$(NAME_CH): $(OBJ_CH)
			gcc -o $(NAME_CH) $(OBJ_CH)

%.o:	%.c $(HEAD_PU) $(HEAD_CH)
			gcc $(FLAGS) -c $< -o $@

clean_push_swap:
	rm -f $(OBJ_PU)

clean_checker:
	rm -f $(OBJ_CH)

clean: clean_push_swap clean_checker

fclean_push_swap: clean_push_swap
	rm -f $(NAME_PU)

fclean_checker: clean_checker
	rm -f $(NAME_CH)

fclean: fclean_push_swap fclean_checker

re: fclean all

.PHONY: all clean fclean re
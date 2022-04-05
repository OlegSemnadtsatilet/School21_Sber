# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 14:01:04 by bmaya             #+#    #+#              #
#    Updated: 2022/02/12 17:46:08 by bmaya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CT = client.c \
	minitalk_includes.c \

SRCS_CT_B = client_bonus.c \
	minitalk_includes_bonus.c \

SRCS_SR = server.c \
	minitalk_includes.c \

SRCS_SR_B = server_bonus.c \
	minitalk_includes_bonus.c \

NAME_CT = client
NAME_SR = server

NAME_CT_B = client_bonus
NAME_SR_B = server_bonus

HEAD = minitalk.h
HEAD_B = minitalk_bonus.h

OBJ_CT = $(SRCS_CT:.c=.o)
OBJ_SR = $(SRCS_SR:.c=.o)

OBJ_CT_B = $(SRCS_CT_B:.c=.o)
OBJ_SR_B = $(SRCS_SR_B:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:	$(NAME_CT) $(NAME_SR)

bonus:	$(NAME_CT_B) $(NAME_SR_B)

$(NAME_CT): $(OBJ_CT)
			gcc -o $(NAME_CT) $(OBJ_CT)

$(NAME_SR): $(OBJ_SR)
			gcc -o $(NAME_SR) $(OBJ_SR)

$(NAME_CT_B): $(OBJ_CT_B)
			gcc -o $(NAME_CT_B) $(OBJ_CT_B)

$(NAME_SR_B): $(OBJ_SR_B)
			gcc -o $(NAME_SR_B) $(OBJ_SR_B)

%.o:	%.c $(HEAD)
			gcc $(FLAGS) -c $< -o $@

%.o:	%.c $(HEAD_B)
			gcc $(FLAGS) -c $< -o $@

clean_client:
	rm -f $(OBJ_CT)

clean_client_bonus:
	rm -f $(OBJ_CT_B)

clean_server:
	rm -f $(OBJ_SR)

clean_server_bonus:
	rm -f $(OBJ_SR_B)

clean: clean_client clean_server

clean_bonus: clean_client_bonus clean_server_bonus

fclean_client: clean_client
	rm -f $(NAME_CT)

fclean_server: clean_server
	rm -f $(NAME_SR)

fclean_client_bonus: clean_client_bonus
	rm -f $(NAME_CT_B)

fclean_server_bonus: clean_server_bonus
	rm -f $(NAME_SR_B)

fclean: fclean_client fclean_server

fclean_bonus: fclean_client_bonus fclean_server_bonus

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus re_bonus
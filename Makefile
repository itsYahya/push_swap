# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 20:56:23 by yel-mrab          #+#    #+#              #
#    Updated: 2022/01/21 21:06:30 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c sort_radix.c utils.c
OBJ = $(SRC:.c=.o)
GCC = gcc -Wall -Wextra -Werror
NAME = push_swap
HEADER = $(NAME=.h)

all : $(NAME)

$(NAME) : $(OBJ)
	$(GCC) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(GCC) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

.PHONY: all clean fclean
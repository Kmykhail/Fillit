# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 21:59:32 by kmykhail          #+#    #+#              #
#    Updated: 2017/11/24 21:59:35 by kmykhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc -Wall -Wextra -Werror

SRC = check_valid.c matrix.c tripple_array.c matrix_solver_1.c matrix_solver_2.c

OBJ =  $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):

	@$(CC) -c $(SRC) 
	@$(CC) -o $(NAME) $(OBJ)
	@echo ./fillit created

clean:
	@rm -f $(OBJ)
fclean: clean

	@rm -f $(NAME)
re: fclean all
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 15:49:12 by gmelisan          #+#    #+#              #
#    Updated: 2018/12/25 16:08:04 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ = ft_printf.o

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\nFile \"$(NAME)\" was successfully created."

clean:
	@rm -f $(OBJ)
	@rm -f main.o

fclean: clean
	@rm -f $(NAME)
	@rm -f test

re: fclean all

$(OBJ): ft_printf.h

test: $(NAME) main.o
	$(CC) $(CFLAGS) -o test main.o -L. -lftprintf

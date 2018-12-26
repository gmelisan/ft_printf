#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 15:49:12 by gmelisan          #+#    #+#              #
#    Updated: 2018/12/26 21:43:46 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra #-Werror
CFLAGS += -g

OBJ = ft_printf.o get_conversion.o get_conv_func.o handle_conversion.o

OBJ += ft_isdigit.o ft_memalloc.o ft_memdel.o ft_bzero.o ft_putchar.o \
ft_itoa.o ft_memset.o ft_strlen.o

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

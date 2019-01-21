#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 15:49:12 by gmelisan          #+#    #+#              #
#    Updated: 2019/01/21 17:14:05 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

OBJ = ft_printf.o get_conversion.o get_conv_func.o handle_conversion.o \
handle_unknown.o create_integer_out.o handle_float.o handle_char.o \
handle_string.o handle_integer.o

OBJ += ft_isdigit.o ft_memalloc.o ft_memdel.o ft_strdel.o ft_bzero.o \
ft_putchar.o ft_itoa.o ft_memset.o ft_strlen.o ft_strnew.o ft_strncpy.o \
ft_memcpy.o ft_putstr.o ft_strjoin.o ft_strdup.o ft_tolower.o ft_itoa.o

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\nFile \"$(NAME)\" was successfully created."

$(OBJ): ft_printf.h

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

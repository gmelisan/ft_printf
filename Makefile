#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 15:49:12 by gmelisan          #+#    #+#              #
#    Updated: 2019/01/30 15:58:35 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ = ft_printf.o ft_vprintf.o ft_fdprintf.o ft_vfdprintf.o
OBJ += get_conversion.o get_flags.o get_width.o get_precision.o get_length.o
OBJ += handle_conversion.o
OBJ += handle_unknown.o
OBJ += handle_char.o handle_string.o
OBJ += handle_wchar.o handle_wstring.o
OBJ += handle_integer.o convert_integer.o number_to_string.o
OBJ += handle_float.o convert_float.o \
number_to_string_f.o number_to_string_e.o
OBJ += get_color.o handle_color.o

OBJ += ft_isdigit.o ft_memalloc.o ft_memdel.o ft_strdel.o ft_bzero.o \
ft_memset.o ft_strlen.o ft_strnew.o ft_strncpy.o \
ft_memcpy.o ft_putstr.o ft_strjoin.o ft_strdup.o ft_tolower.o \
ft_realloc.o ft_strequ.o ft_strcpy.o

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\nFile \"$(NAME)\" was successfully created."

$(OBJ): ft_printf.h libft.h

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

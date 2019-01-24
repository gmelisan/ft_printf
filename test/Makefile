#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 16:40:09 by gmelisan          #+#    #+#              #
#    Updated: 2019/01/24 16:27:38 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = run
LIB = ../libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra #-Werror
CFLAGS += -g

OBJ = main.o test_c.o test_s.o test_d.o test_f.o test_unknown.o test_u.o \
test_o.o test_x.o test_bonus.o test_p.o test_wc.o

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L.. -lftprintf
	@echo "Ready to ./run"

$(OBJ): test.h

$(LIB):
	make -C ..

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB)

re: fclean all

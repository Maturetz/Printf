# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maturetz <maturetz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 15:55:08 by maturetz          #+#    #+#              #
#    Updated: 2024/12/12 16:01:08 by maturetz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFILES =

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall \
         -Wextra \
         -Werror \
         -g

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:  all clean fclean re
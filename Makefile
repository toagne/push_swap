# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 09:17:47 by mpellegr          #+#    #+#              #
#    Updated: 2024/06/05 10:10:18 by mpellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = main.c ft_atol.c check_errors.c utils.c simple_sort.c \
		  swap.c rotate.c rev_rotate.c

OBJECTS = $(SOURCES:.c=.o)

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

LIBFT = libft

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C ./libft clean
	$(RM) $(OBJECTS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re bonus

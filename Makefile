# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 09:17:47 by mpellegr          #+#    #+#              #
#    Updated: 2024/06/10 16:19:39 by mpellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = check_errors.c main.c move_cheapest.c populate_list.c \
		  push_swap.c push.c rev_rotate.c rotate.c swap.c t_ps_list.c utils.c

OBJECTS = $(SOURCES:.c=.o)

NAME = push_swap

LIB = push_swap.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

LIBFT = libft

all: $(NAME)

$(NAME) : $(LIB)
	$(CC) $< -o $@

$(LIB): $(OBJECTS)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(LIB)
	$(AR) $(LIB) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C ./libft clean
	$(RM) $(OBJECTS) $(LIB)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re

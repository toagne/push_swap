# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 09:17:47 by mpellegr          #+#    #+#              #
#    Updated: 2024/06/18 11:48:04 by mpellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = check_errors.c main.c move_cheapest.c populate_list.c \
		  push_swap.c push.c rev_rotate.c rotate.c swap.c t_ps_list.c utils.c

BONUS_SOURCES = check_errors.c checker_push.c checker_rev_rotate.c \
				checker_rotate.c checker_swap.c get_next_line.c  \
				get_next_line_utils.c main_bonus.c t_ps_list.c utils.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

NAME = push_swap

BONUS_NAME = checker

LIB = push_swap.a

BONUS_LIB = checker.a

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

$(BONUS_LIB): $(BONUS_OBJECTS)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(BONUS_LIB)
	$(AR) $(BONUS_LIB) $(BONUS_OBJECTS)

.bonus: $(BONUS_LIB)
	$(CC) $< -o $(BONUS_NAME)
	@touch .bonus;

bonus: .bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C ./libft clean
	$(RM) $(OBJECTS) $(LIB) $(BONUS_OBJECTS) $(BONUS_LIB)
	@$(RM) .bonus

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

PHONY: all clean fclean re

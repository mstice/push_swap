# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtice <mtice@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 11:20:01 by mtice             #+#    #+#              #
#    Updated: 2025/06/01 17:16:48 by mtice            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

SOURCES := 	main.c \
			input_check.c \
			pre_sort.c \
			sorting_functions1.c \
			sorting_functions2.c \
			stack_utils.c \
			mini_revsort.c \
			mini_sort.c \
			quicksort.c \
			sorting_utils.c

OBJECTS := $(SOURCES:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3

RM := rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJECTS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

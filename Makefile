CC := cc
CFLAGS := -Wall -Wextra -Werror -g3

LIBFTDIR := ./libft

NAME := push_swap

LIBFT := $(LIBFTDIR)/libft.a

SRC := $(wildcard *.c)

OBJ := $(SRC:.c=.o)

$(NAME) = $(OBJ) $(LIBFT)
			@cp $(LIBFT) libft.a
			@ar rcs libft.a $(OBJ)
			mv libft.a $(NAME)
			rm  $(wildcard *.o)


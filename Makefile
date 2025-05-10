NAME := push_swap
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3

RM := rm -f

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build final executable
$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

# Build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Default target
all: $(NAME)

# Clean object files and libft objects
clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJECTS)

# Fully clean everything including the library and executable
fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
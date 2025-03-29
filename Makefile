NAME := push_swap.a
LIBFT := libft/libft.a

SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3

AR := ar
ARFLAGS := -rcs

RM := rm -f

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure object files are built before linking push_swap.a
$(NAME): $(LIBFT) $(OBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(LIBFT) $(OBJECTS)

$(LIBFT):
	@$(MAKE) -C libft
	@cp $(LIBFT) libft.a
	@ar rcs libft.a $(OBJ)
	$(RM) libft.a

# Run 'make' to build everything
all: $(LIBFT) $(NAME)

# Clean object files and libft objects
clean:
	@$(MAKE) clean -C libft
	$(RM) libft.a
	$(RM) $(OBJECTS)

# Fully clean everything including the library and compiled archive
fclean: clean
	@$(MAKE) fclean -C libft
	$(RM) libft.a
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
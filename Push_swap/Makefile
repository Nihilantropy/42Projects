# Compiler and compiling flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Name of your program
NAME = push_swap

# Directories
SRCDIR = srcs
INCDIR = include
LIBDIR = libft

# Source files and object files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:.c=.o)

# Include directory for header files
INC = -I $(INCDIR) -I $(LIBDIR)

# Libft library
LIBFT = $(LIBDIR)/libft.a

# Compilation rule for the program
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBDIR) -lft -o $(NAME)

# Rule to make libft
$(LIBFT):
	make -C $(LIBDIR)

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Standard rules
all: $(NAME)

clean:
	make -C $(LIBDIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re
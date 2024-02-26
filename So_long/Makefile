NAME		= so_long

SOLONG_DIR	= ./srcs

SRCS		= open_display.c get_next_line.c my_mlx_pixel_put.c

OBJS		= $(patsubst %.c, $(SOLONG_DIR)/%.o, $(SRCS))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM = rm -f

# Include directory for header files
INC = -I $(INCDIR)

# Compilation rule for the program
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -Imlx -c $< -o $@

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
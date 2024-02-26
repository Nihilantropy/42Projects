NAME		= so_long

SOLONG_DIR	= ./srcs

SRCS		= so_long.c

OBJS		= $(patsubst %.c, $(SOLONG_DIR)/%.o, $(SRCS))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM = rm -f

# Include directory for header files
INC = -I $(INCDIR)

# Compilation rule for the program
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
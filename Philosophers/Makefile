NAME		= philo

PHILO_DIR	= ./srcs
PHILO_HEAD	= ./include

SRCS		= main.c main_utils.c checks.c checks_utils.c create_list.c create_list_utils.c

OBJS		= $(patsubst %.c, $(PHILO_DIR)/%.o, $(SRCS))

LIBFT_DIR	= ./libft
LIBFT		= libft.a

PRINTF_DIR	= ./ft_printf
PRINTF_LIB	= libft_printf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM = rm -f

# Include directory for header files
INC 		= -I$(PHILO_HEAD) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Compilation rule for the program
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


# Rule to compile object files
$(PHILO_DIR)/%.o: $(PHILO_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


all:		$(NAME)

clean:
			$(RM) $(OBJS)


fclean:		clean
			$(RM) $(NAME)

re:			fclean all

rec:		clean all


.PHONY:		all clean fclean re rec test
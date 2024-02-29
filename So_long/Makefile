NAME		= so_long

SOLONG_DIR	= ./srcs
SOLONG_HEAD	= ./include

SRCS		= main.c check_map_extention.c get_map.c get_map_utils.c check_map_edges.c check_map_inter.c manage_display.c \
				render_map.c

OBJS		= $(patsubst %.c, $(SOLONG_DIR)/%.o, $(SRCS))

LIBFT_DIR	= ./libft
LIBFT		= libft.a

PRINTF_DIR	= ./ft_printf
PRINTF_LIB	= libft_printf.a

MLX_DIR		= ./mlx
MLX_LIB		= libmlx.dylib


CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM = rm -f

# Include directory for header files
INC 		= -I$(SOLONG_HEAD) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)

# Compilation rule for the program
$(NAME): $(LIBFT) $(PRINTF_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


# Rule to compile object files
$(SOLONG_DIR)/%.o: $(SOLONG_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rule to make libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to make libft_printf
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

# Rule to make libmlx and copy to root
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX_LIB) ./

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(PRINTF_DIR) clean
			$(MAKE) -C $(MLX_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(MLX_LIB)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(PRINTF_DIR) fclean
			$(MAKE) -C $(MLX_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
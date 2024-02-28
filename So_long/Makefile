NAME		= so_long

SOLONG_DIR	= ./srcs

SRCS		= main.c get_next_line.c get_map.c

OBJS		= $(patsubst %.c, $(SOLONG_DIR)/%.o, $(SRCS))

LIBFT_DIR	= ./libft
LIBFT		= libft.a

PRINTF_DIR	= ./ft_printf
FT_PRINTF	= libft_printf.a

MLX_DIR		= ./mlx
MLX			= libmlx.dylib


CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM = rm -f

# Include directory for header files
INC 		= -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)

# Compilation rule for the program
$(NAME): $(LIBFT) $(FT_PRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Rule to compile object files
$(SOLONG_DIR)/%.o: $(SOLONG_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rule to make libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(PRINTF_DIR) clean
			$(MAKE) -C $(MLX_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(PRINTF_DIR) fclean

re:			fclean all

cleanmlx:	
			$(MAKE) -C $(MLX_DIR) fclean

.PHONY:		all clean fclean re cleanmlx
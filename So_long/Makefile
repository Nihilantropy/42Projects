NAME		= so_long

SECRET_NAME	= so_longo

SOLONG_DIR	= ./srcs
SOLONG_HEAD	= ./include

SECRET_DIR	= ./srcs/do_not_open/stop/i_warn_you/last_chance/secret_hell

SRCS		= main.c check_map_extention.c get_map.c get_map_utils.c check_map_edges.c check_map_interior.c \
				check_if_map_is_complete.c check_if_map_is_complete_utils.c manage_display.c render_map.c player_movement.c \
				player_movement_utils.c handle_closure.c handle_animations.c wall_animation.c player_animation.c player_inv_animation.c \
				collect_animation.c exit_animation.c enemy_animation.c game_mechanics.c game_mechanics_utils.c enemy_mechanics.c enemy_mechanics_utils.c \
				update.c player_mechanics.c player_mechanics_utils.c player_d_animation.c player_d_inv_animation.c number_sprites.c
						
SECRET_SRCS	= iushuj.c sedwhqjkbqjyed.c modify_hell.c

OBJS		= $(patsubst %.c, $(SOLONG_DIR)/%.o, $(SRCS))

SECRET_OBJS	= $(patsubst %.c, $(SECRET_DIR)/%.o, $(SECRET_SRCS))

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

$(SECRET_NAME): $(LIBFT) $(PRINTF_LIB) $(MLX_LIB) $(OBJS) $(SECRET_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(SECRET_OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(SECRET_NAME)


# Rule to compile object files
$(SOLONG_DIR)/%.o: $(SOLONG_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(SECRET_DIR)/%.o: $(SECRET_DIR)/%.c
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

secret_all:	$(SECRET_NAME)

clean:
			$(RM) $(OBJS) $(SECRET_OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(PRINTF_DIR) clean
			$(MAKE) -C $(MLX_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(SECRET_NAME) $(MLX_LIB)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(PRINTF_DIR) fclean
			$(MAKE) -C $(MLX_DIR) fclean

re:			fclean all

rec:		clean all

# Run this from another terminal while game is running
test: 		
			leaks $(shell pgrep so_long)

secret:		huluqb_iushuji secret_all xytu_iushuji

csecret:	clean secret

fsecret:	fclean secret

huluqb_iushuji:
	@./iushuji/huluqb_iushuji.sh
xytu_iushuji:
	@./iushuji/xytu_iushuji.sh

.PHONY:		all clean fclean re rec test secret csecret fsecret secret_all decript
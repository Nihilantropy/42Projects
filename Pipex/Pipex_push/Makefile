NAME		= pipex
NAME_BONUS	= pipex_bonus

PIPEX_DIR	= ./srcs
PIPEX_HEAD	= ./include

PIPEX_DIR_BONUS		= ./srcs_bonus
PIPEX_HEAD_BONUS	= ./include_bonus

SRCS		= main.c pipex.c pipex_utils.c
SRCS_BONUS	= main_bonus.c main_utils_bonus.c pipex_utils_bonus.c pipex_bonus.c

OBJS		= $(patsubst %.c, $(PIPEX_DIR)/%.o, $(SRCS))
OBJS_BONUS	= $(patsubst %.c, $(PIPEX_DIR_BONUS)/%.o, $(SRCS_BONUS))

LIBFT_DIR	= ./libft
LIBFT		= libft.a

PRINTF_DIR	= ./ft_printf
PRINTF_LIB	= libft_printf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Include directory for header files
INC 		= -I$(PIPEX_HEAD) -I$(LIBFT_DIR) -I$(PRINTF_DIR)
INC_BONUS	= -I$(PIPEX_HEAD_BONUS) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Compilation rule for the program
$(NAME): $(LIBFT) $(PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -o $(NAME)

$(NAME_BONUS): $(LIBFT) $(PRINTF_LIB) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -o $(NAME_BONUS)


# Rule to compile object files
$(PIPEX_DIR)/%.o: $(PIPEX_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(PIPEX_DIR_BONUS)/%.o: $(PIPEX_DIR_BONUS)/%.c
	$(CC) $(CFLAGS) $(INC_BONUS) -c $< -o $@

# Rule to make libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to make libft_printf
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)


all:		$(NAME)

bonus:		$(NAME_BONUS)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS) here_doc.txt
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(PRINTF_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(PRINTF_DIR) fclean

re:			fclean all

rec:		clean all

LEAKS_FLAG	= --leak-check=full --trace-children=yes --show-leak-kinds=all -s

test1:
			valgrind $(LEAKS_FLAG) ./$(NAME) "infile.txt" "ls -la" "wc -l" outfile.txt

test2:
			valgrind $(LEAKS_FLAG) ./$(NAME) "infile.txt" "" "wc -l" outfile.txt

test3:
			valgrind $(LEAKS_FLAG) ./$(NAME) "infile.txt" "" "" outfile.txt

test4:
			valgrind $(LEAKS_FLAG) ./$(NAME) "infile.txt" "" "" ""

test5:
			valgrind $(LEAKS_FLAG) ./$(NAME) "infile.txt" "ls -la" "wc -l" ""

testbonus1:
			valgrind $(LEAKS_FLAG) ./$(NAME_BONUS) "infile.txt" "ls -la" "grep 1" "wc -l" "echo 'tester string'" outfile.txt

testbonus2:
			valgrind $(LEAKS_FLAG) ./$(NAME_BONUS) "infile.txt" "" "wc -l" "echo 'tester string'" outfile.txt

testbonus3:
			valgrind $(LEAKS_FLAG) ./$(NAME_BONUS) "infile.txt" "" "" "echo 'tester string'" outfile.txt

testbonus4:
			valgrind $(LEAKS_FLAG) ./$(NAME_BONUS) "infile.txt" "" "" "" ""

testbonus5:
			valgrind $(LEAKS_FLAG) ./$(NAME_BONUS) "infile.txt" "ls -la" "wc -l" ""

testbonus6:
			valgrind $(LEAKS_FLAG) ./$(NAME_BONUS) here_doc END "ls -la" "wc -l" "echo 'tester string'" outfile.txt

testbonus7:
			valgrind $(LEAKS_FLAG) ./$(NAME_BONUS) here_doc END "" "wc -l" "echo 'tester string'" outfile.txt

testbonus8:
			valgrind $(LEAKS_FLAG) ./$(NAME_BONUS) here_doc END "" "" "echo 'tester string'" outfile.txt

testbonus9:
			valgrind $(LEAKS_FLAG) ./$(NAME_BONUS) here_doc END "" "" "" outfile.txt

testbonus10:
			valgrind $(LEAKS_FLAG) ./$(NAME_BONUS) here_doc END "" "" "" ""


.PHONY:		all bonus clean fclean re rec test
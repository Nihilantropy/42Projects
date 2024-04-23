NAME		= pipex

PIPEX_DIR	= ./srcs
PIPEX_HEAD	= ./include

SRCS		= main.c main_utils.c pipex.c pipex_utils.c

OBJS		= $(patsubst %.c, $(PIPEX_DIR)/%.o, $(SRCS))

LIBFT_DIR	= ./libft
LIBFT		= libft.a

PRINTF_DIR	= ./ft_printf
PRINTF_LIB	= libft_printf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM = rm -f

# Include directory for header files
INC 		= -I$(PIPEX_HEAD) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Compilation rule for the program
$(NAME): $(LIBFT) $(PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -o $(NAME)


# Rule to compile object files
$(PIPEX_DIR)/%.o: $(PIPEX_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rule to make libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to make libft_printf
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)


all:		$(NAME)

clean:
			$(RM) $(OBJS) here_doc.txt
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(PRINTF_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(PRINTF_DIR) fclean

re:			fclean all

rec:		clean all

test1:
			valgrind --leak-check=full --trace-children=yes ./$(NAME) "infile.txt" "ls -la" "wc -l" "echo 'tester string'" outfile.txt

test2:
			valgrind --leak-check=full --trace-children=yes ./$(NAME) "infile.txt" "" "wc -l" "echo 'tester string'" outfile.txt

test3:
			valgrind --leak-check=full --trace-children=yes ./$(NAME) "infile.txt" "" "" "echo 'tester string'" outfile.txt

test4:
			valgrind --leak-check=full --trace-children=yes ./$(NAME) "infile.txt" "" "" "" ""

test5:
			valgrind --leak-check=full --trace-children=yes ./$(NAME) "infile.txt" "ls -la" "wc -l" ""

test6:
			valgrind --leak-check=full --trace-children=yes ./$(NAME) here_doc END "ls -la" "wc -l" "echo 'tester string'" outfile.txt

test7:
			valgrind --leak-check=full --trace-children=yes ./$(NAME) here_doc END "" "wc -l" "echo 'tester string'" outfile.txt

test8:
			valgrind --leak-check=full --trace-children=yes ./$(NAME) here_doc END "" "" "echo 'tester string'" outfile.txt

test9:
			valgrind --leak-check=full --trace-children=yes ./$(NAME) here_doc END "" "" "" outfile.txt

test10:
			valgrind --leak-check=full --trace-children=yes ./$(NAME) here_doc END "" "" "" ""

.PHONY:		all clean fclean re rec test
NAME		= libftprintf.a

SRCS		= ft_printf.c

OBJS		= $(SRCS:.c=.o)

HEADER		= libftprintf.h

AR			= ar rcs

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM = rm -f
ifeq ($(OS),Windows_NT)
    RM = del /Q
endif

LIBFT_DIR	= ./Libft

$(NAME):	$(OBJS)	libft
			$(AR) $(NAME) $(OBJS)

libft:
			make -C $(LIBFT_DIR) all

%.o: %.c $(HEADER)
			$(CC) -c $< $(CFLAGS) -o $@ -I$(LIBFT_DIR)


all:		$(NAME)

bonus:		
			make -C $(LIBFT_DIR) bonus

clean:
			$(RM) $(OBJS)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT_DIR) fclean

re:			fclean	all

.PHONY:		all bonus clean fclean re libft

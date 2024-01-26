NAME		= libftprintf.a

LIBFT_DIR	= ./srcs
SRCS		= ft_printf.c ft_check_char.c ft_put.c ft_putchar.c ft_putnbr.c ft_putnbr_hex.c \
				ft_putptr.c ft_putstr.c ft_putuns.c

OBJS		= $(patsubst %.c, $(LIBFT_DIR)/%.o, $(SRCS))

HEADER		= include/ft_printf.h

AR			= ar rcs

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM = rm -f
ifeq ($(OS),Windows_NT)
    RM = del /Q
endif

$(NAME):	$(OBJS)	libft
			$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
			$(CC) -c $< $(CFLAGS) -o $@ -I$(HEADER)


all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean	all

.PHONY:		all clean fclean re libft

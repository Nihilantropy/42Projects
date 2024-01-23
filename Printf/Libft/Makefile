SRCS		= ft_putchar.c ft_putnbr.c ft_putstr.c ft_put.c

OBJS		= $(SRCS:.c=.o)


CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM = rm -f
ifeq ($(OS),Windows_NT)
    RM = del /Q
endif

HEADER		= libft.h

NAME		= libft.a
AR			= ar rcs

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER_FILES)
			$(CC) -c $< $(CFLAGS) -o $@ 

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
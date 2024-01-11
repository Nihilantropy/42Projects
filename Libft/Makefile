#.c file to turn into .o files
SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_memset.c ft_strlen.c \
				ft_atoi.c ft_memset.c ft_bzero.c ft_memmove.c ft_memcpy.c

OBJS		= $(SRCS:.c=.o)


#cc&flags
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

#target name
NAME		= libft.a

#rule all
all			= $(NAME)

#creating library
$(NAME)		$(OBJS)
			ar rcs $(NAME) $(OBJS)

#rules: clean fclean re
clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY		all clean fclean re
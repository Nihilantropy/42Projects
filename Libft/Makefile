#.c file to turn into .o files
SRCS		= ft_memmove.c ft_isalpha ft_isdigit ft_isalnum ft_isprint ft_isascii ft_memset ft_strlen ft_bzero

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
NAME		= libftprintf.a

LIBFT_DIR	= ./srcs
SRCS		= ft_printf.c ft_check_char.c ft_put.c ft_putchar.c ft_putnbr.c ft_putnbr_hex.c \
				ft_putptr.c ft_putstr.c ft_putuns.c ft_calloc.c ft_bzero.c ft_strrev.c ft_strlen.c

OBJS		= $(patsubst %.c, $(LIBFT_DIR)/%.o, $(SRCS))

HEADER_DIR	= ./include

HEADER		= ft_printf.h

AR			= ar rcs

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM = rm -f

$(NAME):	$(OBJS)	libft
			@echo "Creazione della libreria..."
			@$(AR) $(NAME) $(OBJS)
			@echo "Libreria $(NAME) creata con successo."

%.o: %.c $(HEADER_DIR)
			@echo "Compilazione di $<..."
			@$(CC) -c $< $(CFLAGS) -o $@ -I$(HEADER)
			@echo "$@ compilato con successo."

all:		$(NAME)
			@echo "Tutti i target sono stati compilati con successo."

clean:
			@echo "Pulizia dei file oggetto..."
			@$(RM) $(OBJS)
			@echo "File oggetto rimossi con successo."

fclean:		clean
			@echo "Pulizia completa..."
			@$(RM) $(NAME)
			@echo "Libreria $(NAME) e file oggetto rimossi con successo."

re:			fclean	all
			@echo "Ricostruzione completata con successo."

.PHONY:		all clean fclean re libft

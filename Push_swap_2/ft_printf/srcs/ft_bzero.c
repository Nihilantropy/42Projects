#include "../include/ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*buf;

	i = 0;
	buf = s;
	while (i < n)
		buf[i++] = '\0';
}
#include "libft.h"
#include <unistd.h>

void    ft_putchar_fd(char c)
{
    write(1, &c, 1);
}
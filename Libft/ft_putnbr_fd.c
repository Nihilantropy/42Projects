#include "libft.h"
#include <unistd.h>

void    ft_putnbr_fd(int n, int fd)
{
    unsigned int nb;

    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        nb = (unsigned int)(n * -1);
    }
    else
        nb = (unsigned int)n;
    if (nb >= 10)
        ft_putnbr_fd(nb / 10, fd);
    ft_putchar_fd((char)(nb % 10 + 48), fd);
}
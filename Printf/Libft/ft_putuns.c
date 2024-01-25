#include "libft.h"

int    ft_putuns(unsigned int nb)
{
    unsigned int    count;

    count = 0;
    if (nb >= 10)
        count += ft_putuns(nb / 10);
    return (count + ft_putchar((char)(nb % 10 + '0')));
}
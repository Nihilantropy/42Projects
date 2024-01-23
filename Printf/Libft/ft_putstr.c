#include "libft.h"

int ft_putstr(const char *str)
{
    int count;

    count = 0;
    while (*(str))
        ft_putchar(*str++);
    return (count);
}
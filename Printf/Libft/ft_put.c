#include "libft.h"

int    ft_put(char c, va_list args)
{
    int count;

    count = 0;
    if (c == 'c')
        count += ft_putchar(va_arg(args, int));
    else if (c == 'd')
        count += ft_putnbr(va_arg(args, int));
    else if (c == 's')
        count += ft_putstr(va_arg(args, char *));
    return (count);

}
#include "libft.h"

int    ft_put(char c, va_list args)
{
    int count;

    count = 0;
    if (c == '%')
        count += ft_putchar('%');
    else if (c == 'c')
        count += ft_putchar(va_arg(args, int));
    else if (c == 's')
        count += ft_putstr(va_arg(args, char *));
    else if (c == 'd')
        count += ft_putnbr(va_arg(args, int));
    else if (c == 'i')
        count += ft_putnbr(va_arg(args, int));
    else if (c == 'u')
        count += ft_putuns(va_arg(args, unsigned int));
    else if (c == 'p')
        count += ft_putptr(va_arg(args, void *));
    else if (c == 'x' || c == 'X')
        count += ft_putnbr_hex(va_arg(args, int), c);
    return (count);
}
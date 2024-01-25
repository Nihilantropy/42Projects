#include "libftprintf.h"
#include <stdio.h>

int ft_printf(const char *s, ...)
{
    va_list args;
    int count;
    
    va_start(args, s);
    count = 0;
    if (!ft_check_char(s))
        return (0);
    while (*s != '\0')
    {
        if (*s == '%' && *(s + 1) != '\0')
        {
            s++;
            count += ft_put(*s, args);
        }
        else
            count += ft_putchar(*s);
        s++;
    }
    va_end(args);
    return count;
}

int main() 
{
    int x;

    x = ft_printf("vaffanculo,%x", 429496);
    ft_printf("\n%d\n", x);
    return 0;
}


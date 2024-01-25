#include "libft.h"

int ft_check_char(const char *s)
{
    while (*s)
    {
        if (*s == '%' && *(s + 1) != '\0')
        {
            s++;
            if (*s != 'c' && *s != 's' && *s != 'd' && *s != 'i' 
                && *s != 'u' && *s != 'X' && *s != 'x' && *s != 'p')
            {
                ft_putstr("Cazzo fai hai sbagliato!");
                return (0);
            }
        }
        s++;
    }
    return (1);
}
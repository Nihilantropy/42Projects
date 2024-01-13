#include "libft.h"

int ft_toupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}
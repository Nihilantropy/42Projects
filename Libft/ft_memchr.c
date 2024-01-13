#include "libft.h"

void    *ft_memchr(const void *str, int c, size_t sz)
{
    size_t  i;

    i = 0;
    while (i < sz)
    {
        if (((unsigned char *)str)[i] == (unsigned char)c)
            return ((void *)(str + i));
        i++;
    }
    return (NULL);
}
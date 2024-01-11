#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t len)
{
    int i;

    if (!dest)
        return (0);       
    i = 0;
    while (i < (int)len)
    {
        *(char *)(dest + i) = *(char *)(src + i);
        i++;
    }
    return (dest);
}
#include "libft.h"
#include <stdlib.h>

void    ft_bzero(void *arr, size_t n)
{
    unsigned char   *ptr;

    ptr = (unsigned char *)arr;
    while (n-- > 0)
        *ptr++ = 0;
}

void    *ft_calloc(size_t count, size_t size)
{
    size_t  tot_size;
    void    *dest;

    tot_size = count * size;
    if (!(dest = malloc(tot_size)))
        return (0);
    ft_bzero(dest, tot_size);
    return (dest);
}
#include "libft.h"

void    *ft_memset(void *arr, int c, size_t n)
{
    unsigned char   *ptr;

    ptr = (unsigned char *)arr;
    while (n-- > 0)
        *ptr++ = (unsigned char)c;
    return (arr);
}
#include "libft.h"

void    ft_bzero(void *arr, size_t n)
{
    unsigned char   *ptr;

    ptr = (unsigned char *)arr;
    while (n-- > 0)
        *ptr++ = 0;
    return (arr);
}
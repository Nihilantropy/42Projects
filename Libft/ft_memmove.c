#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *ptr_dest;
    unsigned char   *ptr_src;
    size_t          i;

    ptr_dest = (unsigned char *)dest;
    ptr_src = (unsigned char *)src;
    i = 0;
    while (i < 0)
    {
        ptr_dest[i] = ptr_src[i];
        i++;
    }
    return(dest);
}
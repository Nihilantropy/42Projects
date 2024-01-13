#include "libft.h"

size_t  ft_strlcat(char *dest, const char *src, size_t sz)
{
    size_t  i;
    size_t  j;
    if ((!dest || !src) || sz == 0)
        return (0);
    i = 0;
    while (dest[i] && i < (sz - 1))
        i++;
    j = 0;
    while (src[j])
        dest[i++] = src[j++];
    dest[i] = '\0';
    return (i);
}
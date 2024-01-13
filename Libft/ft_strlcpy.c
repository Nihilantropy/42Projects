#include "libft.h"

size_t  ft_strlcpy(char *dest, const char *src, size_t sz)
{
    size_t  i;

    if (!dest || !src)
        return (0);
    i = 0;
    if (sz != 0)
    {
        while (src[i] && i < (sz -1))
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return (i);
}
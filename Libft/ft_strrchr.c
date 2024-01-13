#include "libft.h"

size_t     ft_strlen(const char *str);

char    *ft_strrchr(const char *str, int c)
{
    int i;

    i = ft_strlen(str);
    while (i >= 0)
    {
        if(str[i] == c)
            return ((char *)str + i);
        i--;
    }
    return (NULL);
}
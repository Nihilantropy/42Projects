#include "libft.h"
#include <stdlib.h>

size_t     ft_strlen(const char *str);

void    *ft_memcpy(void *dest, const void *src, size_t len);

char    *ft_strdup(const char *str)
{
    size_t  dup_size;
    char *dup_str;

    dup_size = ft_strlen(str) + 1;
    if (!(dup_str = (char *)malloc(dup_size)))
        return (0);
    ft_memcpy(dup_str, str, dup_size);
    return (dup_str);
}
#include "libft.h"
#include <stdlib.h>

size_t  ft_strlen(const char *str);

char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *str_join;
    size_t  sz_join;
    size_t  i;

    sz_join = ft_strlen(s1) + ft_strlen(s2) + 1;
    if (!(str_join = (char *)malloc(sz_join * sizeof(char))))
        return (0);
    i = 0;
    while(*s1)
        str_join[i++] = *s1++;
    while(*s2)
        str_join[i++] = *s2++;
    str_join[i] = '\0';
    return (str_join);
}
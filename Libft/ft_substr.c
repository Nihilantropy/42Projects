#include "libft.h"
#include <stdlib.h>

size_t  ft_strlen(const char *str);

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    char *  sub_str;
    int     i;

    i = 0;
    if (!s || ft_strlen(s) < start || ft_strlen(s) < len || len < 0 )
        return (0);
    sub_str = (char *)malloc(len * sizeof(char));
    while (start < len && s[start])
        sub_str[i++] = s[start++];
    sub_str[i] = '\0';
    return (sub_str);
}
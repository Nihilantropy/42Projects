#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t len)
{
    int  i;
  
    if (!dest || !src)
        return (0);
    if(dest > src)
    {
        i = (int)len -1;
        while (i >= 0)
        {
            *(char *)(dest + i) = *(char *)(src + i);
            i--;
        }   
    }
    else
    {
        i = 0;
        while (i < (int)len)
        {
            *(char *)(dest + i) = *(char *)(src + i);
            i++;
        }
    }
    return(dest);
}
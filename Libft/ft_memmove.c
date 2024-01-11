#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
/*
int main(int argc, char **argv)
{
    if (argc != 3)
        return (0);
    printf("%s %s\n", argv[1], argv[2]);
    ft_memmove(argv[1], argv[2], strlen(argv[1]));
    printf("%s %s\n", argv[1], argv[2]);    
}
*/
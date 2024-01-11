#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 3)
        return (0);
    printf("%s %s\n", argv[1], argv[2]);

    ft_memmove(argv[1], argv[2], strlen(argv[1]));
    
    printf("%s %s\n", argv[1], argv[2]); 
}

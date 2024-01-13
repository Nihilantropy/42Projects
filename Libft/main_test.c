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

int main (int argc, char **argv)
{
    if (argc != 4)
        return 0;
    int x = ft_strncmp(argv[1], argv[2], ft_atoi(argv[3]));
    printf("%d\n", x);
}

int main (int argc, char **argv)
{
    if (argc != 4)
        return 0;
    printf("%s %s %d\n", argv[1], argv[2], atoi(argv[3]));

    size_t x = ft_strlcpy(argv[1], argv[2], atoi(argv[3]));

    printf("%d\n", x);

    return(1);
    
}

int main()
{
    char a = 'c';
    printf("%c\n", a);
    char x = ft_toupper(a);

    printf("%c\n", x);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    char a = 'a';
    char *x = ft_strrchr(argv[1], a);

    printf("%s\n", x);
}

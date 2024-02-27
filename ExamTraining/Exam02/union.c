#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main (int argc, char **argv)
{
    if (argc != 3)
    {
        ft_putchar('\n');
        return (1);
    }
    char buffer[10000];
    int i = 0;
    int j = 0;
    int isRep = 0;
    while (argv[1][i])
    {
        buffer[i] = argv[1][i];
        i++;
    }
    while (argv[2][j])
    {
        buffer[i++] = argv[2][j++];
    }
    buffer[i] = '\0';
    // printf("%s", buffer);
    i = 1;
    ft_putchar(buffer[0]);
    while (buffer[i])
    {
        j = i - 1;
        while (j >= 0)
        {
            if (buffer[i] == buffer[j])
            {
                isRep = 1;
                break ;
            }
            j--;
        }
        if (isRep == 0)
            ft_putchar(buffer[i]);
        i++;
        isRep = 0;
    }  
    return (0);  
}
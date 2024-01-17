#include "libft.h"
#include <unistd.h>

void    ft_putstr_fd(char *str, int fd)
{
    while (*str)
        write(fd, &*str++, 1);
    write(fd, "\n", 1);
}
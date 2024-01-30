#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *remaining;
    char        buffer[BUFFER_SIZE + 1];
    int         bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX -1)
        return (NULL);
    while (1)
    {
        bytes_read = read(fd, buffe, BUFFER_SIZE);
    }
}
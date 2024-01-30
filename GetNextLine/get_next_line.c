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
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free (remaining);
            remaining = NULL;
            return (NULL);
        }
        if (bytes_read == 0)
            break ;
        buffer[bytes_read] = '\0';
        remaining = ft_strjoin(remaining, buffer);
        if (!remaining)
            return (NULL);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    if ((bytes_read == 0) && (!remaining || *remaining == '\0'))
    {
        free (remaining);
        remaining = NULL;
        return (NULL);
    }
    return (ft_extract_line(&remaining));
}
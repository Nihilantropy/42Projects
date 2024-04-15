#include "get_next_line.h"

int main()
{
    char *line;

    int fd = open("prova.txt", O_RDONLY);
    if (fd <= 0)
        return 0;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
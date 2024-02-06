#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    // Check if the user has provided a filename as an argument
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file specified by the user in the command line argument
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Read and print lines until the end of the file
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Printing the line without additional text
        free(line); // Free the memory allocated by get_next_line
    }

    // Close the file
    close(fd);

    return 0;
}

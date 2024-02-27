#include "../include/so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (ft_printf("Error: Choose a map!\n"));
    init_game();
    ft_printf("%s\n", argv[1]);
}
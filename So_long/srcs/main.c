#include "../include/so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (ft_printf("Error: Choose a map!\n"));
    t_game game;

    game = init_game();
    get_map(argv[1], &game);
}
#include "../include/so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (ft_printf("ERROR! Choose a map!\n"));
    else if (!check_map_ext(argv[1]))
        return (ft_printf("ERROR! Wrong map extention!\n"));
    t_game game;
    game = init_game();
    game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		exit(0);
    get_map(&game, argv[1]);
}
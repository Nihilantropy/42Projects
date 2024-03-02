#include "../include/so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (ft_printf(ERROR_ARG_NBR));
    else if (!check_map_ext(argv[1]))
        return (0);
    t_game game;
    game = init_game();
    game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		exit(0);
    get_map(&game, argv[1]);
    handle_key_event(&game);
    mlx_loop(game.mlx_ptr);
}
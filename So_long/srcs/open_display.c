#include "../include/so_long.h"

void	open_display(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return ;
	game->mlx_win = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, WIN_NAME);
	mlx_loop(game->mlx_ptr);
}
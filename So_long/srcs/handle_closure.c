#include "../include/so_long.h"

int	close_game(void *param)
{
	t_game *game;

	game = param; 
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
    clean_matrix(game);
	exit (0);
}

void    clean_matrix(t_game *game)
{
    int y;

    y = 0;
    while (y < game->map.row)
    {
        free (game->map.matrix[y]);
        y++;
    }
    free(game->map.matrix);
}
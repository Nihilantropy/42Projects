#include "../include/so_long.h"

void	open_display(t_game *game)
{
	window WIDTH = game->win.width;
	window HEIGHT = game->win.height;
	game->mlx_win = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, DISPLAY_NAME);
}

void    get_win_size(t_game *game)
{
    game->win.width = game->map.col * TILE_SIZE;
    game->win.height = game->map.row * TILE_SIZE;
}

void	manage_display(t_game *game)
{
	get_win_size(game);
	open_display(game);
	init_sprites(game);
	render_wall_map(game);
	mlx_loop(game->mlx_ptr);
}
#include "../include/so_long.h"

void    init_sprites(t_game *game)
{
    game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL_SPRITE, &game->tiles.width, &game->tiles.height);
}

void    render_wall_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map.row)
    {
        x = 0;
        while (game->map.matrix[y][x])
        {
            if (game->map.matrix[y][x] == WALL)
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
                    game->tiles.wall, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}
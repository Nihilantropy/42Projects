#include "../include/so_long.h"

void    init_sprites(t_game *game)
{
    void    *mlx_ptr;
    int width;
    int height;

    width = game->tiles.width;
    height = game->tiles.height;
    mlx_ptr = game->mlx_ptr;
    game->tiles.wall = mlx_xpm_file_to_image(mlx_ptr, WALL_SPRITE, &width, &height);
    game->tiles.floor = mlx_xpm_file_to_image(mlx_ptr, FLOOR_SPRITE, &width, &height);
    game->tiles.player = mlx_xpm_file_to_image(mlx_ptr, PLAYER_SPRITE, &width, &height);
    game->tiles.collect = mlx_xpm_file_to_image(mlx_ptr, COLLECT_SPRITE, &width, &height);
    game->tiles.exit = mlx_xpm_file_to_image(mlx_ptr, EXIT_SPRITE, &width, &height);
}

void    render_tiles(t_game *game, char tile)
{
    if (tile == WALL)
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
            game->tiles.wall, game->tiles.x * TILE_SIZE, game->tiles.y * TILE_SIZE);
    else if (tile == FLOOR)
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
            game->tiles.floor, game->tiles.x * TILE_SIZE, game->tiles.y * TILE_SIZE);
    else if (tile == PLAYER)
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
            game->tiles.player, game->tiles.x * TILE_SIZE, game->tiles.y * TILE_SIZE);
    else if (tile == COLLECT)
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
            game->tiles.collect, game->tiles.x * TILE_SIZE, game->tiles.y * TILE_SIZE);
    else if (tile == EXIT)
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
            game->tiles.exit, game->tiles.x * TILE_SIZE, game->tiles.y * TILE_SIZE);
}

void    draw_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map.row)
    {
        x = 0;
        while (game->map.matrix[y][x])
        {
            game->tiles.x = x;
            game->tiles.y = y;
            render_tiles(game, game->map.matrix[y][x]);  
            x++;
        }
        y++;
    }
}
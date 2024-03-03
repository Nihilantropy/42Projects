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
    game->tiles.player_inv = mlx_xpm_file_to_image(mlx_ptr, PLAYER_INV_SPRITE, &width, &height);
    game->tiles.collect = mlx_xpm_file_to_image(mlx_ptr, COLLECT_SPRITE, &width, &height);
    game->tiles.exit = mlx_xpm_file_to_image(mlx_ptr, EXIT_SPRITE, &width, &height);
}

void    render_tiles(t_game *game, char tile)
{
    void *image;

    image = NULL;
    if (tile == WALL)
        image = game->tiles.wall;
    else if (tile == FLOOR)
        image = game->tiles.floor;
    else if (tile == PLAYER && game->map.player_pos.facing_left == 1)
        image = game->tiles.player_inv;
    else if (tile == PLAYER)
        image = game->tiles.player;
    else if (tile == COLLECT)
        image = game->tiles.collect;
    else if (tile == EXIT)
        image = game->tiles.exit;
    if (image)
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
            image, game->tiles.x * TILE_SIZE, game->tiles.y * TILE_SIZE);
}

void    draw_map(t_game *game)
{
    int y;
    int x;

    mlx_clear_window(game->mlx_ptr, game->mlx_win);
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

void    free_images(t_game *game)
{
    mlx_destroy_image(game->mlx_ptr, game->tiles.wall);
    mlx_destroy_image(game->mlx_ptr, game->tiles.floor);
    mlx_destroy_image(game->mlx_ptr, game->tiles.player);
    mlx_destroy_image(game->mlx_ptr, game->tiles.player_inv);
    mlx_destroy_image(game->mlx_ptr, game->tiles.collect);
    mlx_destroy_image(game->mlx_ptr, game->tiles.exit);
}
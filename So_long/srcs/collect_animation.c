#include "../include/so_long.h"

void load_collect_images(t_game *game)
{
    int i;
    int width;
    int height;
    char *collect_frames_paths[COLLECT_ANIM_FRAMES] = { COLLECT_SPRITE_FRAME_1, COLLECT_SPRITE_FRAME_2, 
                            COLLECT_SPRITE_FRAME_3, COLLECT_SPRITE_FRAME_4,
                            COLLECT_SPRITE_FRAME_5, COLLECT_SPRITE_FRAME_6 };

    i = 0;
    width = TILE_SIZE;
    height = TILE_SIZE;
    while (i < COLLECT_ANIM_FRAMES)
    {
        game->tiles.collect.frames[i] = mlx_xpm_file_to_image(game->mlx_ptr, collect_frames_paths[i], &width, &height);
        if (game->tiles.collect.frames[i] == NULL)
            exit(ft_printf(ERROR_COLLECT_IMG_UPLOAD));
        i++;
    }
}

void handle_collect_anim(t_game *game)
{
    game->tiles.collect.anim_counter++;
    if (game->tiles.collect.anim_counter >= FRAME_RATE / 2)
    {
        game->tiles.collect.anim_counter = 0;
        game->tiles.collect.current_frame = (game->tiles.collect.current_frame + 1) % COLLECT_ANIM_FRAMES;
    }
}

void    free_collect_images(t_game *game)
{
    int i;

    i = 0;
    while (i < COLLECT_ANIM_FRAMES)
        mlx_destroy_image(game->mlx_ptr, game->tiles.collect.frames[i++]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:46:20 by crea              #+#    #+#             */
/*   Updated: 2024/03/17 16:15:42 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <../mlx/mlx.h>
# include "messages.h"
# include "keys.h"
# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"

# define FLOOR_SPRITE "Tiles/floor_64_.xpm"

/* wall antimation sprites */
# define WALL_SPRITE_FRAME_1 "Tiles/wall/wall(frame1).xpm"
# define WALL_SPRITE_FRAME_2 "Tiles/wall/wall(frame2).xpm"
# define WALL_SPRITE_FRAME_3 "Tiles/wall/wall(frame3).xpm"
# define WALL_SPRITE_FRAME_4 "Tiles/wall/wall(frame4).xpm"
# define WALL_SPRITE_FRAME_5 "Tiles/wall/wall(frame5).xpm"
# define WALL_SPRITE_FRAME_6 "Tiles/wall/wall(frame6).xpm"
# define WALL_SPRITE_FRAME_7 "Tiles/wall/wall(frame7).xpm"
# define WALL_SPRITE_FRAME_8 "Tiles/wall/wall(frame8).xpm"

/* player animation sprites */
# define PLAYER_SPRITE_FRAME_1 "Tiles/player/player(frame1).xpm"
# define PLAYER_SPRITE_FRAME_2 "Tiles/player/player(frame2).xpm"
# define PLAYER_SPRITE_FRAME_3 "Tiles/player/player(frame3).xpm"
# define PLAYER_SPRITE_FRAME_4 "Tiles/player/player(frame4).xpm"
# define PLAYER_SPRITE_FRAME_5 "Tiles/player/player(frame5).xpm"
# define PLAYER_SPRITE_FRAME_6 "Tiles/player/player(frame6).xpm"
# define PLAYER_SPRITE_FRAME_7 "Tiles/player/player(frame7).xpm"
# define PLAYER_SPRITE_FRAME_8 "Tiles/player/player(frame8).xpm"

/* player inverted animation sprites */
# define PLAYER_INV_SPRITE_FRAME_1 "Tiles/player_inv/player_inv(frame1).xpm"
# define PLAYER_INV_SPRITE_FRAME_2 "Tiles/player_inv/player_inv(frame2).xpm"
# define PLAYER_INV_SPRITE_FRAME_3 "Tiles/player_inv/player_inv(frame3).xpm"
# define PLAYER_INV_SPRITE_FRAME_4 "Tiles/player_inv/player_inv(frame4).xpm"
# define PLAYER_INV_SPRITE_FRAME_5 "Tiles/player_inv/player_inv(frame5).xpm"
# define PLAYER_INV_SPRITE_FRAME_6 "Tiles/player_inv/player_inv(frame6).xpm"
# define PLAYER_INV_SPRITE_FRAME_7 "Tiles/player_inv/player_inv(frame7).xpm"
# define PLAYER_INV_SPRITE_FRAME_8 "Tiles/player_inv/player_inv(frame8).xpm"

/* collectable animation sprites */
# define COLLECT_SPRITE_FRAME_1 "Tiles/collectable/collectable(frame1).xpm"
# define COLLECT_SPRITE_FRAME_2 "Tiles/collectable/collectable(frame2).xpm"
# define COLLECT_SPRITE_FRAME_3 "Tiles/collectable/collectable(frame3).xpm"
# define COLLECT_SPRITE_FRAME_4 "Tiles/collectable/collectable(frame4).xpm"
# define COLLECT_SPRITE_FRAME_5 "Tiles/collectable/collectable(frame4).xpm"
# define COLLECT_SPRITE_FRAME_6 "Tiles/collectable/collectable(frame5).xpm"
# define COLLECT_SPRITE_FRAME_7 "Tiles/collectable/collectable(frame6).xpm"

/* exit animation sprites */
# define EXIT_SPRITE_FRAME_1 "Tiles/exit/exit(frame1).xpm"
# define EXIT_SPRITE_FRAME_2 "Tiles/exit/exit(frame2).xpm"
# define EXIT_SPRITE_FRAME_3 "Tiles/exit/exit(frame3).xpm"
# define EXIT_SPRITE_FRAME_4 "Tiles/exit/exit(frame4).xpm"
# define EXIT_SPRITE_FRAME_5 "Tiles/exit/exit(frame5).xpm"
# define EXIT_SPRITE_FRAME_6 "Tiles/exit/exit(frame6).xpm"
# define EXIT_SPRITE_FRAME_7 "Tiles/exit/exit(frame7).xpm"
# define EXIT_SPRITE_FRAME_8 "Tiles/exit/exit(frame8).xpm"
# define EXIT_SPRITE_FRAME_9 "Tiles/exit/exit(frame9).xpm"
# define EXIT_SPRITE_FRAME_10 "Tiles/exit/exit(frame10).xpm"

# define TILE_SIZE 64

/* game frame rate */
# define FRAME_RATE 6
# define FRAME_TIME_US (100000 / FRAME_RATE)

/* wall animation frames */
# define WALL_ANIM_FRAMES 8

/* player animation frames */
# define PLAYER_ANIM_FRAMES 8

/* collectable animation frames */
# define COLLECT_ANIM_FRAMES 7

/* exit animation frames */
# define EXIT_ANIM_FRAMES 10

# define DISPLAY_NAME "So_longo!"

/* enum for display size */
typedef enum window
{
    WIDTH,
    HEIGHT
}   window;

/* enum for boolean var type */
typedef enum e_bool
{
    false = 0,
    true = 1
}   t_bool;

/* enum for map tiles symbols */
typedef enum map_tiles
{
    FLOOR = '0',
    WALL = '1',
    PLAYER = 'P',
    COLLECT = 'C',
    EXIT = 'E'
}   map_tiles;

/* struct for display size */
typedef struct s_display
{
    int width;
    int height;
}       t_display;

/* struct for player position axis */
typedef struct s_axis
{
    int x;
    int y;
    t_bool  facing_left;
}           t_axis;

/* struct for checking reachable collectables and exit */
typedef struct s_reachable
{
    int     collect_reachable;
    t_bool  exit_reachable;
}           t_reachable;

/* struct for all map specifics */
typedef struct s_map
{
    char        **matrix;
    int         row;
    int         col;
    int         collect;
    int         player;
    int         exit;
    t_reachable reachable;
    t_axis      player_pos;
}           t_map;

/* struct for wall animated tiles */
typedef struct s_wall_anim_sprite
{
    void *frames[WALL_ANIM_FRAMES];
    int current_frame;
    int anim_counter;
} t_wall_anim_sprite;

/* struct for player animated tiles */
typedef struct s_player_anim_sprite
{
    void *frames[PLAYER_ANIM_FRAMES];
    int current_frame;
    int anim_counter;
} t_player_anim_sprite;

/* struct for inverted player animated tiles */
typedef struct s_player_inv_anim_sprite
{
    void *frames[PLAYER_ANIM_FRAMES];
    int current_frame;
    int anim_counter;
} t_player_inv_anim_sprite;

/* struct for exit animated tiles */
typedef struct s_exit_anim_sprite
{
    void *frames[EXIT_ANIM_FRAMES];
    int current_frame;
    int anim_counter;
} t_exit_anim_sprite;

/* struct for collect animated tiles */
typedef struct s_collect_anim_sprite
{
    void *frames[COLLECT_ANIM_FRAMES];
    int current_frame;
    int anim_counter;
} t_collect_anim_sprite;

/* struct for all tiles & sprites specifics */
typedef struct s_tiles
{
    void    *floor;
    t_wall_anim_sprite  wall;
    t_player_anim_sprite    player;
    t_player_inv_anim_sprite    player_inv;
    t_collect_anim_sprite    collect;
    t_exit_anim_sprite    exit;
    int     width;
    int     height;
    int     x;
    int     y;
}           t_tiles;

/* struct for all game's specifics */
typedef struct s_game
{
    t_map   map;
    void    *mlx_ptr;
    void    *mlx_win;
    t_tiles tiles;
    t_display win;
    int     moves;
}           t_game;

/* inline function to initialize the game map, tiles, player_pos & moves, and all checks */
static inline t_game    init_game(void)
{
    return ((t_game)
    {
        .map.matrix = NULL,
        .map.row = 0,
        .map.col = 0,
        .map.collect = 0,
        .map.player = 0,
        .map.exit = 0,
        .map.reachable.collect_reachable = 0,
        .map.reachable.exit_reachable = false,
        .map.player_pos.facing_left = false,
        .tiles.floor = NULL,
        .tiles.wall.current_frame = 0,
        .tiles.wall.anim_counter = 0,
        .tiles.player.current_frame = 0,
        .tiles.player.anim_counter = 0,
        .tiles.player_inv.current_frame = 0,
        .tiles.player_inv.anim_counter = 0,
        .tiles.collect.current_frame = 0,
        .tiles.collect.anim_counter = 0,
        .tiles.exit.current_frame = 0,
        .tiles.exit.anim_counter = 0,
        .tiles.width = TILE_SIZE,
        .tiles.height = TILE_SIZE,
        .tiles.x = 0,
        .tiles.y = 0,
        .moves = 0,
    });
}

/* map extention control */
int check_map_ext(char *map_file);

/* get map */
void    get_map(t_game *game, char *map_file);
int     build_matrix(t_game *game, char *map_file);
int     check_matrix(t_game *game);

/* get map utils */
void    get_map_size(t_game *game, char *map_file);
void    get_map_col(t_game *game);
void    save_player_pos(t_game *game);
void    print_matrix(t_game *game);
void    printf_flood_matrix(t_game *game, t_bool visited[][game->map.col]);

/* map edges controls */
int check_top_map(t_game *game);
int check_bottom_map(t_game *game);
int check_if_rect(t_game *game);
int check_map_sides(t_game *game);
int check_wrong_symb(t_game *game);

/* map internal control */
int check_map_player(t_game *game);
int check_map_exit(t_game *game);
int check_map_collect(t_game *game);
int is_map_complete(t_game *game);

/* animation handler */
int     update_animations(t_game *game);
void    handle_animations(t_game *game);

/* walls sprites animation */
void    load_wall_images(t_game *game);
void    handle_wall_anim(t_game *game);
void    free_wall_images(t_game *game);

/* player sprites animation */
void    load_player_images(t_game *game);
void    handle_player_anim(t_game *game);
void    free_player_images(t_game *game);
void    load_player_inv_images(t_game *game);
void    handle_player_inv_anim(t_game *game);
void    free_player_inv_images(t_game *game);

/* collectable sprites animation */
void    load_collect_images(t_game *game);
void    handle_collect_anim(t_game *game);
void    free_collect_images(t_game *game);

/* exit sprites animation */
void    load_exit_images(t_game *game);
void    handle_exit_anim(t_game *game);
void    free_exit_images(t_game *game);

/* sprites render */
void    init_sprites(t_game *game);
void    render_tiles(t_game *game, char tile);
void    draw_map(t_game *game);
void    free_images(t_game *game);

/* manage display */
void    manage_display(t_game *game);
void    get_win_size(t_game *game);
void	open_display(t_game *game);

/* player movement */
void    handle_key_event(t_game *game);
int     key_press(int keycode, t_game *game);
void    handle_player_movement(t_game *game, int keycode);
void    handle_movement_changes(t_game *game, int new_x, int new_y);

/* player movement utils */
int     is_valide_move(t_game *game, int new_x, int new_y, int keycode);
void    check_if_player_facing_left(t_game *game, int new_x);
void    update_player_pos(t_game *game, int new_x, int new_y);
void    update_collect_count(t_game *game, int new_x, int new_y);
int     check_if_win(t_game *game);

/* handle closure */
void    clean_matrix(t_game *game);
int 	close_game(void *param);

#endif
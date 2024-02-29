/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:46:20 by crea              #+#    #+#             */
/*   Updated: 2024/02/29 21:07:26 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <../mlx/mlx.h>
# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include "keys.h"

# define KEYPRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17

# define WIN_MSG "YOU lucky dog! Congrats! ദ്ദി(˵ •̀ ᴗ - ˵ ) ✧"

# define DISPLAY_NAME "So_longo!"

# define WALL_SPRITE "Tiles/wall.xpm"
# define FLOOR_SPRITE "Tiles/floor.xpm"
# define PLAYER_SPRITE "Tiles/player.xpm"
# define COLLECT_SPRITE "Tiles/collect.xpm"
# define EXIT_SPRITE "Tiles/exit.xpm"

# define TILE_SIZE 32

typedef enum window
{
    WIDTH,
    HEIGHT,
}       window;

typedef enum map_tiles
{
    FLOOR = '0',
    WALL = '1',
    P_START = 'P',
    COLLECT = 'C',
    EXIT = 'E'
}           map_tiles;

typedef struct s_axis
{
    int x;
    int y;
}           t_axis;

typedef struct s_map
{
    char    **matrix;
    int     row;
    int     col;
    int     collect;
    int     p_start;
    int     exit;
    t_axis  player_pos;
}           t_map;

typedef struct s_tiles
{
    void    *wall;
    void    *floor;
    void    *player;
    void    *collect;
    void    *exit;
    int     width;
    int     height;
}           t_tiles;

typedef struct s_display
{
    int width;
    int height;
}              t_display;

typedef struct s_game
{
    t_map   map;
    void    *mlx_ptr;
    void    *mlx_win;
    t_tiles tiles;
    t_display win;
    int     moves;
}           t_game;

static inline t_game    init_game(void)
{
    return ((t_game) {
        .map.matrix = NULL,
        .map.row = 0,
        .map.col = 0,
        .map.collect = 0,
        .map.p_start = 0,
        .map.exit = 0,
        .tiles.wall = NULL,
        .tiles.floor = NULL,
        .tiles.player = NULL,
        .tiles.collect = NULL,
        .tiles.exit = NULL,
        .tiles.width = TILE_SIZE,
        .tiles.height = TILE_SIZE,
        .moves = -1,
    });
}

/* map extention control */
int check_map_ext(char *map_file);

/* get map */
void    get_map(t_game *game, char *map_file);
int     build_matrix(t_game *game, char *map_file);
int     check_matrix(t_game *game);

/* get_map_utils */
void    get_map_size(t_game *game, char *map_file);
void    get_map_col(t_game *game);
void    print_matrix(t_game *game);

/* map edges controls */
int check_top_map(t_game *game);
int check_bottom_map(t_game *game);
int check_if_rect(t_game *game);
int check_map_sides(t_game *game);

/* map internal control */
int check_map_player(t_game *game);
int check_map_exit(t_game *game);
int check_map_collect(t_game *game);

/* sprites render */
void    init_sprites(t_game *game);
void    render_wall_map(t_game *game);

/* Display */
void    manage_display(t_game *game);
void    get_win_size(t_game *game);
void	open_display(t_game *game);


#endif
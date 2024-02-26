/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:46:20 by crea              #+#    #+#             */
/*   Updated: 2024/02/26 20:09:48 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include </Users/crea/Desktop/42projects/So_long/mlx/mlx.h>
# include "error_msg.h"
# include "keys.h"

# define FLOOR '0'
# define WALL '1'
# define P_START 'P'
# define COLLECT 'C'
# define EXIT 'E'

# define KEYPRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17

# define WIN_MSG "YOU lucky dog! Congrats! ദ്ദി(˵ •̀ ᴗ - ˵ ) ✧"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_axis
{
    int x;
    int y;
}       t_axis;

typdef struct s_map
{
    char    **map;
    int     row;
    int     col;
    int     collect;
    int     player_start;
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
}               t_tiles;

typedef struct s_game
{
    t_map   map;
    void    *mlx_ptr;
    void    *mlx_win;
    t_tiles tiles;
    int     moves;
}           t_game;

static t_game    init_game(void)
{
    return ((t_game){
        .map.map = NULL,
        .map.row = 0,
        .map.col = 0,
        .map.collect = 0,
        .map.player_start = 0,
        .map.exit = 0,
        .tiles.wall = NULL,
        .tiles.floor = NULL,
        .tiles.player = NULL,
        .tiles.collect = NULL,
        .tiles.exit = NULL,
        .moves = -1,
    });
}

void    get_map(char *map, t_game *game);


#endif

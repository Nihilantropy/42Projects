/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:46:20 by crea              #+#    #+#             */
/*   Updated: 2024/03/25 17:39:25 by crea             ###   ########.fr       */
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

# define WALL_SPRITE "Tiles/wall_64_.xpm"
# define FLOOR_SPRITE "Tiles/floor_64_.xpm"
# define PLAYER_SPRITE "Tiles/player_64_.xpm"
# define PLAYER_INV_SPRITE "Tiles/player_invert_64_.xpm"
# define COLLECT_SPRITE "Tiles/collectable_64_.xpm"
# define EXIT_SPRITE "Tiles/exit_64_.xpm"

# define DISPLAY_NAME "So_longo!"
# define TILE_SIZE 64

/* enum for display size */
typedef enum window
{
	width,
	height
}	t_window;

/* enum for boolean var type */
typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

/* enum for map tiles symbols */
typedef enum map_tiles
{
	FLOOR = '0',
	WALL = '1',
	PLAYER = 'P',
	COLLECT = 'C',
	EXIT = 'E'
}	t_map_tiles;

/* struct for display size */
typedef struct s_display
{
	int	width;
	int	height;
}	t_display;

/* struct for player position axis */
typedef struct s_axis
{
	int		x;
	int		y;
	t_bool	facing_left;
}	t_axis;

/* struct for checking reachable collectables and exit */
typedef struct s_reachable
{
	int		collect_reachable;
	t_bool	exit_reachable;
}	t_reachable;

/* struct for all map specifics */
typedef struct s_map
{
	char		**matrix;
	int			row;
	int			col;
	int			collect;
	int			player;
	int			exit;
	t_reachable	reachable;
	t_axis		player_pos;
}	t_map;

/* struct for all tiles & sprites specifics */
typedef struct s_tiles
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*player_inv;
	void	*collect;
	void	*exit;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_tiles;

/* struct for all game's specifics */
typedef struct s_game
{
	t_map		map;
	void		*mlx_ptr;
	void		*mlx_win;
	t_tiles		tiles;
	t_display	win;
	int			moves;
}	t_game;

/* inline function to initialize the game map,
	tiles, player_pos & moves, and all checks */
static inline t_game	init_game(void)
{
	return ((t_game){
		.map.matrix = NULL,
		.map.row = 0,
		.map.col = 0,
		.map.collect = 0,
		.map.player = 0,
		.map.exit = 0,
		.map.reachable.collect_reachable = 0,
		.map.reachable.exit_reachable = false,
		.map.player_pos.facing_left = false,
		.tiles.wall = NULL,
		.tiles.floor = NULL,
		.tiles.player = NULL,
		.tiles.player_inv = NULL,
		.tiles.collect = NULL,
		.tiles.exit = NULL,
		.tiles.width = TILE_SIZE,
		.tiles.height = TILE_SIZE,
		.tiles.x = 0,
		.tiles.y = 0,
		.moves = 0,
	});
}

/* map extention control */
int		check_map_ext(char *map_file);

/* get map */
void	get_map(t_game *game, char *map_file);
int		build_matrix(t_game *game, char *map_file);
int		check_matrix(t_game *game);

/* get map utils */
void	get_map_size(t_game *game, char *map_file);
void	get_map_col(t_game *game);
void	save_player_pos(t_game *game);
void	print_matrix(t_game *game);
void	printf_flood_matrix(t_game *game, char **visited);

/* map edges controls */
int		check_top_map(t_game *game);
int		check_bottom_map(t_game *game);
int		check_if_rect(t_game *game);
int		check_map_sides(t_game *game);
int		check_wrong_symb(t_game *game);

/* map internal control */
int		check_map_player(t_game *game);
int		check_map_exit(t_game *game);
int		check_map_collect(t_game *game);
int		is_map_complete(t_game *game);

/* sprites render */
void	init_sprites(t_game *game);
void	render_tiles(t_game *game, char tile);
void	draw_map(t_game *game);
void	free_images(t_game *game);

/* manage display */
void	manage_display(t_game *game);
void	get_win_size(t_game *game);
void	open_display(t_game *game);

/* player movement */
void	handle_key_event(t_game *game);
int		key_press(int keycode, t_game *game);
void	handle_player_movement(t_game *game, int keycode);
void	handle_movement_changes(t_game *game, int new_x, int new_y);

/* player movement utils */
int		is_valide_move(t_game *game, int new_x, int new_y, int keycode);
void	check_if_player_facing_left(t_game *game, int new_x);
void	update_player_pos(t_game *game, int new_x, int new_y);
void	update_collect_count(t_game *game, int new_x, int new_y);
int		check_if_win(t_game *game);

/* handle closure */
void	clean_matrix(t_game *game);
int		close_game(void *param);

#endif
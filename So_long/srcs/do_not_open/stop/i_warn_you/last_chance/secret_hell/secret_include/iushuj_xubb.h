#ifndef IUSHUJ_XUBB_H
# define IUSHUJ_XUBB_H

# include "../../../../../../../include/so_long.h"
# include "secret_images.h"

typedef enum	boss_tile
{
	BOSS = 'B',
}	boss_tile;

typedef struct	s_boss_anim_sprites
{
	void	**frames;
	void	**health;
	int		current_health;
	int		anim_counter;
	int		current_frame;
}			t_boss_anim_sprites;

typedef struct	s_secret_tiles
{
	t_boss_anim_sprites	boss;
	int					width;
	int					height;
	int					x;
	int					y;
}						t_secret_tiles;


typedef struct	s_boss
{
	char				*name;
	int					health;
	t_axis				pos;
}						t_boss;

typedef struct	s_secret_game
{
	t_game			*game;
	t_boss			boss;
	t_secret_tiles	tiles;
	void			*mlx_ptr;
	void			*mlx_win;
}					t_secret_game;

static inline t_secret_game	init_secret_game(void)
{
	return ((t_secret_game)
	{
		.boss.health = 16,
		.boss.name = "Bob",
		.tiles.boss.anim_counter = 0,
		.tiles.boss.current_frame = 0,
		.tiles.boss.current_health = 0,
		.tiles.width = TILE_SIZE,
		.tiles.height = TILE_SIZE,
		.tiles.x = 0,
		.tiles.y = 0,
	});
}

void	init_secret_hell(t_secret_game *secret_game);
void	sxqdwu_cqf(t_secret_game *secret_game);
void	xqdtbu_iushuj_fbqouh_celucudj(t_secret_game *secret_game, int keycode);
void	xqdtbu_iushuj_celucudj_sxqdwui(t_secret_game *secret_game, int new_x, int new_y);
int		auo_fhuii(int keycode, t_secret_game *secret_game);

int		secret_is_valid_move(t_secret_game *secret_game, int new_x, int new_y, int keycode);
void	secret_update_collect_count(t_secret_game *secret_game, int new_x, int new_y);
void	secret_update_player_pos(t_secret_game *secret_game, int new_x, int new_y);
void	secret_check_if_win(t_secret_game *secret_game, int new_x, int new_y);

int		iushuj_wqcu_kftqju(t_secret_game *secret_game);

void	secret_init_sprites(t_secret_game *secret_game);
void	secret_draw_map(t_secret_game *secret_game);
void	secret_render_tiles(t_secret_game *secret_game, char tile);
void	secret_free_images(t_secret_game *secret_game);

void	secret_update_animations(t_secret_game *secret_game);

void	load_boss_images(t_secret_game *secret_game);
void	handle_boss_anim(t_secret_game *secret_game);
void	free_boss_images(t_secret_game *secret_game);


void	load_boss_health_images(t_secret_game *secret_game);
void    free_boss_health_images(t_secret_game *secret_game);

int		player_bump_boss(t_secret_game *secret_game, int new_x, int new_y);
void	update_boss_health(t_secret_game *secret_game);

int		secret_close_game(void *param);

#endif
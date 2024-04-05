#!/bin/bash

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

player_movement_file="$script_dir/../srcs/player_movement.c"

so_long_file="$script_dir/../include/so_long.h"

update_file="$script_dir/../srcs/update.c"

render_map_file="$script_dir/../srcs/render_map.c"

sed -i '' 's/SECRET_LOCKED/SECRET_UNLOCKED/g' "$player_movement_file"

sed -i '' '/#endif/i\
/* oek sqddej ru ijeffut */\
void uisqfu_xubb(t_game *game);\
\
int sedwhqjkbqjyed(t_game *game);\
\
' "$so_long_file"

sed -i '' '/if (current_timestamp() - game->powerup.time >= THE_D_BURNS)/i\
	if (game->uisqfut)\
		mlx_loop_hook(game->mlx_ptr, sedwhqjkbqjyed, game);\
	if (game->iushuj_xubb)\
		uisqfu_xubb(game);\
' "$update_file"
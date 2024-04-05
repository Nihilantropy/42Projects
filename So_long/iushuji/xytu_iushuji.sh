#!/bin/bash

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

player_movement_file="$script_dir/../srcs/player_movement.c"

so_long_file="$script_dir/../include/so_long.h"

update_file="$script_dir/../srcs/update.c"

sed -i '' 's/SECRET_UNLOCKED/SECRET_LOCKED/g' "$player_movement_file"

sed -i '' '/\* oek sqddej ru ijeffut \*/d' "$so_long_file"
sed -i '' '/void uisqfu_xubb(t_game \*game);/,+1d' "$so_long_file"
sed -i '' '/int sedwhqjkbqjyed(t_game \*game);/,+1d' "$so_long_file"

sed -i '' '/if (game->uisqfut)/d' "$update_file"
sed -i '' '/mlx_loop_hook(game->mlx_ptr, sedwhqjkbqjyed, game);/d' "$update_file"
sed -i '' '/if (game->iushuj_xubb)/d' "$update_file"
sed -i '' '/uisqfu_xubb(game);/d' "$update_file"
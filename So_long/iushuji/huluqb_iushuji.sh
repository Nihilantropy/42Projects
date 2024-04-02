#!/bin/bash

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

player_movement_file="$script_dir/../srcs/player_movement.c"

so_long_file="$script_dir/../include/so_long.h"

sed -i '' 's/ft_printf(SECRET_LOCKED);/uisqfu_xubb(game);/g' "$player_movement_file"

sed -i '' '/#endif/i\
/* oek sqddej ru ijeffut */\
void uisqfu_xubb(t_game *game);\
\
' "$so_long_file"
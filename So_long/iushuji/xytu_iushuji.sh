#!/bin/bash

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

player_movement_file="$script_dir/../srcs/player_movement.c"

so_long_file="$script_dir/../include/so_long.h"

sed -i '' 's/uisqfu_xubb(game);/ft_printf(SECRET_LOCKED);/g' "$player_movement_file"

sed -i '' '/\* oek sqddej ru ijeffut \*/d' "$so_long_file"
sed -i '' '/void uisqfu_xubb(t_game \*game);/,+1d' "$so_long_file"

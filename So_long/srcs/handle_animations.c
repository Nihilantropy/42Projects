#include "../include/so_long.h"

void    handle_animations(t_game *game)
{
    handle_wall_anim(game);
    handle_player_anim(game);
    handle_player_inv_anim(game);
    handle_collect_anim(game);
    handle_exit_anim(game);
}

int update_animations(t_game *game)
{
    handle_animations(game);
    draw_map(game);
    usleep(FRAME_TIME_US);
    return (0);
}

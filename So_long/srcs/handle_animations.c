#include "../include/so_long.h"

void    handle_animations(t_game *game)
{
    handle_collect_anim(game);
}

int update_animations(t_game *game)
{
    handle_animations(game);
    draw_map(game);
    usleep(FRAME_TIME_US);
    return (0);
}

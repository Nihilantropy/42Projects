#include "../include/so_long.h"

int is_valide_move(t_game *game, int x, int y)
{
    if (x <= 0 || y <= 0 || x >= game->map.col || y >= game->map.row)
        return (0);
    if (game->map.matrix[y][x] == WALL)
        return (0);
    if (game->map.collect != 0 && game->map.matrix[y][x] == EXIT)
        return (0);
    return 1;
}

void update_player_pos(t_game *game, int new_x, int new_y)
{
    game->map.matrix[game->map.player_pos.y][game->map.player_pos.x] = FLOOR;
    game->map.matrix[new_y][new_x] = PLAYER;
    game->map.player_pos.x = new_x;
    game->map.player_pos.y = new_y;
    game->moves++;
    if (game->map.matrix[game->map.player_pos.y][game->map.player_pos.x] == COLLECT)
    {
        game->map.collect--;
        ft_printf("remaining collectables: %d\n", game->map.collect);
    }
    ft_printf("You made %d moves\n", game->moves);
    return ;
}

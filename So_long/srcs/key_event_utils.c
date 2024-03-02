#include "../include/so_long.h"

int is_valide_move(t_game *game, int x, int y, int keycode)
{
    if (x <= 0 || y <= 0 || x >= game->map.col || y >= game->map.row)
        return (0);
    if (game->map.matrix[y][x] == WALL)
    {
        ft_printf(ERROR_INVALID_ROUT);
        return (0);
    }
    if (game->map.collect != 0 && game->map.matrix[y][x] == EXIT)
    {
        ft_printf(ERROR_EXIT_NOT_OPEN);
        return (0);
    }
    if (keycode == W || keycode == A || keycode == S || keycode == D
        || keycode == UP || keycode == LEFT || keycode == DOWN || keycode == RIGHT)
    {
        game->moves++;
        ft_printf(MOVES_NBR);
        return (1);
    }
    else
        ft_printf(ERROR_INVALID_KEY);
    return (0);
    
}

void update_player_pos(t_game *game, int new_x, int new_y)
{
    game->map.matrix[game->map.player_pos.y][game->map.player_pos.x] = FLOOR;
    game->map.matrix[new_y][new_x] = PLAYER;
    game->map.player_pos.x = new_x;
    game->map.player_pos.y = new_y;
    return ;
}

void    update_collect_count(t_game *game, int new_x, int new_y)
{
    if (game->map.matrix[new_y][new_x] == COLLECT)
    {
        game->map.collect--;
        ft_printf(COLLECTABLES_NBR);
    }
}

int check_if_win(t_game *game)
{
    int y;
    int x;

    y = 1;
    while (y < game->map.row)
    {
        x = 1;
        while (x < game->map.col)
        {
            if (game->map.matrix[y][x] == EXIT)
                return (1);
            x++;
        }
        y++;
    }
    return (0);
}
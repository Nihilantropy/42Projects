#include "../include/so_long.h"

void handle_key_event(t_game *game)
{
    mlx_hook(game->mlx_win, DESTROY_WIN_CLIENT_MSG, 0, close_game, game);
    mlx_key_hook(game->mlx_win, key_press, game);
}

int     key_press(int keycode, t_game *game)
{
    ft_printf("%d\n", keycode); //remove
    if (keycode == ESC)
        close_game(game);
    else
        handle_player_movement(game, keycode);
    return (0);
}

void    handle_player_movement(t_game *game, int keycode)
{
    int delta_x;
    int delta_y;
    int new_x;
    int new_y;

    delta_x = 0;
    delta_y = 0;
    if (keycode == W || keycode == UP)
        delta_y = -1;
    else if (keycode == A || keycode == LEFT)
        delta_x = -1;
    else if (keycode == S || keycode == DOWN)
        delta_y = 1;
    else if (keycode == D || keycode == RIGHT)
        delta_x = 1;
    new_x = game->map.player_pos.x + delta_x;
    new_y = game->map.player_pos.y + delta_y;
    if (is_valide_move(game, new_x, new_y))
    {
        handle_movement_changes(game, new_x, new_y);
    }
}

void    handle_movement_changes(t_game *game, int new_x, int new_y)
{
    if (game->map.matrix[game->map.player_pos.y][game->map.player_pos.x] == COLLECT)
    {
        game->map.collect--;
        ft_printf("remaining collectables: %d\n", game->map.collect);
    }
    update_player_pos(game, new_x, new_y);
    draw_map(game);
    print_matrix(game); //remove
}
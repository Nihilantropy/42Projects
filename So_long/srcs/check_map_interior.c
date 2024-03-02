#include "../include/so_long.h"

int check_map_player(t_game *game)
{
    int y;
    int x;

    y = 1;
    while (y < game->map.row - 1)
    {
        x = 1;
        while (game->map.matrix[y][x])
        {
            if (game->map.matrix[y][x] == PLAYER)
                game->map.player++;
            x++;
        }
        y++;
    }
    if (game->map.player == 1)
    {
        ft_printf(CORRECT_PLAYER_NBR);
        ft_printf(PLAYER_POS);
        return (1);
    }
    else
    {
        ft_printf(ERROR_PLAYER_NBR);
        return (0);
    }
}

int check_map_exit(t_game *game)
{
    int y;
    int x;

    y = 1;
    while (y < game->map.row - 1)
    {
        x = 1;
        while (game->map.matrix[y][x])
        {
            if (game->map.matrix[y][x] == EXIT)
                game->map.exit++;
            x++;
        }
        y++;
    }
    if (game->map.exit == 1)
    {
        ft_printf(CORRECT_EXIT_NBR);
        return (1);
    }
    else
    {
        ft_printf(ERROR_EXIT_NBR);
        return (0);
    }
}

int check_map_collect(t_game *game)
{
    int y;
    int x;

    y = 1;
    while (y < game->map.row - 1)
    {
        x = 1;
        while (game->map.matrix[y][x])
        {
            if (game->map.matrix[y][x] == COLLECT)
                game->map.collect++;
            x++;
        }
        y++;
    }
    if (game->map.collect >= 0)
        return (ft_printf(CORRECT_COLLECT_NBR));
    else
        ft_printf(ERROR_COLLECT_NBR);
    return (0);
    
}

int check_wrong_symb(t_game *game)
{
    int y;
    int x;

    y = 1;
    while (y < game->map.row - 1)
    {
        x = 1;
        while (x < game->map.col - 1)
        {
            if (game->map.matrix[y][x] != WALL && game->map.matrix[y][x] != FLOOR
                && game->map.matrix[y][x] != PLAYER && game->map.matrix[y][x] != COLLECT
                    && game->map.matrix[y][x] != EXIT)
            {
                ft_printf(ERROR_SYMBOL_IN_MAP);
                return (0);
            }
            x++;
        }
        y++;
    }
    ft_printf(CORRECT_SYMBOLS_IN_MAP);
    return (1);
}
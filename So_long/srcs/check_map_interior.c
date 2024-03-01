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
        ft_printf("%d PLAYER START!\n", game->map.player);
        return (1);
    }
    else
    {
        ft_printf("Error\nWrong number of player start: %d\n", game->map.player);
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
        ft_printf("%d EXIT! You can escape hell!\n", game->map.exit);
        return (1);
    }
    else
    {
        ft_printf("Error\nWrong number of exit: %d\n", game->map.exit);
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
    if (game->map.collect > 0)
    {
        ft_printf("%d COLLECTABLES! You can devour the world!\n", game->map.collect);
        return (1);
    }
    else
    {
        ft_printf("Error\nNot enoght collectable: %d\n", game->map.collect);
        return (0);
    }
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
                ft_printf("Error\nWrong symbol in map!\n");
                return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
}
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
            if (game->map.matrix[y][x] == P_START)
                game->map.p_start++;
            x++;
        }
        y++;
    }
    if (game->map.p_start == 1)
    {
        ft_printf("%d PLAYER START!\n", game->map.p_start);
        return (1);
    }
    else
    {
        ft_printf("Error\nWrong number of player start: %d\n", game->map.p_start);
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
    if (game->map.collect == 1)
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
#include "../include/so_long.h"

int check_top_map(t_game *game)
{
    int x;

    x = 0;
    while (game->map.matrix[0][x] != '\n')
    {
        if (game->map.matrix[0][x] != WALL)
        {
            ft_printf(ERROR_MAP_TOP);
            return (0);
        }
        x++;
    }
    ft_printf(MAP_TOP_OK);
    return (1);
}

int check_bottom_map(t_game *game)
{
    int x;

    x = 0;
    while (game->map.matrix[game->map.row - 1][x] != '\n'
        && game->map.matrix[game->map.row - 1][x] != '\0')
    {
        if (game->map.matrix[game->map.row - 1][x] != WALL)
        {
            ft_printf(ERROR_MAP_BOTTOM);
            return (0);
        }
        x++;
    }
    ft_printf(MAP_BOTTOM_OK);
    return (1);
}

int check_map_sides(t_game *game)
{
    int y;

    y = 1;
    while (y < game->map.row)
    {
        if (game->map.matrix[y][0] != WALL || game->map.matrix[y][game->map.col - 1] != WALL)
        {
            ft_printf(ERROR_MAP_SIDES);
            return (0);
        }
        y++;
    }
    ft_printf(MAP_SIDES_OK);
    return (1);
}

int check_if_rect(t_game *game)
{
    int y;
    int x;

    y = 1;
    while (y < game->map.row)
    {
        x = 0;
        while (game->map.matrix[y][x] != '\n' && game->map.matrix[y][x] != '\0')
            x++;
        if (game->map.col != x)
        {
            ft_printf(ERROR_MAP_RECT);
            return (0);
        }
        else
            y++;
    }
    ft_printf(MAP_RECT_OK);
    return (1);
}
#include "../include/so_long.h"

void    get_map_size(t_game *game, char *map_file)
{
    char    *line;
    int     fd;

    fd = open(map_file, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
        return ;
    while (line)
    {
        line = get_next_line(fd);
        game->map.row++;
    }
    close(fd);
    return ;
}

void get_map_col(t_game *game)
{
    int x;
    
    x = 0;
    while (game->map.matrix[0][x] != '\n')
    {
        game->map.col++;
        x++;
    }
    return ;
}

void    print_matrix(t_game *game)
{
    int y;

    y = 0;
    ft_printf("\n");
    while (y < game->map.row)
        ft_printf("%s", game->map.matrix[y++]);
    ft_printf("\n");
}

void printf_flood_matrix(t_game *game, t_bool visited[][game->map.col])
{
    int y;
    int x;

    y = 0;
    ft_printf("\n");
    while (y < game->map.row)
    {
        x = 0;
        while (x < game->map.col)
        {
            if (visited[y][x])
                ft_printf("%d", 1);
            else
                ft_printf("%d", 0);
            x++;
        }
        ft_printf("\n");
        y++;
    }
    ft_printf("\n");
}

void    save_player_pos(t_game *game)
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
            {
                game->map.player_pos.x = x;
                game->map.player_pos.y = y;
                ft_printf(PLAYER_POS);
                return ;
            }
            x++;
        }
        y++;
    }
    return ;
}

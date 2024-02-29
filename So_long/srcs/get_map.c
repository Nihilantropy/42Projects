#include "../include/so_long.h"

void    get_map(t_game *game, char *map_file)
{
    get_map_size(game, map_file);
    game->map.matrix = malloc(game->map.row * sizeof(char *));
    if (!game->map.matrix)
    {
        printf("Can't allocate memory for the map :(");
        return ;
    }
    if (!build_matrix(game, map_file))
        return ;
    else
        open_display();
}

int    build_matrix(t_game *game, char *map_file)
{
    int y;
    int fd;

    fd = open(map_file, O_RDONLY);
    y = 0;
    while (y < game->map.row)
    {
        game->map.matrix[y] = get_next_line(fd);
        y++;
    }
    close(fd);
    print_matrix(game);
    get_map_col(game);
    if (!check_matrix(game))
        return (0);
    else
        return (1);
}

int check_matrix(t_game *game)
{
    if (!check_top_map(game) || !check_bottom_map(game) 
        || !check_if_rect(game) || !check_map_sides(game))
        return (0);
    else
    {
        ft_printf("ALL GOOD! Go haed :)");
        return (1);
    }
}
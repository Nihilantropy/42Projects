#include "../include/so_long.h"

void    get_map(char *map_file, t_game *game)
{
    get_map_size(map_file, game);
    game->map.matrix = malloc(game->map.row * sizeof(char *));
    if (!game->map.matrix)
    {
        printf("Can't allocate memory for the map :(");
        return ;
    }
    build_matrix(game, map_file);
    count_map_col(game);
}

void    get_map_size(char *map_file, t_game *game)
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

void    build_matrix(t_game *game, char *map_file)
{
    int y;
    int fd;

    fd = open(map_file, O_RDONLY);
    y = 0;
    while (y < game->map.row)
    {
        game->map.matrix[y] = get_next_line(fd);
        ft_printf ("%s", game->map.matrix[y]);
        y++;
    }
    close(fd);
}

void count_map_col(t_game *game)
{
    int x;
    
    x = 0;
    while (game->map.matrix[0][x] != '\n')
    {
        game->map.col++;
        x++;
    }
    printf("\n%d\n", game->map.col);
    return ;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (ft_printf("Error: Choose a map!\n"));
    t_game game;

    game = init_game();
    get_map(argv[1], &game);
}
#include "../include/so_long.h"

// Utilizza questa funzione per eseguire il flood fill dalla posizione del giocatore
// e marcare le celle visitate.
static void flood_fill(t_game *game, int x, int y, t_bool visited[][game->map.col])
{
    // Controlla i limiti e se la cella è già stata visitata o è una parete.
    if (x < 0 || y < 0 || x >= game->map.col || y >= game->map.row || visited[y][x] || game->map.matrix[y][x] == WALL)
        return;

    // Marca la cella corrente come visitata.
    visited[y][x] = true;

    // Esegui il flood fill nelle 4 direzioni.
    flood_fill(game, x + 1, y, visited);
    flood_fill(game, x - 1, y, visited);
    flood_fill(game, x, y + 1, visited);
    flood_fill(game, x, y - 1, visited);
}

static int verify_collectibles_and_exit(t_game *game, t_bool visited[][game->map.col])
{
    int collectibles_reachable = 0;
    int exit_reachable = 0;

    for (int y = 0; y < game->map.row; y++)
    {
        for (int x = 0; x < game->map.col; x++)
        {
            if (visited[y][x] && game->map.matrix[y][x] == COLLECT)
                collectibles_reachable++;
            if (visited[y][x] && game->map.matrix[y][x] == EXIT)
                exit_reachable = 1;
        }
    }
    if (collectibles_reachable == game->map.collect && exit_reachable)
    {
        ft_printf("You can get all things and escape!\n");
        return (1);
    }
    else
    {
        if (collectibles_reachable != game->map.collect)
            ft_printf("Error\nSome collectables aren't reachable.\n");
        if (!exit_reachable)
            ft_printf("Error\nExit isn't reachable.\n");
        return (0);
    }
}


int is_map_complete(t_game *game)
{
    t_bool visited[game->map.row][game->map.col];
    ft_memset(visited, false, sizeof(visited));
    flood_fill(game, game->map.player_pos.x, game->map.player_pos.y, visited);
    for (int y = 0; y < game->map.row; y++) {
    for (int x = 0; x < game->map.col; x++) {
        ft_printf("%d", visited[y][x] ? 1 : 0);
    }
    ft_printf("\n");
}
    ft_printf("%d %d\n", game->map.player_pos.x, game->map.player_pos.y);

    if (verify_collectibles_and_exit(game, visited))
        return (ft_printf("Map can be completed!\n"));
    else
    {
        ft_printf("Error\nMap cannot be completed.\n");
        return (0);
    }
}

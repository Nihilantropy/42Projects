#include "../include/so_long.h"

int main()
{
    t_mlx   *mlx;

    mlx = malloc(sizeof(t_mlx));
    if (!mlx)
        return (1);
    
    mlx->mlx = mlx_init();
    if (!mlx->mlx)
    {
        free (mlx);
        return (1);
    }
    
    mlx->mlx_win = mlx_new_window(mlx->mlx, 1920, 1080, "Hello World!");
    if (!mlx->mlx_win)
    {
        free(mlx);
        return (1);
    }

    mlx_loop(mlx->mlx);

    mlx_destroy_window(mlx->mlx, mlx->mlx_win);

    free (mlx);
    return (0);
}
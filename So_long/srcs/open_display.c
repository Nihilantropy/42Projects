#include "../include/so_long.h"

void	open_display(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 700, 500, "So_longo");
	mlx_loop(vars.mlx);
}
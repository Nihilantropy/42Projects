/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:55 by crea              #+#    #+#             */
/*   Updated: 2024/03/25 16:27:29 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf(ERROR_ARG_NBR));
	else if (!check_map_ext(argv[1]))
		return (0);
	game = init_game();
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		exit(0);
	get_map(&game, argv[1]);
	handle_key_event(&game);
	mlx_loop(game.mlx_ptr);
}

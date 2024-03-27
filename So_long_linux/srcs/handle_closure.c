/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_closure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:51 by crea              #+#    #+#             */
/*   Updated: 2024/03/25 16:27:24 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(void *param)
{
	t_game	*game;

	game = param;
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	free_images(game);
	clean_matrix(game);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit (0);
}

void	clean_matrix(t_game *game)
{
	int	y;

	y = game->map.row;
	while (y-- > 0)
		free(game->map.matrix[y]);
	free(game->map.matrix);
}

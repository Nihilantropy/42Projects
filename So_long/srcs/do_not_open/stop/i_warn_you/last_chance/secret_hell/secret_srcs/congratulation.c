/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   congratulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 00:03:04 by crea              #+#    #+#             */
/*   Updated: 2024/04/06 00:25:49 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

int	congratulation(t_game *game)
{
	int len;
	int x;
	int y;
	
	len = ft_strlen(ENTERING_SECRET_HELL);
	x = (game->win.width - (len * 10)) / 2;
	y = game->win.height / 2;
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	if (game->screenup >= CONGRATS)
	{
		game->escaped = false;
		game->secret_hell = true;
		mlx_loop_hook(game->mlx_ptr, game_update, game);
		return (0);
	}
	else
		mlx_string_put(game->mlx_ptr, game->mlx_win, x, y, 0xFFFFFF, ENTERING_SECRET_HELL);
	game->screenup++;
	return (1);
}
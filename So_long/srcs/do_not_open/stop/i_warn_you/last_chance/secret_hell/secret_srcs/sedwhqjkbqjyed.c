/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedwhqjkbqjyed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 00:03:04 by crea              #+#    #+#             */
/*   Updated: 2024/04/05 16:24:00 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/iushuj_xubb.h"

int	sedwhqjkbqjyed(t_game *game)
{
	int len;
	int x;
	int y;
	
	len = ft_strlen(ENTERING_SECRET_HELL);
	x = (game->win.width - (len * 10)) / 2;
	y = game->win.height / 2;
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	if (game->screenup >= 100)
	{
		game->uisqfut = false;
		game->iushuj_xubb = true;
		mlx_loop_hook(game->mlx_ptr, game_update, game);
		return (0);
	}
	else
		mlx_string_put(game->mlx_ptr, game->mlx_win, x, y, 0xFFFFFF, ENTERING_SECRET_HELL);
	game->screenup++;
	return (1);
}
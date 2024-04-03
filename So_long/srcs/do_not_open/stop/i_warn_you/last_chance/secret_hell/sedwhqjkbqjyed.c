/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedwhqjkbqjyed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 00:03:04 by crea              #+#    #+#             */
/*   Updated: 2024/04/04 00:12:17 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "secret_hell.h"

int	sedwhqjkbqjyed(t_game *game)
{
	int len;
	int x;
	int y;
	
	len = ft_strlen(UDJUHYDW_IUSHUJ_XUBB);
	x = (game->win.width - (len * 10)) / 2;
	y = game->win.height / 2;
	game->map.collect = 0;
	game->map.enemies = 0;
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	if (game->screenup >= 500)
	{
		game->uisqfut = false;
		game->iushuj_xubb = true;
		mlx_loop_hook(game->mlx_ptr, game_update, game);
		return (0);
	}
	else
		mlx_string_put(game->mlx_ptr, game->mlx_win, x, y, 0xFFFFFF, UDJUHYDW_IUSHUJ_XUBB);
	game->screenup++;
	return (1);
}
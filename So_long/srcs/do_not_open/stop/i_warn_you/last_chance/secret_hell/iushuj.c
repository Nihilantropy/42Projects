/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iushuj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:53:06 by crea              #+#    #+#             */
/*   Updated: 2024/04/04 00:15:28 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "secret_hell.h"

static void	ft_handle_key_event(t_game *game);

void    uisqfu_xubb(t_game *game)
{
	if (game->map.row < 6 && game->map.col < 6)
		ft_exit_error(UHHEH_CQF_IYPU);
	ft_printf(UISQFUT);
	change_map(game);
	ft_handle_key_event(game);
	return ;
}

int	iushuj_wqcu_kftqju(t_game *game)
{
	if (current_timestamp() - game->powerup.time >= THE_D_BURNS)
		depression_of_the_d(game);
	update_animations(game);
	return (0);
}

static int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		ft_printf(EARLY_GAME_CLOSE);
		close_game(game);
	}
	else
		ft_printf("ciao");
	//handle_secret_movement_changes(game);
	return (0);
}

static void	ft_handle_key_event(t_game *game)
{
	mlx_hook(game->mlx_win, DESTROY_WIN_CLIENT_MSG, 0, close_game, game);
	mlx_key_hook(game->mlx_win, ft_key_press, game);
}
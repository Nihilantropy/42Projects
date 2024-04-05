/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iushuj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:53:06 by crea              #+#    #+#             */
/*   Updated: 2024/04/05 17:42:00 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/iushuj_xubb.h"

void    uisqfu_xubb(t_game *game)
{
	t_secret_game	secret_game;

	secret_game = init_secret_game();
	secret_game.game = game;
	secret_game.mlx_ptr = game->mlx_ptr;
	secret_game.mlx_win = game->mlx_win;
	secret_game.game->moves = 0;
    secret_game.game->map.collect = 0;
	if (game->map.row < 6 && game->map.col < 6)
		ft_exit_error(ERROR_MAP_SIZE);
	ft_printf(ESCAPED);
	init_secret_hell(&secret_game);
	mlx_hook(secret_game.mlx_win, DESTROY_WIN_CLIENT_MSG, 0, secret_close_game, &secret_game);
	mlx_key_hook(secret_game.mlx_win, auo_fhuii, &secret_game);
	mlx_loop_hook(secret_game.mlx_ptr, iushuj_wqcu_kftqju, &secret_game);
	mlx_loop(secret_game.mlx_ptr);
	return ;
}

int	iushuj_wqcu_kftqju(t_secret_game *secret_game)
{
	if (current_timestamp() - secret_game->game->powerup.time >= THE_D_BURNS)
		depression_of_the_d(secret_game->game);
	secret_update_animations(secret_game);
	//boss_mechanics(secret_game);
	return (0);
}

int	auo_fhuii(int keycode, t_secret_game *secret_game)
{
	if (keycode == ESC)
	{
		ft_printf(EARLY_GAME_CLOSE);
		secret_close_game(secret_game);
	}
	else
		xqdtbu_iushuj_fbqouh_celucudj(secret_game, keycode);
	return (0);
}

void	init_secret_hell(t_secret_game *secret_game)
{
	sxqdwu_cqf(secret_game);
	secret_init_sprites(secret_game);
}
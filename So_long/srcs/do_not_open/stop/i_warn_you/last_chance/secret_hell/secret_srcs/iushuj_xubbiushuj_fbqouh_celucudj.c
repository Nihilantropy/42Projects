/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iushuj_xubbiushuj_fbqouh_celucudj.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:29:20 by crea              #+#    #+#             */
/*   Updated: 2024/04/05 16:23:47 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/iushuj_xubb.h"

void	xqdtbu_iushuj_fbqouh_celucudj(t_secret_game *secret_game, int keycode)
{
	int	delta_x;
	int	delta_y;
	int	new_x;
	int	new_y;

	delta_x = 0;
	delta_y = 0;
	if (keycode == W || keycode == UP)
		delta_y = -1;
	else if (keycode == A || keycode == LEFT)
		delta_x = -1;
	else if (keycode == S || keycode == DOWN)
		delta_y = 1;
	else if (keycode == D || keycode == RIGHT)
		delta_x = 1;
	new_x = secret_game->game->map.player_pos.x + delta_x;
	new_y = secret_game->game->map.player_pos.y + delta_y;
	if (secret_is_valid_move(secret_game, new_x, new_y, keycode)
		&& !player_bump_boss(secret_game, new_x, new_y))
		xqdtbu_iushuj_celucudj_sxqdwui(secret_game, new_x, new_y);
	return ;
}

void	xqdtbu_iushuj_celucudj_sxqdwui(t_secret_game *secret_game, int new_x, int new_y)
{
	secret_update_collect_count(secret_game, new_x, new_y);
	secret_check_if_win(secret_game, new_x, new_y);
	secret_update_player_pos(secret_game, new_x, new_y);
	secret_draw_map(secret_game);
	if (secret_game->game->victory == true)
		player_win(secret_game->game);
}
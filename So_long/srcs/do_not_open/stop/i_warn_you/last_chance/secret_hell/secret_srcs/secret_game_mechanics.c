/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_game_mechanics.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:53:39 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:51:01 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void	secret_player_win(t_secret_game *secret_game)
{
	if (secret_game->game->moves <= 100 && !secret_game->cheat_done)
		ft_printf(SECRET_WIN_MSG);
	else if (secret_game->game->moves > 100 && !secret_game->cheat_done)
		ft_printf(SECRET_WIN_JOKE);
	else if (secret_game->cheat_done)
		ft_printf(CHEATER_WIN_MSG);
	secret_close_game(secret_game);
}

int		secret_collect_count(t_secret_game *secret_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < secret_game->game->map.row)
	{
		x = 0;
		while (x < secret_game->game->map.col)
		{
			if (secret_game->game->map.matrix[y][x] == COLLECT)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
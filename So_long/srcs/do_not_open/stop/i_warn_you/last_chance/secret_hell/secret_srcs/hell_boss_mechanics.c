/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_mechanics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:07:22 by crea              #+#    #+#             */
/*   Updated: 2024/04/05 17:37:54 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/iushuj_xubb.h"

int	player_bump_boss(t_secret_game *secret_game, int new_x, int new_y)
{
	if (secret_game->game->map.matrix[new_y][new_x] == BOSS &&
		!secret_game->game->powerup.the_d)
		player_lose(secret_game->game, PLAYER_BUMP_BOSS);
	else if (secret_game->game->map.matrix[new_y][new_x] == BOSS &&
		secret_game->game->powerup.the_d)
	{
		update_boss_health(secret_game);
		return (1);
	}
	return (0);
}

// int	boss_hit_player(t_game *game)
// {
	
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_mechanics_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:08:24 by crea              #+#    #+#             */
/*   Updated: 2024/04/06 00:04:08 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void	update_boss_health(t_secret_game *secret_game)
{
	if (secret_game->boss.is_alive)
	{
		if (secret_game->tiles.boss.current_health < BOSS_HEALTH_FRAMES)
			secret_game->tiles.boss.current_health++;
		if (secret_game->boss.health > 0)
			secret_game->boss.health--;
		return ;
	}
}

void	update_player_health(t_secret_game *secret_game)
{
	if (secret_game->player.is_alive)
	{
		secret_game->player.last_hit = current_timestamp();
		secret_game->player.is_hit = true;
		if (secret_game->player.current_health < BOSS_HEALTH_FRAMES)
			secret_game->player.current_health++;
		if (secret_game->player.health > 0)
			secret_game->player.health--;
		return ;
	}
}

int	is_boss_valid_move(t_secret_game *secret_game, int new_x, int new_y)
{
	if (secret_game->game->map.matrix[new_y][new_x] == WALL || 
		secret_game->game->map.matrix[new_y][new_x] == EXIT ||
		new_x <= 0 || new_y <= 0 ||
		new_x >= secret_game->game->map.col ||
		new_y >= secret_game->game->map.row)
		return (0);
	return (1);
}

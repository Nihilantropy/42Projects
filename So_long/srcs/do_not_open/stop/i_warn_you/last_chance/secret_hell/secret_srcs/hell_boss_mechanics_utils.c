/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_mechanics_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:08:24 by crea              #+#    #+#             */
/*   Updated: 2024/04/05 16:23:40 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/iushuj_xubb.h"

void	update_boss_health(t_secret_game *secret_game)
{
	if (secret_game->tiles.boss.current_health < BOSS_HEALTH_FRAMES)
		secret_game->tiles.boss.current_health++;
	if (secret_game->boss.health > 0)
		secret_game->boss.health--;
	secret_draw_map(secret_game);
}

// int	is_valid_boss_move(t_game *game, int new_x, int new_y)
// {
// 	if (game->map.matrix[new_y][new_x] == WALL ||
// 		game->map.matrix[new_y][new_x] == COLLECT ||
// 		game->map.matrix[new_y][new_x] == EXIT ||
// 		new_x <= 0 || new_y <= 0 ||
// 		new_x >= game->map.col ||
// 		new_y >= game->map.row)
// 		return (0);
// 	return (1);
// }

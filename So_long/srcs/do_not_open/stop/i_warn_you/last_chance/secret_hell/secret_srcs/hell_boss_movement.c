/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:48:57 by crea              #+#    #+#             */
/*   Updated: 2024/04/05 18:22:52 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

// void	boss_patrol(t_game *game)
// {
// 	int	probability;

// 	probability = rand() % BOSS_MOVE_PROB + 1;
// 	if (probability == 1)
// 	{
// 		while (game->map.boss_index < game->map.enemies)
// 		{
// 			if (game->map.boss[game->map.boss_index].alive)
// 				move_boss(game);
// 			game->map.boss_index++;
	
// 		}
// 		game->map.boss_index = 0;
// 	}
// 	return ;
// }


// void move_boss(t_game *game)
// {
// 	int	new_x;
// 	int	new_y;
// 	int	delta_x;
// 	int	delta_y;
// 	int direction;

// 	delta_x = 0;
// 	delta_y = 0;
//     direction = random_range(0, 3);
//     if (direction == 0)
// 		delta_y = -1;
//     else if (direction == 1)
//         delta_y = 1;
//     else if (direction == 2)
// 		delta_x = -1;
//     else if (direction == 3)
// 		delta_x = 1;
// 	else
// 		return ;
// 	new_x = game->map.boss[game->map.boss_index].boss_pos.x + delta_x;
// 	new_y = game->map.boss[game->map.boss_index].boss_pos.y + delta_y;
// 	if (is_valid_boss_move(game, new_x, new_y)
// 		&& !boss_bump_player(game, new_x, new_y))
// 		update_boss_pos(game, new_x, new_y);
// }
// void	update_boss_pos(t_game *game, int new_x, int new_y)
// {
// 	game->map.matrix[game->map.boss[game->map.boss_index].boss_pos.y][game->map.boss[game->map.boss_index].boss_pos.x] = FLOOR;
// 	game->map.matrix[new_y][new_x] = BOSS;
// 	game->map.boss[game->map.boss_index].boss_pos.x = new_x;
// 	game->map.boss[game->map.boss_index].boss_pos.y = new_y;
// }
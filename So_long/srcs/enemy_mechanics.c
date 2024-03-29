/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mechanics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:47:51 by crea              #+#    #+#             */
/*   Updated: 2024/03/29 18:18:10 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	player_got_caught(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == ENEMY)
		player_lose(game, PLAYER_GOT_CAUGHT);
	return (0);
}

int		enemy_got_player(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == PLAYER)
		player_lose(game, ENEMY_GOT_PLAYER);
	return (0);
}

int	enemy_patrol(t_game *game)
{
	int	enemy_index;
	int	wait_time;

	enemy_index = 0;
	while (enemy_index < game->map.enemies)
	{
		move_enemy(game, enemy_index);
		enemy_index++;
	}
	wait_time = random_range(500000, 1500000);
	usleep(FRAME_TIME_US);
	return (0);

}

void move_enemy(t_game *game, int enemy_index)
{
	int	new_x;
	int	new_y;
	int	delta_x;
	int	delta_y;
	int direction;

	delta_x = 0;
	delta_y = 0;
    direction = random_range(0, 3);
    if (direction == 0)
		delta_y = -1;
    else if (direction == 1)
        delta_y = 1;
    else if (direction == 2)
		delta_x = -1;
    else if (direction == 3)
		delta_x = 1;
	else
		return ;
	new_x = game->map.enemy.enemy_pos[enemy_index].x + delta_x;
	new_y = game->map.enemy.enemy_pos[enemy_index].y + delta_y;
	if (is_valid_enemy_move(game, new_x, new_y)
		&& !enemy_got_player(game, new_x, new_y))
		update_enemy_pos(game, new_x, new_y, enemy_index);
	
}
void	update_enemy_pos(t_game *game, int new_x, int new_y, int enemy_index)
{
	game->map.matrix[game->map.enemy.enemy_pos[enemy_index].y][game->map.enemy.enemy_pos[enemy_index].x] = FLOOR;
	game->map.matrix[new_y][new_x] = ENEMY;
	game->map.enemy.enemy_pos[enemy_index].x = new_x;
	game->map.enemy.enemy_pos[enemy_index].y = new_y;
}
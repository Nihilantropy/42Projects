/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_mechanics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:07:22 by crea              #+#    #+#             */
/*   Updated: 2024/04/05 23:26:21 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void	boss_patrol(t_secret_game *secret_game)
{
	int	probability;

	probability = rand() % BOSS_MOVE_PROB + 1;
	if (probability == 1)
		move_boss(secret_game);
	return ;
}

void move_boss(t_secret_game *secret_game)
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
	new_x = secret_game->boss.pos.x + delta_x;
	new_y = secret_game->boss.pos.y + delta_y;
	if (is_boss_valid_move(secret_game, new_x, new_y)
		&& !boss_hit_player(secret_game, new_x, new_y))
		secret_update_boss_pos(secret_game, new_x, new_y);
}

void	secret_update_boss_pos(t_secret_game *secret_game, int new_x, int new_y)
{
	secret_update_boss_collect_count(secret_game, new_x, new_y);
	secret_game->game->map.matrix[secret_game->boss.pos.y][secret_game->boss.pos.x] = FLOOR;
	secret_game->game->map.matrix[new_y][new_x] = BOSS;
	secret_game->boss.pos.x = new_x;
	secret_game->boss.pos.y = new_y;
	secret_draw_map(secret_game);
}

int player_bump_boss(t_secret_game *secret_game, int new_x, int new_y)
{
	char	current_tile;
	
	current_tile = secret_game->game->map.matrix[new_y][new_x];
	if (current_tile == BOSS)
	{
		if (!secret_game->game->powerup.the_d)
			player_lose(secret_game->game, PLAYER_BUMP_BOSS);
		else if (secret_game->game->powerup.the_d && secret_game->boss.health > 1)
		{
			update_boss_health(secret_game);
			return (1);
		}
		else if (secret_game->game->powerup.the_d && secret_game->boss.health <= 1)
		{
			secret_game->boss.is_alive = false;
			ft_printf("You defeated the boss!\n");
			ft_printf("boss is alive? %d\n", secret_game->boss.is_alive);
			handle_secret_movement_changes(secret_game, new_x, new_y);
			return (1);
		}	
	}
	return (0);
}

int	boss_hit_player(t_secret_game *secret_game, int new_x, int new_y)
{
	char	current_tile;
	
	current_tile = secret_game->game->map.matrix[new_y][new_x];
	if (current_tile == PLAYER)
	{
		if (!secret_game->game->powerup.the_d && secret_game->player.is_alive)
			player_lose(secret_game->game, BOSS_DESTROY_PLAYER);
		else if (secret_game->game->powerup.the_d && secret_game->player.health > 1)
		{
			update_player_health(secret_game);
			return (1);
		}
		else if (secret_game->game->powerup.the_d && secret_game->player.health <= 1)
		{
			secret_game->player.is_alive = false;
			player_lose(secret_game->game, BOSS_DESTROY_PLAYER);
			return (0);
		}	
	}
	return (0);
}

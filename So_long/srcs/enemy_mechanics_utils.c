/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mechanics_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:25:43 by crea              #+#    #+#             */
/*   Updated: 2024/03/29 17:57:14 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	build_enemy_arr(t_game *game)
{
	int		enemy_nbr = game->map.enemies;

	game->map.enemy.enemy_pos = malloc(sizeof(t_axis) * enemy_nbr);
	if (!game->map.enemy.enemy_pos)
		ft_exit_error(ERROR_ENEMY_ALLOC);
}

void	save_enemy_pos(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = 1;
	i = 0;
	while (y < game->map.row - 1)
	{
		x = 1;
		while (game->map.matrix[y][x])
		{
			if (game->map.matrix[y][x] == ENEMY && i < game->map.enemies)
			{
				game->map.enemy.enemy_pos[i].x = x;
				game->map.enemy.enemy_pos[i].y = y;
				ft_printf(ENEMY_POS);
				i++;
			}
			x++;
		}
		y++;
	}
	return ;
}

int	is_valid_enemy_move(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == WALL
		|| game->map.matrix[new_y][new_x == COLLECT]
		|| new_x <= 0 || new_y <= 0
		|| new_x >= game->map.col
		|| new_y >= game->map.row)
		return (0);
	return (1);
}

void	free_enemy_arr(t_game *game)
{
	free(game->map.enemy.enemy_pos);
}

void	handle_enemy(t_game *game)
{
	build_enemy_arr(game);
	save_enemy_pos(game);
}

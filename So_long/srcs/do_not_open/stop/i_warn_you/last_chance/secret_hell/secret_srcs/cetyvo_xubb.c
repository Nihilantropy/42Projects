/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cetyvo_xubb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 00:03:00 by crea              #+#    #+#             */
/*   Updated: 2024/04/05 16:23:29 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/iushuj_xubb.h"

static void	vybb_cqf(t_secret_game *secret_game);

static void	fkj_reii(t_secret_game *secret_game);

void	sxqdwu_cqf(t_secret_game *secret_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < secret_game->game->map.row)
	{
		x = 0;
		while (x < secret_game->game->map.col)
		{
			secret_game->game->map.matrix[0][x] = WALL;
			secret_game->game->map.matrix[secret_game->game->map.row - 1][x] = WALL;
			if (secret_game->game->map.matrix[y][x] != PLAYER 
				&& ((y + 1) != secret_game->game->map.row))
				secret_game->game->map.matrix[y][x] = FLOOR;
			x++;
		}
		secret_game->game->map.matrix[y][0] = WALL;
		secret_game->game->map.matrix[y][secret_game->game->map.col - 1] = WALL;
		y++;
	}
	vybb_cqf(secret_game);
	fkj_reii(secret_game);
	return ;
}

static void	vybb_cqf(t_secret_game *secret_game)
{
	int	x;
	int	y;
	int	rand;
	
	y = 0;
	while (y < secret_game->game->map.row)
	{
		x = 0;
		while (x < secret_game->game->map.col)
		{
			if (secret_game->game->map.matrix[y][x] != PLAYER &&
				secret_game->game->map.matrix[y][x] != WALL)
			{
				rand = random_range(1, 10);
				if (rand == 1)
				{
					secret_game->game->map.matrix[y][x] = COLLECT;
					secret_game->game->map.collect++;
				}
			}
			x++;
		}
		y++;
	}
	secret_game->game->map.matrix[secret_game->game->map.row - 2][secret_game->game->map.col - 2] = EXIT;
	return ;
}

static void	fkj_reii(t_secret_game *secret_game)
{
	int	x;
	int	y;

	x = secret_game->game->map.col / 2;
	y = secret_game->game->map.row / 2 - 2;
	if (secret_game->game->map.matrix[y][x] == PLAYER)
	{
		x += 1;
		y += 1;
	}
	secret_game->game->map.matrix[y][x] = BOSS;
	secret_game->boss.pos.y = y;
	secret_game->boss.pos.x = x;
	ft_printf(BOSS_POSITION);
	print_matrix(secret_game->game);
	return ;
}

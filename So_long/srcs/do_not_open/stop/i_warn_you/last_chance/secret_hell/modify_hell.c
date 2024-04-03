/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_hell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 00:03:00 by crea              #+#    #+#             */
/*   Updated: 2024/04/04 00:20:19 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "secret_hell.h"

static void	fill_map(t_game *game);

static void	put_boss(t_game *game);

void	change_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			game->map.matrix[0][x] = WALL;
			game->map.matrix[game->map.row - 1][x] = WALL;
			if (game->map.matrix[y][x] != PLAYER && ((y + 1) != game->map.row))
				game->map.matrix[y][x] = FLOOR;
			x++;
		}
		game->map.matrix[y][0] = WALL;
		game->map.matrix[y][game->map.col - 1] = WALL;
		y++;
	}
	fill_map(game);
	put_boss(game);
	return ;
}

static void	fill_map(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			if (game->map.matrix[y][x] != PLAYER &&
				game->map.matrix[y][x] != WALL)
			{
					if ((x % 15) + (y % 3) == 1)
					{
						game->map.matrix[y][x] = COLLECT;
						game->map.collect++;
					}
			}
			x++;
		}
		y++;
	}
	game->map.matrix[game->map.row - 2][game->map.col - 2] = EXIT;
}

static void	put_boss(t_game *game)
{
	int	x;
	int	y;

	x = game->map.col / 2;
	y = game->map.row / 2 - 2;
	if (game->map.matrix[y][x] == PLAYER)
	{
		x += 2;
		y += 1;
	}
	game->map.matrix[y][x] = ENEMY;
}

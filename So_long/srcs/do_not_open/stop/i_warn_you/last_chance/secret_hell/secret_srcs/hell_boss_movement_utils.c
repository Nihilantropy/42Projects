/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_movement_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:32 by crea              #+#    #+#             */
/*   Updated: 2024/04/06 00:11:34 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void	secret_update_boss_collect_count(t_secret_game *secret_game, int new_x, int new_y)
{
	if (secret_game->game->map.matrix[new_y][new_x] == COLLECT)
	{
		secret_game->game->map.collect--;
		if (secret_game->game->map.collect > 0)
			ft_printf(SECRET_BOSS_COLLECTABLES_NBR);
		else if (secret_game->game->map.collect == 0)
		{
			secret_game->game->map.collect = -1;	
			ft_printf(CANT_ESCAPE);
		}
	}
}

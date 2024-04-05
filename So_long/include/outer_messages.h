/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outer_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:33:25 by crea              #+#    #+#             */
/*   Updated: 2024/04/05 17:15:04 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTER_MESSAGES_H
# define OUTER_MESSAGES_H

# define ERROR_MAP_SIZE "\nHey, map is not large enough! Secret hell is not a weiner\n"
# define ESCAPED "\nYou escaped from hell!\n"
# define ENTERING_SECRET_HELL "\n...You are now in the secret hell! The bottom of the barrle my friend...\n"

# define BOSS_POSITION "\nenemy pos is {%d} {%d}\n", secret_game->boss.pos.y, secret_game->boss.pos.x
# define SECRET_COLLECTABLES_NBR "\nRemaining bones: %d. You're boner is getting harder!\n", secret_game->game->map.collect
# define SECRET_ALL_COLLECT_PICKEDUP "\nAll bones picked up. You can run if you want...\n"
# define SECRET_FINAL_PLAYER_POS "\nYou've reached the portal, on position {%d} {%d}!\n", secret_game->game->map.player_pos.x, secret_game->game->map.player_pos.y

# define ERROR_BOSS_ALLOC_FRAME "\nError. Can't allocate memory for boss frame array.\n"
# define ERROR_BOSS_IMG_UPLOAD "\nError. Can't upload boss images\n"
# define ERROR_BOSS_ALLOC_HEALTH "\nError. Can't allocate boss health images\n"
# define ERROR_BOSS_HEALTH_IMG_UPLOAD "\nError. Can't upload boss health images\n"

# define PLAYER_BUMP_BOSS "\nMake sure to have your D on flame next time! What an idiot...\n"


#endif
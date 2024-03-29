/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:04:59 by crea              #+#    #+#             */
/*   Updated: 2024/03/28 11:46:56 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

/* main */
# define ERROR_ARG_NBR "Error\nChoose a map!\n"

/* check_map_extention */
# define CORRECT_MAP_EXT "\nMap extention in good! Bravo!\n"
# define ERROR_MAP_EXT "\nError\nWrong map extention! .ber is not that hard... Not that easy too tho.\n"

/* get_map */
# define ERROR_MATRIX_ALLOC "Error\nCan't allocate memory for the map! Nothing else to say...\n"
# define MAP_CHECK_OK "ALL good! Go haed hellwalker Skeletronk!\n\n"

/* get_map_utils */
# define PLAYER_POS "Skeletronk position is {%d} {%d}\n", x, y
# define ERROR_CANT_OPEN_MAP_FILE "Error\nMap file can't be open. Have you checked the name of the map file?\n"

/* check_map_interior */
# define CORRECT_PLAYER_NBR "%d PLAYER START! The one and only... Skeletronk!!!\n", game->map.player
# define ERROR_PLAYER_NBR "Error\nWrong number of player start: %d\n", game->map.player
# define CORRECT_EXIT_NBR "%d EXIT! You can escape hell!\n", game->map.exit
# define ERROR_EXIT_NBR "Error\nWrong number of exit: %d. What are you? A pussycat?\n", game->map.exit
# define CORRECT_COLLECT_NBR "%d COLLECTABLES to pick up! Your D is knocking on heaven's door!\n", game->map.collect
# define ERROR_COLLECT_NBR "Error\nNot enoght bones: %d. What about your boner? It's sad, isn't it?\n", game->map.collect
# define CORRECT_SYMBOLS_IN_MAP "All symbols in map are good! Great job my hellwalker!\n"
# define ERROR_SYMBOL_IN_MAP "Error\nWrong symbol in map! Cheating isn't allowd here! Try in 42...\n"

/* check_map_edges */
# define ERROR_MAP_TOP "Error\nHell top isn't closed! Angles will pee on you!\n"
# define MAP_TOP_OK "Hell top is well closed! You won't get wet!\n"
# define ERROR_MAP_BOTTOM "Error\nHell boottom isn't closed! You'll drown in pee!\n"
# define MAP_BOTTOM_OK "Hell bottom is well closed! You won't drown in pee!\n"
# define ERROR_MAP_SIDES "Error\nSides are open! They will reach you...\n"
# define MAP_SIDES_OK "Hell sides are well-fanced! They won't be able to reach you...\n"
# define ERROR_MAP_RECT "Error\nHell is what? circol? triangle? wtf?! Make a rectangle!\n"
# define MAP_RECT_OK "Your Hell is perfectly square! Top notch!\n"

/* che_if_map_is_complete */
# define MAP_CAN_BE_COMPLETED "You can get all your bones and escape! Go get that boner!\n"
# define ERROR_CANT_REACH_COLLECT "Error\nSome of your bones are trapped! Oh no! Your boner!!!.\n"
# define ERROR_CANT_REACH_EXIT "Error\nSomeone doesn't want you to escape... What a coward.\n"
# define ERROR_MAP_CANT_BE_COMPLETED "You won't be able to escape hell... Ask your daddy for help.\n"
# define ERROR_BOOL_MATRIX_ALLOC "Error\nCan't allocate the boolean matrix.\n"

/* images upload */
# define ERROR_WALL_IMG_UPLOAD "Error\nCan't upload wall images.\n"
# define ERROR_PLAYER_IMG_UPLOAD "Error\nCan't upload player images.\n"
# define ERROR_PLAYER_INV_IMG_UPLOAD "Error\nCan't upload player inverted images.\n"
# define ERROR_COLLECT_IMG_UPLOAD "Error\nCan't upload collectable images.\n"
# define ERROR_EXIT_IMG_UPLOAD "Error\nCan't upload exit images.\n"

/* render map */
# define ERROR_FREE_IMAGE "Error\nCan't deallocate memory for some images.\n"

/* player_movement_utils */
# define ERROR_INVALID_ROUT "Error\nAre you trying to brake the wall? What are you, a Pink floyd fan?\n\n"
# define ERROR_INVALID_KEY "Error\nTry to smash another button... Or I'll smash your sis.\n"
# define COLLECTABLES_NBR "Remaining bones: %d. You're boner is getting harder!\n\n", game->map.collect
# define ALL_COLLECT_PICKEDUP "You've earned FULL POWER! Don't waste time! Your boner might disappear!\n\n"
# define MOVES_NBR "You've made %d moves! Keep goin Skeletronk!\n", game->moves
# define ERROR_EXIT_NOT_OPEN "Error\nDo you have all the bones? Are you sure? That doesn't seems a big boner to me...\n"
# define NEW_PLAYER_POS "Your new position is {%d} {%d}! Keep navigate hell!\n", game->map.player_pos.x, game->map.player_pos.y
# define FINAL_PLAYER_POS "You've reached the portal, on position {%d} {%d}!\n", game->map.player_pos.x, game->map.player_pos.y

/* player_movement */
# define EARLY_GAME_CLOSE "Leaving hell? already? what about your boner???\n"
# define FINAL_MOVE "\nYou got that boner with only %d moves! You're a real champ!\n", game->moves
# define FINAL_MOVE_JOKE "\n%d moves to get a boner??? Should i call you Rocco or just turtle? Anyway...\n", game->moves
# define WIN_MSG "\n##########################\n#                        #\n# WHAT AN AMAZING BONER! #\n#                        #\n#        CONGRATS!       #\n#                        #\n##########################\n"
# define WIN_MSG_JOKE "\n##################################\n#                                #\n# A PERFECTLY RESPECTABLE BONER! #\n#                                #\n#        CONGRATS TURTLE!        #\n#                                #\n##################################\n"

#endif
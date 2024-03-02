#ifndef MESSAGES_H
# define MESSAGES_H

/* main */
# define ERROR_ARG_NBR "Error\nChoose a map!\n"

/* check_map_extention */
# define CORRECT_MAP_EXT "\nMap extention in good! Bravo!\n"
# define ERROR_MAP_EXT "\nError\nWrong map extention! .ber is not that hard... Not that easy too tho.\n"

/* get_map */
# define ERROR_MATRIX_ALLOC "Error\nCan't allocate memory for the map! Nothing else to say...\n"
# define MAP_CHECK_OK "ALL good! Go haed hellwalker Skeletronk!\n"

/* get_map_utils */
# define PLAYER_POS "Skeletronk position is {%d} {%d}\n", x, y

/* check_map_interior */
# define CORRECT_PLAYER_NBR "%d player start! The one and only... Skeletronk!!!\n", game->map.player
# define ERROR_PLAYER_NBR "Error\nWrong number of player start: %d\n", game->map.player
# define CORRECT_EXIT_NBR "%d EXIT! You can escape hell!\n", game->map.exit
# define ERROR_EXIT_NBR "Error\nWrong number of exit: %d. What are you? A pussycat?\n", game->map.exit
# define CORRECT_COLLECT_NBR "%d COLLECTABLES! You can devour the world!\n", game->map.collect
# define ERROR_COLLECT_NBR "Error\nNot enoght collectable: %d\n. Is it possible tho?", game->map.collect
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

/* key_event_utils */
# define ERROR_INVALID_ROUT "Error\nAre you trying to brake the wall? What are you, a Pink floyd fan?\n"
# define ERROR_INVALID_KEY "Error\nTry to smash another button... Or I'll smash your sis.\n"
# define COLLECTABLES_NBR "Remaining bones: %d. You're boner is getting harder!\n", game->map.collect
# define MOVES_NBR "You made %d moves! Keep goin Skeletronk!\n", game->moves
# define ERROR_EXIT_NOT_OPEN "Error\nDo you have all the bones? Are you sure? That doesn't seems a big boner to me...\n"

/* key_event */
# define WIN_MSG "WHAT AN AMAZING BONER!!!"

#endif
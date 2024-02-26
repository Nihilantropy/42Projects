/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:46:13 by crea              #+#    #+#             */
/*   Updated: 2024/02/26 17:47:40 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define MALLOC_ERROR "Malloc allocation failed!"
# define MLX_INIT_ERROR "Failed to init mlx"
# define MLX_NEW_WIN_ERROR "Failed to open new window"
# define ARG_NBR_ERROR "Invalid number of arguments"
# define NULL_MAP_ERROR "Null map argument"
# define INVALID_ENTITY_ERROR "Invalid entity on map's file"
# define INVALID_MAP_FORMAT "Invalid map format"
# define INVALID_MAP_CLOSURE "Map isn't close"
# define INVALID_NBR_EXIT "Invalid number of exit (E)"
# define INVALID_NBR_COLLECT "Invalid number of collectables (C)"
# define INVALID_NBR_PLAYER "Invalid number of player starter position (P)"
# define UNACHIVABLE_COLLECT "Collectables can't be collected"
# define INVALID_MAP_EXT "Invalid map file extension (.ber)"
# define OPEN_MAP_FAIL "Failed to open map file"
# define EMPTY_MAP_FILE "Map file is empty"
# define WALL_XPM_ERROR "Failed to open wall file image (.xpm)"
# define FLOOR_XPM_ERROR "Failed to open floor file image (.xpm)"
# define PLAYER_XPM_ERROR "Failed to open player file image (.xpm)"
# define COLLECT_XPM_ERROR "Failed to open collectable file image (.xpm)"
# define EXIT_XPM_ERROR "Failed to open exit file image (.xpm)"

#endif

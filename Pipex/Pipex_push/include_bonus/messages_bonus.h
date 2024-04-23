/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:47:33 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 21:39:01 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_BONUS_H
# define MESSAGES_BONUS_H

# define ERROR_ARG_NBR "Error\nTry like this: < in_file cmd cmd out_file >\n"
# define ERROR_MATRIX_EMPTY "Error\nYou've passed an empy string.\n"

# define ERROR_OPEN_FILE "Error on 'read file' opening.\n"
# define ERROR_WRITE_FILE "Error on write file creation.\n"
# define PIPE_ERROR "Error\nPipe error -1\n"
# define FORK_ERROR "Error\nFork error -1\n"
# define ERROR_MATRIX_ALLOC "Error\nCan't allocate memory for matrix\n"

# define ERROR_CHILD_OPEN "Error\nCan't open file in child proc. Exit -1\n"
# define ERROR_PARENT_OPEN "Error\nCan't open file in parent proc. Exit -1\n"

# define ERROR_CMD_PATH "Error\nCan't find command in PATH\n"
# define ERROR_EXECVE "Error\nExecve exit -1\n"

#endif
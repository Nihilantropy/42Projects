/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:47:33 by crea              #+#    #+#             */
/*   Updated: 2024/04/17 16:18:03 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define ERROR_ARG_NBR "Error\nTry with 4 arg, like this: < in_file cmd cmd out_file >\n"
# define ERROR_ARG_SYNTAX "Error\nArgument syntax isn't correct.\n"
# define ERROR_FDS_ALLOC "Error\nCan't allocate memory for fds file descriptor\n"
# define PIPE_ERROR "Error\nPipe error -1\n"
# define FORK_ERROR "Error\nFork error -1\n"
# define ERROR_MATRIX_ALLOC "Error\nCan't allocate memory for matrix\n"

# define ERROR_CHILD_OPEN "Error\nCan't open file in child proc. Exit -1\n"
# define ERROR_PARENT_OPEN "Error\nCan't open file in parent proc. Exit -1\n"

# define ERROR_CMD_PATH "Error\nCan't find command in PATH\n"
# define ERROR_EXECVE "Error\nExecve exit -1\n"


#endif
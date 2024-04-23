/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:29:19 by crea              #+#    #+#             */
/*   Updated: 2024/04/17 16:17:21 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "messages.h"
# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"

# define INDEX_TEMP_FILE "./cmd_index_file.tmp"

typedef struct s_cmd
{
	char	**matrix;
	int		pipes_nbr;
	int		index;
	char	**total_path;
}			t_cmd;

/* pipex */
void	process_child(t_cmd *cmd, char *command, char **envp);
void	process_parent(t_cmd *cmd, char *command, char **envp);
void	exe_cmd(t_cmd *cmd, char *command, char **envp);
char	*find_cmd_path(t_cmd *cmd, char *command);

/* main utils */
void	init_cmd(t_cmd *cmd, int argc, char **argv, char **envp);
char	**build_cmd_matrix(int argc, char **argv);
void	free_matrix(char **matrix);
int		check_valid_cmd(t_cmd *cmd);

/* pipex utils */
char	**find_total_path(char **envp);

#endif
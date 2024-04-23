/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:29:19 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 16:12:08 by crea             ###   ########.fr       */
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

typedef struct s_cmd
{
	char	**matrix;
	int		index;
	char	**total_path;
}			t_cmd;

/* pipex */
void	process_child(int *fd, t_cmd *cmd, char **envp, char *in_file);
void	process_parent(int *fd, t_cmd *cmd, char **envp, char *out_file);
void	exe_cmd(t_cmd *cmd, char *command, char **envp);
char	*find_cmd_path(t_cmd *cmd, char *command);

/* pipex utils */
int		check_matrix_format(char **matrix, int argc);
void	init_cmd(t_cmd *cmd, int argc, char **argv, char **envp);
char	**build_cmd_matrix(int argc, char **argv);
char	**find_total_path(char **envp);
void	free_matrix(char **matrix);

#endif
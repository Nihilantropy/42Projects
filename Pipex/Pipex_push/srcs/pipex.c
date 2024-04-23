/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:04:28 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 22:38:10 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	process_child(int *fd, t_cmd *cmd, char **envp, char *in_file)
{
	int	read_file;

	read_file = open(in_file, O_RDONLY, 0777);
	if (read_file == -1)
		ft_exit_error(ERROR_CHILD_OPEN);
	dup2(read_file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	exe_cmd(cmd, cmd->matrix[cmd->index], envp);
}

void	process_parent(int *fd, t_cmd *cmd, char **envp, char *out_file)
{
	int	write_file;

	write_file = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (write_file == -1)
		ft_exit_error(ERROR_PARENT_OPEN);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(write_file, STDOUT_FILENO);
	exe_cmd(cmd, cmd->matrix[cmd->index], envp);
}

void	exe_cmd(t_cmd *cmd, char *command, char **envp)
{
	char	*path;
	char	**raw_command;

	raw_command = ft_split(command, ' ');
	path = find_cmd_path(cmd, raw_command[0]);
	if (!path)
	{
		free_matrix(raw_command);
		return ;
	}
	if (execve(path, raw_command, envp) == -1)
	{
		ft_printf(ERROR_EXECVE);
		return ;
	}
}

char	*find_cmd_path(t_cmd *cmd, char *command)
{
	int		i;
	char	*relative_path;
	char	*cmd_path;

	i = 0;
	while (cmd->total_path[i])
	{
		relative_path = ft_strjoin(cmd->total_path[i], "/");
		cmd_path = ft_strjoin(relative_path, command);
		free(relative_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_matrix(cmd->total_path);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_matrix(cmd->total_path);
	return (NULL);
}

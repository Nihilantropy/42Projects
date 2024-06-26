/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:04:35 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 21:27:15 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_here_doc(t_cmd *cmd, char **argv, int argc, char **envp)
{
	int		here_doc;
	int		write_file;
	char	*line;

	line = get_next_line(STDIN_FILENO);
	here_doc = open("here_doc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (here_doc == -1)
		ft_exit_error(ERROR_OPEN_FILE);
	while (ft_strcmp(ft_strtrim(line, " \t\n\r\f\v"), argv[2]) != 0)
	{
		ft_putstr_fd(line, here_doc);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	dup2(here_doc, STDIN_FILENO);
	write_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0600);
	if (write_file == -1)
		ft_exit_error(ERROR_WRITE_FILE);
	while (cmd->index < cmd->pipes_nbr)
		process_child(cmd, cmd->matrix[cmd->index++], envp);
	wait(NULL);
	dup2(write_file, STDOUT_FILENO);
	process_parent(cmd, cmd->matrix[cmd->index], envp);
	return (0);
}

int	ft_pipex(t_cmd *cmd, char **argv, int argc, char **envp)
{
	int		read_file;
	int		write_file;

	read_file = open(argv[1], O_RDONLY, 0777);
	if (read_file == -1)
		ft_exit_error(ERROR_OPEN_FILE);
	dup2(read_file, STDIN_FILENO);
	write_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (write_file == -1)
		ft_exit_error(ERROR_WRITE_FILE);
	while (cmd->index < cmd->pipes_nbr)
		process_child(cmd, cmd->matrix[cmd->index++], envp);
	wait(NULL);
	dup2(write_file, STDOUT_FILENO);
	process_parent(cmd, cmd->matrix[cmd->index], envp);
	return (0);
}

char	**find_total_path(char **envp)
{
	// Dichiaro la path totale, ovvero tutto ciò che si trova dopo la
	// variabile PATH= nell'ambiente envp
	char	**total_path;
	int		i;

	i = 0;
	// Itero finchè non trovo la variabile PATH=
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	// Splitto i vari percorsi delle cartelle, che sono separati dai ':'
	// Es. /usr/bin:/usr/sbin:/ etc...
	total_path = ft_split(envp[i] + 5, ':');
	return (total_path);
}

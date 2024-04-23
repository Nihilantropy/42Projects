/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:04:28 by crea              #+#    #+#             */
/*   Updated: 2024/04/17 10:51:18 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	process_child(t_cmd *cmd, char *command, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_exit_error(PIPE_ERROR);
	pid = fork();
	if (pid == -1)
		ft_exit_error(FORK_ERROR);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exe_cmd(cmd, command, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

void	process_parent(t_cmd *cmd, char *command, char **envp)
{
	exe_cmd(cmd, command, envp);
}

void	exe_cmd(t_cmd *cmd, char *command, char **envp)
{
	// Dichiaro una variabile che mi servirà per cercare e trovare (se esiste)
	// il percorso completo del comando da eseguire. all'interno dell' envp.
	// Quindi cerco il comando 'x' all'indice 'y', tra le variabili d'ambiente
	char	*path;
	// Dichiaro una variabile per tenere traccia di eventuali flag.
	// La funzione deve cercare la path solo con il comando principale, non con le flag
	// Es. se ho "ls -la", la path deve essere costruita solo con 'ls'
	char	**raw_command;

	raw_command = ft_split(command, ' ');
	path = find_cmd_path(cmd, raw_command[0]);
	if (!path)
	{
		// Se non l'ho trovato, chiudo il programma
		free_matrix(raw_command);
		return ;
	}
	// Eseguo execve per far partire il comando specificato, ovvero il programma
	// con eventuali flag, all'interno dell'ambiente envp.
	// Es. se ho "ls -la", execve eseguirà il programma ls anche con la flag la.
	if (execve(path, raw_command, envp) == -1)
	{
		// Se execve fallisce 
		ft_printf(ERROR_EXECVE);
		return ;
	}
}

char	*find_cmd_path(t_cmd *cmd, char *command)
{
	int		i;
	// Dichiaro la path relativa per ogni cartella contenente i file binari
	char	*relative_path;
	// Dichiaro la path specifica del comando, se trovato.
	char	*cmd_path;

	i = 0;
	//ft_printf("cmd->total_path is: %s\n", cmd->total_path[i]);
	// Finchè non ho scorso tutto il PATH, diviso nei vari array
	while (cmd->total_path[i])
	{
		// Costruisco i percorsi relativi, aggiungendo il '/'
		// Es. /usr/bin/(aggiungo il '/' per continuare il percorso)
		relative_path = ft_strjoin(cmd->total_path[i], "/");
		// Unisco il percorso relativo al comando passato come parametro, in modo
		// da poter verificare se si trova all'interno della cartella
		// Es. /usr/bin/ls (aggiungo il comando preso dall'input)
		cmd_path = ft_strjoin(relative_path, command);
		// Libero immediatamente la memoria per il percorso relativo, avendo già
		// quello specifico del comando
		free(relative_path);
		// Se access, con la flag F_OK restituisce 0, il file binario è stato trovato;
		// ora possiamo restituire il percorso completo del comando
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
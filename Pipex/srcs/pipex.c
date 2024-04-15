/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:04:28 by crea              #+#    #+#             */
/*   Updated: 2024/04/15 17:23:15 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	process_child(int *fd, t_cmd *cmd, char **envp, char *in_file)
{
	// creo un file che avrà il valore del file descriptor passato
	// come input nel programma
	int	read_file;

	read_file = open(in_file, O_RDONLY, 0777);
	if (read_file == -1)
		ft_exit_error(ERROR_CHILD_OPEN);
	// Chiudo immediatamente il file descriptor a indice 0 creato con la funzione pipe.
	// Essendo il file dedicato alla lettura, in questa iterazione non serve.
	close(fd[0]);
	// Redireziono lo STDIN (0) verso il file descriptor passato come argomento;
	// in questo modo il programma prenderà l'input dal file passato dall'utente.
	// dup2 chiude il file STDIN_FILENO
	dup2(read_file, STDIN_FILENO);
	// Redireziono lo STDOUT (1) verso il file descriptor creato con la funzione pipe;
	// in questo modo il programma non stamperà sul terminale ma scriverà su quel 'file'
	// in modo da poterlo usare come input del prossimo processo
	// dup2 chiude il file STDOUT_FILENO
	dup2(fd[1], STDOUT_FILENO);
	exe_cmd(cmd, cmd->matrix[cmd->index], envp);
}

void	process_parent(int *fd, t_cmd *cmd, char **envp, char *out_file)
{
	// Dichiaro un file descriptor che diventerà il file di output dei vari comandi.
	// Avrà il nome del file passato come ultimo argomento dall'utente
	int	write_file;

	write_file = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (write_file == -1)
		ft_exit_error(ERROR_PARENT_OPEN);
	// Chiudo immediatamente il file descriptor di creato con la funzione pipe,
	// dedicato alla scrittura. Non serve più proprio perchè ora evo andare a scrivere
	// sul nuovo file apppena creato con la funzione open
	close(fd[1]);
	// Redireziono lo standard input in modo che legga dal file descriptor dedicato 
	// alla lettura creato con la funzione pipe.  
	// dup2 chiude il file STDIN_FILENO
	dup2(fd[0], STDIN_FILENO);
	// Redireziono lo standard output in modo che scriva sul file appena creato
	// con la funzione open.
	// dup2 chiude il file STDOUT_FILENO
	dup2(write_file, STDOUT_FILENO);
	// Eseguo il comando del processo figlio, ovvero il primo nella matrice
	exe_cmd(cmd, cmd->matrix[cmd->index], envp);
}

void	exe_cmd(t_cmd *cmd, char *command, char **envp)
{
	// Dichiaro una variabile che mi servirà per cercare e trovare (se esiste)
	// il percorso completo del comando da eseguire. all'interno dell' envp.
	// Quindi cerco il comando 'x' all'indice 'y', tra le variabili d'ambiente
	char	*path;
	// Dichiaro una variabile per tenere traccia di eventuali flag.
	// La funzione deve cercare la path solo con il comando principale, non con le flag
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
	// con eventuali flag, all'interno dell'ambiente envp
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
		relative_path = ft_strjoin(cmd->total_path[i], "/");
		// Unisco il percorso relativo al comando passato come parametro, in modo
		// da poter verificare se si trova all'interno della cartella
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:34:23 by crea              #+#    #+#             */
/*   Updated: 2024/04/17 15:56:43 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{	
	// Dichiaro i due file descriptor che serviranno per ridirezionare lo
	// STDIN e lo STDOUT sui nuovi 'file' con l'output dei comandi
	int		fd[2];
	// Dichiaro la vairabile del process id
	pid_t	pid;
	// Dichiaro una struttura cmd per tenere traccia dei comandi eseguiti
	// Costruendo una matrice che contenga SOLO i comandi passati in input
	t_cmd	cmd;
	
	init_cmd(&cmd, argc, argv, envp);
	// La funzione pipe crea i due fd collegati tra loro, in questo caso hanno
	// valore 3 e 4 (0 è STDIN, 1 è STDOUT, 2 è STDERROR)
	if (argc < 5)
		ft_exit_error(ERROR_ARG_NBR);
	if (pipe(fd) == -1)
		ft_exit_error(PIPE_ERROR);
	// La funzione fork sdoppia il processo chiamante, ritornando il valore
	// del processo figlio (ovvero 0)
	pid = fork();
	if (pid == -1)
		ft_exit_error(FORK_ERROR);
	// Se il pid è 0 (ovvero il processo figlio) eseguo la parte del programma
	// dedicata al processo figlio
	if (pid == 0)
	{
		process_child(fd, &cmd, envp, argv[1]);
		return (0);
	}
	// Aspetto che il processo figlio abbia finito prima di proseguire
	waitpid(pid, NULL, 0);
	cmd.index++;
	process_parent(fd, &cmd, envp, argv[argc - 1]);
	return (0);
}
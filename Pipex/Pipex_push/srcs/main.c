/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:34:23 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 22:03:24 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	t_cmd	cmd;

	if (!check_matrix_format(argv, argc))
		ft_exit_error(ERROR_MATRIX_EMPTY);
	init_cmd(&cmd, argc, argv, envp);
	if (argc < 5)
		ft_exit_error(ERROR_ARG_NBR);
	if (pipe(fd) == -1)
		ft_exit_error(PIPE_ERROR);
	pid = fork();
	if (pid == -1)
		ft_exit_error(FORK_ERROR);
	if (pid == 0)
	{
		process_child(fd, &cmd, envp, argv[1]);
		return (0);
	}
	waitpid(pid, NULL, 0);
	cmd.index++;
	process_parent(fd, &cmd, envp, argv[argc - 1]);
	return (0);
}

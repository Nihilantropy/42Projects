/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:34:23 by crea              #+#    #+#             */
/*   Updated: 2024/04/17 16:21:22 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		read_file;
	int		write_file;
	t_cmd	cmd;

	init_cmd(&cmd, argc, argv, envp);
	if (argc <= 4)
		ft_exit_error(ERROR_ARG_NBR);
	// if (!check_valid_cmd(&cmd))
	// 	ft_exit_error(ERROR_ARG_SYNTAX);
	read_file = open(argv[1], O_RDONLY, 0777);
	if (read_file == -1)
		ft_exit_error("Error on read file opening.\n");
	dup2(read_file, STDIN_FILENO);
	write_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (write_file == - 1)
		ft_exit_error("Error on write file creation.\n");
	while (cmd.index < cmd.pipes_nbr)
		process_child(&cmd, cmd.matrix[cmd.index++], envp);
	wait(NULL);
	dup2(write_file, STDOUT_FILENO);
	process_parent(&cmd, cmd.matrix[cmd.index], envp);
}
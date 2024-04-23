/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:34:23 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 22:12:08 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;

	if (!check_matrix_format(argv, argc))
		ft_exit_error(ERROR_MATRIX_EMPTY);
	if (argc <= 4)
		ft_exit_error(ERROR_ARG_NBR);
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		cmd.here_doc = true;
		init_cmd(&cmd, argc, argv, envp);
		ft_here_doc(&cmd, argv, argc, envp);
		return (0);
	}
	else
	{
		cmd.here_doc = false;
		init_cmd(&cmd, argc, argv, envp);
		ft_pipex(&cmd, argv, argc, envp);
		return (0);
	}
}

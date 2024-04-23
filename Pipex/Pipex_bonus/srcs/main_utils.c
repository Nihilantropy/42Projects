/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:57:29 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 19:26:28 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	check_matrix_format(char **matrix, int argc)
{
	int	y;

	y = 0;
	while (y < argc)
	{
		if (!matrix[y][0])
			return (0);
		y++;
	}
	return (1);
}

void	init_cmd(t_cmd *cmd, int argc, char **argv, char **envp)
{
	if (cmd->here_doc == true)
	{
		cmd->matrix = build_cmd_matrix((argc - 4), (argv + 3));
		cmd->pipes_nbr = argc - 5;
	}
	else
	{
		cmd->matrix = build_cmd_matrix((argc - 3), (argv + 2));
		cmd->pipes_nbr = argc - 4;
	}
	cmd->index = 0; // Inizializzo l'index dei comandi
	cmd->total_path = find_total_path(envp); // Trovo la PATH generale
}

char	**build_cmd_matrix(int argc, char **argv)
{
	char	**matrix;
	int		i;

	matrix = malloc(sizeof(char *) * (argc + 1));
	if (!matrix)
		ft_exit_error(ERROR_MATRIX_ALLOC);
	i = 0;
	while (i < (argc))
	{
		matrix[i] = argv[i];
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	free_matrix(char **matrix)
{
	int	y;

	if (!matrix)
		return ;
	y = 0;
	while (matrix[y])
		free(matrix[y++]);
	free(matrix);
}

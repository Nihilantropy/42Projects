/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:57:29 by crea              #+#    #+#             */
/*   Updated: 2024/04/17 16:20:36 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_cmd(t_cmd *cmd, int argc, char **argv, char **envp)
{
	cmd->matrix = build_cmd_matrix((argc - 3), (argv + 2)); // Costruisco la matrice dei comandi
	cmd->pipes_nbr = argc - 4; // Trovo il numero delle pipe necessarie
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

int	check_valid_cmd(t_cmd *cmd)
{
	int	y;

	y = 0;
	while (cmd->matrix[y])
	{
		if (cmd->matrix[y][0] == '\0')
			return (0);
		y++;
	}
	return (1);
}

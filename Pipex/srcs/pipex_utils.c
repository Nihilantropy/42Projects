/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:04:35 by crea              #+#    #+#             */
/*   Updated: 2024/04/15 16:37:46 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_cmd(t_cmd *cmd, int argc, char **argv, char **envp)
{
	cmd->matrix = build_cmd_matrix((argc - 3), (argv + 2));
	cmd->index = 0;
	cmd->total_path = find_total_path(envp);
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
	total_path = ft_split(envp[i] + 5, ':');
	return (total_path);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:17:36 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 12:28:53 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**build_matrix(int argc, char **argv)
{
	char	**matrix;
	int		i;

	matrix = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < argc)
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
	{
		free(matrix[y]);
		matrix[y] = NULL;
		y++;
	}
	free(matrix);
	matrix = NULL;
}

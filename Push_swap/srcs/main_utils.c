/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:17:36 by crea              #+#    #+#             */
/*   Updated: 2024/03/25 19:02:37 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**build_matrix(int argc, char **argv)
{
	char	**matrix;
	int		i;

	matrix = (char **)malloc(sizeof(char *) * argc);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		matrix[i] = argv[i];
		i++;
	}
	matrix[argc] = NULL;
	return (matrix); 
}

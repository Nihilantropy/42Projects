/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:17:39 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 13:07:19 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**matrix;
	t_stack	*a;
	t_stack	*b;

	matrix = NULL;
	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		matrix = ft_split(argv[1], ' ');
	else
		matrix = build_matrix(argc - 1, (argv + 1));
	if (!matrix[0])
		return (0);
	init_stack(&a, matrix);
	choose_sort(&a, &b);
	free_stack(&a);
	if (argc == 2)
		free_matrix(matrix);
	else
		free(matrix);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:17:39 by crea              #+#    #+#             */
/*   Updated: 2024/03/23 18:04:55 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	test(t_stack **a, t_stack **b);

int	main(int argc, char **argv)
{
	char	**matrix;
	t_stack	*a;
	t_stack	*b;

	matrix = NULL;
	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		ft_exit_error(ERROR_ARG_NBR);
	else if (argc == 2)
		matrix = ft_split(argv[1], ' ');
	else
		matrix = build_matrix(argc, (argv + 1));
	init_stack(&a, matrix);
	test(&a, &b);
}

void	test(t_stack **a, t_stack **b)
{
	b = NULL;
	print_list(*a);
	rra(a, true);
	print_list(*a);
}
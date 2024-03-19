/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:50:03 by crea              #+#    #+#             */
/*   Updated: 2024/03/19 19:54:44 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	test(t_linked_list **a, t_linked_list **b);

int main(int argc, char **argv)
{
	t_linked_list *a;
	t_linked_list *b;

	a = NULL;
	b = NULL;
	char **matrix;

	matrix = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return(ft_printf(ERROR_ARG_NBR));
	else if (argc == 2)
		matrix = ft_split(argv[1], ' ');
	else if (argc > 2)
		matrix = build_matrix(argc, (argv + 1));
	if (!check_format(matrix))
	{
		free(matrix);
		return (ft_printf(ERROR_ARG_FORMAT));
	}
	init_stack(&a, matrix);
	test(&a, &b);
	free(matrix);
	free_stacks(a);
	free_stacks(b);
	return (0);
}

void test(t_linked_list **a, t_linked_list **b)
{
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pb(a, b);
	ft_printf("\npush 1:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pb(a, b);
	ft_printf("\npush 2:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pb(a, b);
	ft_printf("\npush 3:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pb(a, b);
	ft_printf("\npush 4:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pb(a, b);
	ft_printf("\npush 5:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pb(a, b);
	ft_printf("\npush 6:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pb(a, b);
	ft_printf("\npush 7:\n");
	print_list(a);

	ft_printf("\n");
	print_list(b);
	pa(a, b);
	ft_printf("\npush 1:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pa(a, b);
	ft_printf("\npush 2:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pa(a, b);
	ft_printf("\npush 3:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pa(a, b);
	ft_printf("\npush 4:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pa(a, b);
	ft_printf("\npush 5:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pa(a, b);
	ft_printf("\npush 6:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	pa(a, b);
	ft_printf("\npush 7:\n");
	print_list(a);
	ft_printf("\n");
	print_list(b);
	
}
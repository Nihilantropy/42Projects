/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:33:26 by crea              #+#    #+#             */
/*   Updated: 2024/03/25 19:11:38 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack **a, char **matrix)
{
	long	nbr;

	if (!check_format(matrix))
		ft_exit_error(ERROR_ARG_FORMAT);
	while (*matrix)
	{
		nbr	= ft_atol(*matrix);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_exit_error(ERROR_INPUT_OVERFLOW);
		if (!check_double(*a, (int)nbr))
			create_node(a, (int)nbr);
		matrix++;
	}
}

void	create_node(t_stack **stack, int nbr)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		ft_exit_error(ERROR_NEW_NODE_ALLOC);
	new_node->data = nbr;
	new_node->next = NULL;
	if (!(*stack))
	{
		new_node->prev = new_node;
		*stack = new_node;
	}
	else
	{
		last_node = (*stack)->prev;
		last_node->next = new_node;
		new_node->prev = last_node;
		(*stack)->prev = new_node;
	}
}
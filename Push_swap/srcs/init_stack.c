/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:50:10 by crea              #+#    #+#             */
/*   Updated: 2024/03/21 13:54:05 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_node(t_linked_list **a, int nbr)
{
	t_linked_list	*new_node;
	t_linked_list	*last_node;

	new_node = malloc(sizeof(t_linked_list));
	if (!new_node)
		ft_print_error(ERROR_NEW_NODE_ALLOC);
	new_node->data = nbr;
	new_node->cheapest = NULL;
	if (!*a)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*a = new_node;
	}
	else
	{
		last_node = (*a)->prev;
		new_node->next = *a;
		new_node->prev = last_node;
		last_node->next = new_node;
		(*a)->prev = new_node;
	}
}

void	init_stack(t_linked_list **a, char **matrix)
{
	long	nbr;

	if (!check_format(matrix))
			ft_print_error(ERROR_ARG_FORMAT);
	while (*matrix)
	{
		nbr = ft_atol(*matrix);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_print_error(ERROR_INPUT_OVERFLOW);
		if (!check_double(*a, (int)nbr))
			create_node(a, (int)nbr);
		matrix++;
	}
}

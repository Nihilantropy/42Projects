/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:50:10 by crea              #+#    #+#             */
/*   Updated: 2024/03/19 19:37:55 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int	check_double(t_linked_list *a, int nbr)
{
	t_linked_list	*current;
	
	current = a;
	if (!a)
		return (0);
	while (1)
	{
		if (current->data == nbr)
			exit (ft_printf(ERROR_DOUBLE_NBR));
		current = current->next;
		if (current == a)
			break ;
	}
	return (0);
}

void	push(t_linked_list **a, int nbr)
{
	t_linked_list	*new_node;
	t_linked_list	*last_node;

	new_node = malloc(sizeof(t_linked_list));
	if (!new_node)
		exit(1);
	new_node->data = nbr;
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

	while (*matrix)
	{
		nbr = ft_atol(*matrix);
		if (nbr > INT_MAX || nbr < INT_MIN)
			exit(1);
		if (!check_double(*a, (int)nbr))
			push(a, (int)nbr);
		matrix++;
	}
}

void	free_stacks(t_linked_list *a)
{
	if (!a)
		return;

	t_linked_list	*current;
	t_linked_list	*next_node;

	current = a;
	while (1)
	{
		next_node = current->next;
		free(current);
		if (next_node == a)
			break ;
		current = next_node;
	}
}

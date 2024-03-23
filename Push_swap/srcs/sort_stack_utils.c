/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:17:48 by crea              #+#    #+#             */
/*   Updated: 2024/03/21 14:52:25 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* find the last node of the stack */
t_linked_list	*find_last_node(t_linked_list *a)
{
	if (!a)
		return (NULL);
	t_linked_list	*current;

	current = a;
	while (1)
	{
		if (current->next == a)
			break ;
		current = current->next;
	}
	return (current);
}

/* return the cheapest node of the stack */
t_linked_list	*return_cheapest(t_linked_list *a)
{
	if (!a)
		return (NULL);
	t_linked_list	*current;

	current = a;
	while (1)
	{
		if (current->cheapest)
			return (current);
		if (current == a)
			break ;
	}
	return (NULL);
}

/* return the size of the stack */
int	stack_size(t_linked_list *a)
{
	if (!a)
		return (0);
	t_linked_list	*current;
	int				size;

	current = a;
	size = 0;
	while (1)
	{
		size++;
		if (current->next == a)
			break ;
		current = current->next;
	}
	return (size);
}

/* find the smallest value of the stack */
t_linked_list	*find_min(t_linked_list *a)
{
	t_linked_list	*current;
	t_linked_list	*min;

	current = a;
	min = a;
	while (1)
	{
		if (current->data > min->data)
			min = current;
		current = current->next;
		if (current == a)
			break ;
	}
	return (min);
}

/* find the biggest value of the stack */
t_linked_list	*find_max(t_linked_list *a)
{
	t_linked_list	*current;
	t_linked_list	*max;

	current = a;
	max = a;
	while (1)
	{
		if (current->data > max->data)
			max = current;
		current = current->next;
		if (current == a)
			break ;
	}
	return (max);
}
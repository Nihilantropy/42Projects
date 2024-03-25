/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:38:06 by crea              #+#    #+#             */
/*   Updated: 2024/03/22 14:18:02 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_double(t_linked_list *a, int nbr)
{
	t_linked_list	*current;
	
	current = a;
	if (!a)
		return (0);
	while (1)
	{
		if (current->data == nbr)
			ft_print_error(ERROR_DOUBLE_NBR);
		current = current->next;
		if (current == a)
			break ;
	}
	return (0);
}

bool	check_if_sorted(t_linked_list *a)
{
	t_linked_list *current;

	current = a;
	while (1)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
		if (current == a)
			break ;
	}
	return (true);
}

void	free_stack(t_linked_list **head)
{
	if (!head)
		return;
	t_linked_list	*current;
	t_linked_list	*next_node;

	current = *head;
	while (1)
	{
		next_node = current->next;
		free(current);
		if (next_node == *head)
			break ;
		current = next_node;
	}
}
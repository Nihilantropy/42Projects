/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:47:43 by crea              #+#    #+#             */
/*   Updated: 2024/04/12 17:54:46 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	free_stack(t_stack **head)
{
	t_stack	*current;
	t_stack	*next_node;

	if (!head || !*head)
		return ;
	current = *head;
	next_node = NULL;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*head = NULL;
}

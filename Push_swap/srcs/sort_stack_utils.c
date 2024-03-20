/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:17:48 by crea              #+#    #+#             */
/*   Updated: 2024/03/20 15:50:42 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int	stack_size(t_linked_list **a)
{
	if (!(*a))
		return (0);
	t_linked_list	*current;
	int				size;

	current = *a;
	size = 0;
	while (1)
	{
		size++;
		if (current->next == *a)
			break ;
		current = current->next;
	}
	return (size);
}
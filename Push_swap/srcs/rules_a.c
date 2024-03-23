/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:37:24 by crea              #+#    #+#             */
/*   Updated: 2024/03/21 14:33:54 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_linked_list **a)
{
	t_linked_list	*first;
	t_linked_list	*second;

	if (!(*a) || !(*a)->next || *a == (*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->prev = second;
	second->prev = first->prev;
	second->next = first;
	first->next->prev = first;
	second->prev->next = second;
	*a = second;
}

void pa(t_linked_list **a, t_linked_list **b)
{
    t_linked_list *top_b;

	top_b = *b;
	if (*b == (*b)->next)
		*b = NULL;
	else
	{
		*b = (*b)->next;
		(*b)->prev = top_b->prev;
		top_b->prev->next = *b;
	}
	if (*a)
	{
		top_b->next = *a;
		top_b->prev = (*a)->prev;
		(*a)->prev->next = top_b;
		(*a)->prev = top_b;
	}
	else
	{
		top_b->next = top_b;
		top_b->prev = top_b;
	}
	(*a) = top_b;
}

void	ra(t_linked_list **a)
{
	if (!(*a) || (*a)->next == *a)
		return ;
	*a = (*a)->next;
}

void	rra(t_linked_list **a)
{
	if (!(*a) || (*a)->next == *a)
		return ;
	*a = (*a)->prev;
}

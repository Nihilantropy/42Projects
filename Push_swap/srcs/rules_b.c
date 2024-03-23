/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:37:24 by crea              #+#    #+#             */
/*   Updated: 2024/03/21 14:34:41 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sb(t_linked_list **b)
{
	t_linked_list	*first;
	t_linked_list	*second;

	if (!(*b) || !(*b)->next || *b == (*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->prev = second;
	second->prev = first->prev;
	second->next = first;
	first->next->prev = first;
	second->prev->next = second;
	*b = second;
}

void pb(t_linked_list **a, t_linked_list **b)
{
    t_linked_list *top_a;

	top_a = *a;
	if (*a == (*a)->next)
		*a = NULL;
	else
	{
		*a = (*a)->next;
		(*a)->prev = top_a->prev;
		top_a->prev->next = *a;
	}
	if (*b)
	{
		top_a->next = *b;
		top_a->prev = (*b)->prev;
		(*b)->prev->next = top_a;
		(*b)->prev = top_a;
	}
	else
	{
		top_a->next = top_a;
		top_a->prev = top_a;
	}
	(*b) = top_a;
}

void	rb(t_linked_list **b)
{
	if (!(*b) || (*b)->next == *b)
		return ;
	*b = (*b)->next;
}

void	rrb(t_linked_list **b)
{
	if (!(*b) || (*b)->next == *b)
		return ;
	*b = (*b)->prev;
}

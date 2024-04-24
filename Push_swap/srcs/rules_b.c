/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:29:48 by crea              #+#    #+#             */
/*   Updated: 2024/04/12 17:51:25 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sb(t_stack	**b, bool write)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	if (second->next)
		second->prev = first->prev;
	else
		second->prev = first;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	*b = second;
	if (write)
		ft_putstr("sb\n");
}

void	pb(t_stack **a, t_stack **b, bool write)
{
	t_stack	*new_head;

	if (!(*a))
		return ;
	new_head = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = new_head->prev;
	if (*b)
	{
		new_head->prev = (*b)->prev;
		new_head->next = (*b);
		(*b)->prev = new_head;
	}
	else if (!(*b))
	{
		new_head->next = NULL;
		new_head->prev = new_head;
	}
	*b = new_head;
	if (write)
		ft_putstr("pb\n");
}

void	rb(t_stack **b, bool write)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	last = first->prev;
	*b = first->next;
	(*b)->prev = first;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (write)
		ft_putstr("rb\n");
}

void	rrb(t_stack **b, bool write)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	last = first->prev;
	*b = last;
	(*b)->next = first;
	last->prev->next = NULL;
	if (write)
		ft_putstr("rrb\n");
}

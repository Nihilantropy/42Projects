/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:14:55 by crea              #+#    #+#             */
/*   Updated: 2024/04/17 12:45:20 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_2(t_stack **stack);

static void	rotate_up(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = first->prev;
	*stack = first->next;
	(*stack)->prev = first;
	last->next = first;
	first->prev = last;
	last->next->next = NULL;
}

static void	rev_rotate_down(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = first->prev;
	*stack = last;
	(*stack)->next = first;
	last->prev->next = NULL;
}

void	rr(t_stack **a, t_stack **b, bool write)
{
	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	rotate_up(a);
	rotate_up(b);
	if (write)
		ft_putstr("rr\n");
}

void	rrr(t_stack **a, t_stack **b, bool write)
{
	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	rev_rotate_down(a);
	rev_rotate_down(b);
	if (write)
		ft_putstr("rrr\n");
}

void	ss(t_stack **a, t_stack **b, bool write)
{
	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	swap_2(a);
	swap_2(b);
	if (write)
		ft_putstr("ss\n");
}

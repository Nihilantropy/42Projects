/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:26:36 by crea              #+#    #+#             */
/*   Updated: 2024/03/27 13:40:19 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest_node;

	if (!stack)
		return (NULL);
	cheapest_node = stack;
	while (stack)
	{
		if (stack->isCheapest)
			cheapest_node = stack;
		stack = stack->next;
	}
	return (cheapest_node);
}

void	rotate_ab(t_stack **a,
					t_stack **b,
					t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, true);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_ab(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, true);
	current_index(*a);
	current_index(*b);
}

void	min_on_top(t_stack **a)
{
	t_stack	*min_node;

	min_node = find_min(*a);
	while ((*a)->data != min_node->data)
	{
		if (min_node->isAboveMedian)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	prep_for_push(t_stack **stack,
						t_stack *cheapest_node,
						char stack_name)
{
	while (*stack != cheapest_node)
	{
		if (stack_name == 'a')
		{
			if (cheapest_node->isAboveMedian)
				ra(stack, true);
			else if (!(cheapest_node->isAboveMedian))
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (cheapest_node->isAboveMedian)
				rb(stack, true);
			else if (!(cheapest_node->isAboveMedian))
				rrb(stack, true);
		}
	}
}
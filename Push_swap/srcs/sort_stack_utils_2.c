/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:14:01 by crea              #+#    #+#             */
/*   Updated: 2024/04/17 12:42:34 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest_node;
	int		cheapest;

	if (!stack)
		return ;
	cheapest = INT_MAX;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->push_cost == 1)
		{
			stack->is_cheapest = true;
			return ;
		}
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = true;
}

void	current_index(t_stack *stack)
{
	int	median;
	int	index;

	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	index = 0;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->is_above_median = true;
		else
			stack->is_above_median = false;
		stack = stack->next;
		index++;
	}
}

void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (!cheapest_node)
		return ;
	if (cheapest_node->is_above_median
		&& cheapest_node->target_node->is_above_median)
		rotate_ab(a, b, cheapest_node);
	else if (!(cheapest_node->is_above_median
			&& !(cheapest_node->target_node->is_above_median)))
		rev_rotate_ab(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b, true);
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

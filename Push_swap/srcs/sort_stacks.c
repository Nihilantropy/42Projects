/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:21:12 by crea              #+#    #+#             */
/*   Updated: 2024/04/12 17:51:12 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	choose_sort(t_stack **a, t_stack **b)
{
	if (!check_if_sorted(*a))
	{
		if (stack_size(*a) == 2)
		{
			sa(a, true);
			ft_exit_success(STACK_SORTED);
		}
		else if (stack_size(*a) == 3)
			tiny_sort(a);
		else
			sort_stacks(a, b);
	}
	else
		ft_exit_success(INPUT_STACK_SORTED);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stack_size(*a);
	if (size_a-- > 3 && !check_if_sorted(*a))
		pb(a, b, true);
	if (size_a-- > 3 && !check_if_sorted(*a))
		pb(a, b, true);
	while (size_a-- > 3 && !check_if_sorted(*a))
	{
		init_stack_a(*a, *b);
		push_a_to_b(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		init_stack_b(*a, *b);
		push_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	init_stack_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	find_target_cost(a, b);
	set_cheapest_node(a);
}

void	init_stack_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

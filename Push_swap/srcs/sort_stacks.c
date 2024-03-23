/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:10:31 by crea              #+#    #+#             */
/*   Updated: 2024/03/21 18:39:13 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	move_a_to_b(t_linked_list **a, t_linked_list **b)
{
	t_linked_list	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

static void	move_b_to_a(t_linked_list **a, t_linked_list **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void	min_on_top(t_linked_list **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_linked_list **a, t_linked_list **b)
{
	int				size_a;
	t_linked_list	*current_b;

	size_a = stack_size(*a);
	if(size_a-- > 3 && !check_if_sorted(*a))
		pb(a, b);
	if(size_a-- > 3 && !check_if_sorted(*a))
		pb(a, b);
	while (size_a-- > 3 && !check_if_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	tiny_sort(a, b);
	while (1)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
		if (current_b = *b)
			break ;
		current_b = current_b->next;
	}
	current_index(*a);
	min_on_top(a);
}
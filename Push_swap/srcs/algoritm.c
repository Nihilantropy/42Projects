/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:40:13 by crea              #+#    #+#             */
/*   Updated: 2024/03/21 18:40:14 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	current_index(t_linked_list *a)
{
	t_linked_list *current;
	int	i;
	int	median;

	current = a;
	i = 0;
	if (!a)
		return ;
	median = stack_size(a) / 2;
	while (1)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		if (current->next == a)
			break ;
		current = current->next;
		i++;
	}
}

static void	set_target_a(t_linked_list *a, t_linked_list *b)
{
	t_linked_list	*current_b;
	t_linked_list	*current_a;
	t_linked_list	*target_node;
	long			best_match_index;

	current_a = a;
	while (1)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (1)
		{
			if (current_b->data < a->data
				&& current_b->data > best_match_index)
			{
				best_match_index = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
			if (current_b == b)
				break ;
		}
		if (best_match_index == LONG_MIN)
			current_a->target_node = find_max(b);
		else
			current_a->target_node = target_node;
		current_a = current_a->next;
		if (current_a == a)
			break ;
	}
}

static void	cost_analysis_a(t_linked_list *a, t_linked_list *b)
{
	t_linked_list	*current;
	int				size_a;
	int				size_b;

	current = a;
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (1)
	{
		current->push_cost = current->index;
		if (!(current->above_median))
			current->push_cost = size_a - (current->index);
		if (current->target_node->above_median)
			current->push_cost += current->target_node->index;
		else
			current->push_cost += size_b - (current->target_node->index);
		current = current->next;
		if (current == a)
			break ;
	}
}

void	set_cheapest(t_linked_list *a)
{
	t_linked_list	*current;
	t_linked_list	*cheapest_node;
	long			cheapest_value;

	cheapest_value = LONG_MAX;
	while (1)
	{
		if (current->push_cost < cheapest_value)
		{
			cheapest_value = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
		if (current == a)
			break ;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_linked_list *a, t_linked_list *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
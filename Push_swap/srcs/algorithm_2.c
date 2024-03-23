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

static void	set_target_b(t_linked_list *a, t_linked_list *b)
{
	t_linked_list	*current_b;
	t_linked_list	*current_a;
	t_linked_list	*target_node;
	long			best_match_index;

	current_b = b;
	while (1)
	{
		best_match_index = LONG_MIN;
		current_a = a;
		while (1)
		{
			if (current_a->data > b->data
				&& current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
			if (current_a == a)
				break ;
		}
		if (best_match_index == LONG_MIN)
			current_b->target_node = find_min(a);
		else
			current_b->target_node = target_node;
		current_b = current_b->next;
		if (current_b == b)
			break ;
	}
}

void	init_nodes_b(t_linked_list *a, t_linked_list *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
#include "../include/push_swap.h"

void	sa(t_stack	**a, bool write)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	if (second->next)
		second->prev = first->prev;
	else
		second->prev = first;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	*a = second;
	if (write)
		ft_putstr("sa\n");
}

void	pa(t_stack **a, t_stack **b, bool write)
{
	t_stack	*new_head;

	if (!(*b))
		return ;
	new_head = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = new_head->prev;
	if (*a)
	{
		new_head->prev = (*a)->prev;
		new_head->next = *a;
		(*a)->prev = new_head;		
	}
	else if (!(*a))
	{
		new_head->next = NULL;
		new_head->prev = new_head;
	}
	*a = new_head;
	if (write)
		ft_putstr("pa\n");
}

void	ra(t_stack **a, bool write)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	last = first->prev;
	*a = first->next;
	(*a)->prev = first;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (write)
		ft_putstr("ra\n");
}

void	rra(t_stack **a, bool write)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	last = first->prev;
	*a = last;
	(*a)->next = first;
	last->prev->next = NULL;
	if (write)
		ft_putstr("rra\n");
}

void	swap_2(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	if (second->next)
		second->prev = first->prev;
	else
		second->prev = first;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	*stack = second;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:57:47 by crea              #+#    #+#             */
/*   Updated: 2024/03/27 13:21:30 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_list(t_stack *stack)
{
	if (!stack)
	{
		ft_printf("(null)\n");
		return ;
	}
	while (stack)
	{
		ft_printf("{%d}\n", stack->data);
		stack = stack->next;
	}
	ft_putnl();
}

void	print_nodes_addr(t_stack *stack)
{
	if (!stack)
	{
		ft_printf(0x0);
		return ;
	}
	while (stack)
	{
		ft_printf("node address {%d} is: %p\n", stack->index, stack);
		stack = stack->next;
	}
}

void	print_target_node(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("node {%d} target node value is: {%d}\n", stack->index, stack->target_node->data);
		stack = stack->next;
	}
	return ;
}

void	print_push_cost(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("node {%d} with data value {%d} push cost is: {%d}\n", stack->index, stack->data, stack->push_cost);
		stack = stack->next;
	}
}

void	print_node_median(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("node {%d} with data value {%d} isAboveMedian is: {%d}\n", stack->index, stack->data, stack->isAboveMedian);
		stack = stack->next;
	}
}
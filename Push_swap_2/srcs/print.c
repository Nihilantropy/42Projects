/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:49:38 by crea              #+#    #+#             */
/*   Updated: 2024/03/23 17:04:58 by crea             ###   ########.fr       */
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
		ft_printf("%d ", stack->data);
		stack = stack->next;
	}
	ft_putnl();
}
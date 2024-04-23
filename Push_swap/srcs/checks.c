/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:52:10 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 13:07:50 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_format(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y])
	{
		if (!ft_isdigit_str(matrix[y]))
			return (0);
		y++;
	}
	return (1);
}

int	check_double(t_stack *stack, int nbr)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->data == nbr)
			ft_exit_error(ERROR_DOUBLE_NBR);
		stack = stack->next;
	}
	return (0);
}

bool	check_if_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (true);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

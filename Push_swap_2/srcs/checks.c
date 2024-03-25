/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:52:10 by crea              #+#    #+#             */
/*   Updated: 2024/03/23 12:27:11 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_format(char **matrix)
{
	int y;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:14:51 by crea              #+#    #+#             */
/*   Updated: 2024/03/27 11:57:44 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_max(*a);
	if (*a == biggest)
		ra(a, true);
	else if ((*a)->next == biggest)
		rra(a, true);
	if ((*a)->data > (*a)->next->data)
		sa(a, true);
}
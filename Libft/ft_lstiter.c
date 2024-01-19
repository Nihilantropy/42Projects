/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:49:22 by crea              #+#    #+#             */
/*   Updated: 2024/01/19 20:17:14 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *)) 
{
	if (lst == NULL || f == NULL)
		return;

	t_list	*current = lst;

	while (current != NULL)
	{
		f(current -> content);
		current = current -> next;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:45:24 by crea              #+#    #+#             */
/*   Updated: 2024/01/19 19:47:21 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *)) {
	if (lst == NULL || del == NULL)
		return;

	t_list	*current = *lst;
	t_list	*next;

	while (current != NULL) 
	{
		next = current -> next;
		del(current -> content);
		free(current);
		current = next;
	}

	*lst = NULL;
}

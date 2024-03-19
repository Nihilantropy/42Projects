/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:37:24 by crea              #+#    #+#             */
/*   Updated: 2024/03/19 19:44:21 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	sb(t_linked_list **b)
{
	t_linked_list	*first;
	t_linked_list	*second;

	if (!(*b) || !(*b)->next || *b == (*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = first->prev;
	second->next = first;
	first->next->prev = first;
	second->prev->next = second;

	*b = second;
}

void	pb(t_linked_list **a, t_linked_list **b)
{
    t_linked_list *top_a;

    if (!(*a)) // Se A è vuoto o ha un solo elemento.
        return ;

     // Isoliamo il top di A.
    top_a = *a;

    if (*a == (*a)->next) { // Se A ha un solo elemento, dopo la rimozione diventerà vuoto.
        *a = NULL;
    } else {
        // Collega il secondo nodo di A a diventare il primo.
        *a = (*a)->next;
        (*a)->prev = top_a->prev;
        top_a->prev->next = *a;
    }

    if (*b)
	{
        // Inseriamo top_b in B.
        top_a->next = *b;
        top_a->prev = (*b)->prev;
        (*b)->prev->next = top_a;
        (*b)->prev = top_a;
    } else {
        // Se B è vuoto, top_a diventa l'unico elemento.
        top_a->next = top_a;
        top_a->prev = top_a;
    }
    
    *b = top_a; // Aggiorniamo la testa di B con il nuovo elemento.
}
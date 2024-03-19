/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:37:24 by crea              #+#    #+#             */
/*   Updated: 2024/03/19 19:51:12 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	sa(t_linked_list **a)
{
	t_linked_list	*first;
	t_linked_list	*second;

	if (!(*a) || !(*a)->next || *a == (*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = first->prev;
	second->next = first;
	first->next->prev = first;
	second->prev->next = second;

	*a = second;
}

void pa(t_linked_list **a, t_linked_list **b)
{
    t_linked_list *top_b;

    if (!*b) // Se B è vuoto, non fare nulla.
        return;

    // Isoliamo il top di B.
    top_b = *b;

    if (*b == (*b)->next) { // Se B ha un solo elemento, dopo la rimozione diventerà vuoto.
        *b = NULL;
    } else {
        // Collega il secondo nodo di B a diventare il primo.
        *b = (*b)->next;
        (*b)->prev = top_b->prev;
        top_b->prev->next = *b;
    }

    // Se A non è vuoto, inseriamo top_b in A.
    if (*a) {
        top_b->next = *a;
        top_b->prev = (*a)->prev;
        (*a)->prev->next = top_b;
        (*a)->prev = top_b;
    } else {
        // Se A è vuoto, top_b diventa l'unico elemento di A.
        top_b->next = top_b;
        top_b->prev = top_b;
    }
    
    *a = top_b; // Aggiorna la testa di A con il nuovo elemento.
}

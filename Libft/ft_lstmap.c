/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:14:59 by crea              #+#    #+#             */
/*   Updated: 2024/01/19 20:25:09 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    if (lst == NULL || f == NULL)
        return (NULL);

    t_list  *newList = NULL;
    t_list  *current = lst;

    while (current != NULL)
    {
        void *newContent = f(current->content);

        if (newContent == NULL)
        {
            ft_lstclear(&newList, del);
            return (NULL);
        }

        t_list *newNode = ft_lstnew(newContent);

        if (newNode == NULL) 
        {
            ft_lstclear(&newList, del);
            return (NULL);
        }
        ft_lstadd_back(&newList, newNode);
        current = current -> next;
    }

    return newList;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:35:27 by crea              #+#    #+#             */
/*   Updated: 2024/02/10 02:35:28 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list  *find_last_node(t_list **list)
{
    t_list  *last_node;

    if (!*list)
        return (NULL);
    last_node = *list;
    while (last_node->next)
        last_node = last_node->next;
    return(last_node);

}
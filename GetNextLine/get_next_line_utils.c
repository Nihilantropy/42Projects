/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:05:41 by crea              #+#    #+#             */
/*   Updated: 2024/02/06 14:58:44 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     found_newline(t_list *list)
{
    int i;

    if (!list)
        return (0);
    while (list)
    {
        i = 0;
        while (list->str_buf[i] && i < BUFFER_SIZE)
        {
            if (list->str_buf[i] == '\n')
                return (1);
            i++;
        }
        list = list->next;
    }
    return (0);
}

t_list  *find_last_node(t_list *list)
{
    if (!list)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}

void    copy_str(t_list *list, char *str)
{
    int i;
    int j;

    if (!list)
        return ;
    j = 0;
    while (list)
    {
        i = 0;
        while (list->str_buf[i])
        {
            if (list->str_buf[i] == '\n')
            {
                str[j++] = '\n';
                str[j] = '\0';
                return ;
            }
            str[j++] = list->str_buf[i++];
        }
        list = list->next;
    }
    str[j] = '\0';
}

int len_to_newline(t_list *list)
{
    int i;
    int len;

    if (!list)
        return (0);
    len = 0;
    while (list)
    {
        i = 0;
        while (list->str_buf[i])
        {
            if (list->str_buf[i] == '\n')
            {
                len++;
                return (len);
            }
            i++;
            len++;
        }
        list = list->next;
    }
    return (len);
}

void    dealloc(t_list **list, t_list *new_node, char *buffer)
{
    t_list  *temp;

    if (!*list)
        return ;
    while (*list)
    {
        temp = (*list)->next;
        free((*list)->str_buf);
        free(*list);
        *list = temp;
    }
    *list = NULL;
    if (new_node->str_buf[0])
        *list = new_node;
    else
    {
        free(buffer);
        free(new_node);
    }
}
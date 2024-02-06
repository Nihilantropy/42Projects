/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:05:39 by crea              #+#    #+#             */
/*   Updated: 2024/02/06 14:54:04 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    polish_list(t_list **list)
{
    t_list  *last_node;
    t_list  *clean_node;
    int     i;
    int     j;
    char    *buffer;

    buffer = malloc(BUFFER_SIZE + 1);
    clean_node = malloc(sizeof(t_list));
    if (!(buffer || clean_node))
        return ;
    last_node = find_last_node(*list);
    i = 0;
    j = 0;
    while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
        i++;
    while (last_node->str_buf[i] && last_node->str_buf[i++])
        buffer[j++] = last_node->str_buf[i];
    buffer[j] = '\0';
    clean_node->str_buf = buffer;
    clean_node->next = NULL;
    dealloc(list, clean_node, buffer);
}

char    *get_line(t_list *list)
{
    int     str_len;
    char    *next_str;

    if (!list)
        return (NULL);
    str_len = len_to_newline(list);
    next_str = malloc(str_len + 1);
    if (!next_str)
        return (NULL);
    copy_str(list, next_str);
    return (next_str);
}

void    append(t_list **list, char *buffer)
{
    t_list  *new_node;
    t_list  *last_node;

    last_node = find_last_node(*list);
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    if (!last_node)
        *list = new_node;
    else
        last_node->next = new_node;
    new_node->str_buf = buffer;
    new_node->next = NULL;
}

void create_list(t_list **list, int fd)
{
    int     bytes_read;
    char    *buffer;

    while (!found_newline(*list))
    {
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return ;
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (!bytes_read)
        {
            free(buffer);
            return ;
        }
        buffer[bytes_read] = '\0';
        append(list, buffer);
    }
}

char    *get_next_line(int fd)
{
    static t_list   *list;
    char            *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
        return (NULL);
    create_list(&list, fd);
    if (!list)
        return (NULL);
    next_line = get_line(list);
    polish_list(&list);
    return(next_line);
}


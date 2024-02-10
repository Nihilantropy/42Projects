/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:35:30 by crea              #+#    #+#             */
/*   Updated: 2024/02/10 02:35:30 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    create_new_node(t_list **list, char *buffer)
{
    t_list  *new_node;
    t_list  *current_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    new_node->data = buffer;
    new_node->next = NULL;
    if (!*list)
        *list = new_node;
    else
    {
        current_node = find_last_node(*list);
        current_node = new_node;
    }   
}

void    create_buffer(t_list **list, int fd)
{
    ssize_t bytes_read;
    char *buffer;

    while (!(found_newline(*list)))
    {
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return ;
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            return ;
        }
        buffer[bytes_read] = '\0';
        create_new_node(list, buffer);
    }
}

char    *get_next_line(int fd)
{
    static t_list *list;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return (NULL);
    create_buffer(&list, fd);
    if (!list)
        return (NULL);
    line = extract_line(list);
    if (!line)
        return (NULL);
    polish_list(&list);
    return (line);  
}
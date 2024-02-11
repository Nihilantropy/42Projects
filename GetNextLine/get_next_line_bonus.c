/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:12:07 by crea              #+#    #+#             */
/*   Updated: 2024/02/11 17:19:56 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	polish_list(t_list **list)
{
	int		i;
	int		j;
	char	*buffer;
	t_list	*last_node;
	t_list	*new_head;

	new_head = malloc(sizeof(t_list));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || !new_head)
		return ;
	i = 0;
	j = 0;
	last_node = find_last_node(*list);
	while (last_node->data[i] && last_node->data[i] != '\n')
		i++;
	while (last_node->data[i] && last_node->data[i++])
		buffer[j++] = last_node->data[i];
	buffer[j] = '\0';
	new_head->data = buffer;
	new_head->next = NULL;
	clean_list(list, new_head, buffer);
}

char	*extract_line(t_list *list)
{
	char	*line;
	int		len;

	len = len_to_newline(list);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	cpy_nodes(line, list);
	return (line);
}

void	create_new_node(t_list **list, char *buffer, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    new_node->data = buffer;
    new_node->next = NULL;
    last_node = find_last_node(list[fd]);
    if (!last_node)
        list[fd] = new_node;
    else
        last_node->next = new_node;
}

void	create_buffer(t_list **list, int fd)
{
	ssize_t	bytes_read;
	char	*buffer;

	while (!(find_newline(list[fd])))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free (buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		create_new_node(list, buffer, fd);
	}
}

char	*get_next_line(int fd)
{
	static	t_list *list[4096];
	char	*line;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	create_buffer(list, fd);
	if (!list[fd])
		return (NULL);
	line = extract_line(list[fd]);
	polish_list(&list[fd]);
	return(line);
}

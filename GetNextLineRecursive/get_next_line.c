/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:18:16 by crea              #+#    #+#             */
/*   Updated: 2024/02/01 21:15:52 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_ret(int n, char *buffer)
{
	char	*ptr;

	ptr = malloc(n + 1);
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, buffer);
	return (ptr);
}

char	*ret(int n, char *buffer, int fd)
{
	size_t	byte_read;
	char	*ptr;

	ptr = str_ret(n, buffer);
	if (!ptr)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (*ptr == '\0' && byte_read == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (byte_read == 0)
		return (ptr);
	if (byte_read == 1)
	{
		free(ptr);
		return (NULL);
	}
	return (ft_strjoin(ptr, get_next_line(fd)));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[0] == '\n')
		return (str_ret(1, buffer));
	n = find_n(buffer);
	if (n > 0)
		return (str_ret(n, buffer));
	else
		return (ret(n, buffer, fd));
}

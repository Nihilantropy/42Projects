/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:53:28 by crea              #+#    #+#             */
/*   Updated: 2024/01/19 17:43:51 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dest;

	tot_size = count * size;
	if (count && size && (4294967295U / size <= count))
		return (NULL);
	dest = malloc(tot_size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, (tot_size));
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:53:28 by crea              #+#    #+#             */
/*   Updated: 2024/01/16 00:03:12 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dest;

	tot_size = count * size;
	if (tot_size > 2147483647)
		return (0);
	dest = malloc(tot_size);
	if (!dest || (count < 0 && size < 0))
		return (0);
	ft_memset(dest, 0, tot_size);
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:59:10 by crea              #+#    #+#             */
/*   Updated: 2024/01/15 21:42:21 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *arr, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)arr;
	while (n-- > 0)
		*ptr++ = (unsigned char)c;
	return (arr);
}

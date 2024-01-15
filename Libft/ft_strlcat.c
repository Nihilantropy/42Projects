/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:01:52 by crea              #+#    #+#             */
/*   Updated: 2024/01/15 22:27:29 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t sz)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (sz == 0)
		return (ft_strlen(src));
	while (dest[i] && i < sz)
		i++;
	while ((i + j +1) < sz && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i != sz)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}

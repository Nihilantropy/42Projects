/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:00:42 by crea              #+#    #+#             */
/*   Updated: 2024/01/15 21:47:18 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t	dup_sz;
	char	*dup_str;

	dup_sz = ft_strlen(str) +1;
	dup_str = (char *)malloc(dup_sz);
	if (!dup_str)
		return (0);
	ft_memcpy(dup_str, str, dup_sz);
	return (dup_str);
}

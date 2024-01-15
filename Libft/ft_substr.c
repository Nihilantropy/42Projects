/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:07:03 by crea              #+#    #+#             */
/*   Updated: 2024/01/15 23:47:49 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	sub_str = (char *)malloc(len + 1);
	if (!sub_str || !str)
		return (0);
	while (i < len && str[j])
	{
		sub_str[i++] = str[j++];
	}
	sub_str[i] = '\0';
	return (sub_str);
}

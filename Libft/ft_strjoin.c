/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:01:42 by crea              #+#    #+#             */
/*   Updated: 2024/01/15 23:55:16 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char    *str_join;
	size_t  sz_join;
	size_t  i;

	sz_join = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_join = (char *)malloc(sz_join);
	if (!str_join)
		return (0);
	i = 0;
	while(*s1)
		str_join[i++] = *s1++;
	while(*s2)
		str_join[i++] = *s2++;
	str_join[i] = '\0';
	return (str_join);
}

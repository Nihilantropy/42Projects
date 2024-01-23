/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:59:37 by crea              #+#    #+#             */
/*   Updated: 2024/01/15 19:51:23 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == (const char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

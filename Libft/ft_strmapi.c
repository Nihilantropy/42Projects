/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:27:56 by crea              #+#    #+#             */
/*   Updated: 2024/01/16 18:27:59 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char	*str_f;
	size_t	i;

	str_f = ft_strdup(str);
	if (!str_f)
		return (NULL);
	i = 0;
	while (str_f[i])
	{
		str_f[i] = (*f)(i, str_f[i]);
		i++;
	}
	return (str_f);
}

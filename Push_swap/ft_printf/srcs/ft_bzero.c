/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:20:56 by crea              #+#    #+#             */
/*   Updated: 2024/04/17 12:20:57 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*buf;

	i = 0;
	buf = s;
	while (i < n)
		buf[i++] = '\0';
}

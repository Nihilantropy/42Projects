/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:59:23 by crea              #+#    #+#             */
/*   Updated: 2024/02/05 15:06:26 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	if (!ft_check_char(s))
		return (0);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			count += ft_put(*s, args);
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:02:43 by crea              #+#    #+#             */
/*   Updated: 2024/01/26 13:52:39 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_hex(unsigned long long n, char c)
{
	int			count;
	static char	*digits;

	if (c == 'x')
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		print_hex(n / 16, c);
	count += ft_putchar(digits[n % 16]);
	return (count);
}

int	ft_putnbr_hex(long long num, char c)
{
	int					count;
	unsigned long long	n;

	count = 0;
	if (num < 0)
		n = (unsigned long long)(-num);
	else
		n = (unsigned long long)num;
	count += print_hex(n, c);
	return (count);
}

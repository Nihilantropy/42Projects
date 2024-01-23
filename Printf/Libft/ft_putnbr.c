/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:12:25 by crea              #+#    #+#             */
/*   Updated: 2024/01/23 22:55:30 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int count;
	unsigned int	nb;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	count += ft_putchar((char)(nb % 10 + 48));
	return (count);
}

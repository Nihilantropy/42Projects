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

int ft_putnbr(int n)
{
    int count;
    unsigned int nb;

    count = 0;
    nb = (n < 0) ? (unsigned int)(n * -1) : (unsigned int)n;

    if (n < 0)
        count += ft_putchar('-');
    
    if (nb == 0)
        return (count + ft_putchar('0'));

    if (nb >= 10)
        count += ft_putnbr(nb / 10);

    return (count + ft_putchar((char)(nb % 10 + '0')));
}


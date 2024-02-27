/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:59:23 by crea              #+#    #+#             */
/*   Updated: 2024/02/27 19:29:07 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"


static int	pft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static void    pft_strrev(char *str)
{
	char	c;
	int		i;
	int		n;

	if (!str)
		return ;
	i = 0;
	n = pft_strlen(str);
	while (i < n / 2)
	{
		c = str[n - i - 1];
		str[n - i - 1] = str[i];
		str[i] = c;
		i++;
	}
    pft_putstr(str);
}

static size_t	pft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	pft_putuns(unsigned int nb)
{
	unsigned int	count;

	count = 0;
	if (nb >= 10)
		count += pft_putuns(nb / 10);
	return (count + pft_putchar((char)(nb % 10 + '0')));
}

static int	pft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		count += pft_putstr("(null)");
		return (count);
	}
	while (*(str))
		count += pft_putchar(*str++);
	return (count);
}


static void	pft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*buf;

	i = 0;
	buf = s;
	while (i < n)
		buf[i++] = '\0';
}

static int	pft_putnbr_hex(size_t nb, char c)
{
	char	*base;
	char	*str;
	int		i;
	int		count;

	count = baselen(nb);
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	str = pft_calloc(sizeof(char), baselen(nb) + 1);
	if (!str)
		return (0);
	str[0] = '0';
	i = 0;
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	pft_strrev(str);	
	return (count);
}

static int	baselen(size_t nb)
{
	int		i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

static void	*pft_calloc(size_t n, size_t size)
{
	void	*buf;

	buf = malloc(n * size);
	if (!buf)
		return (NULL);
	if (buf)
		pft_bzero(buf, n * size);
	return (buf);
}

static int	ft_check_char(const char *s)
{
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			if (*s != 'c' && *s != 's' && *s != 'd' && *s != 'i'
				&& *s != 'u' && *s != 'X' && *s != 'x' && *s != 'p'
				&& *s != '%')
				return (0);
		}
		else if (*s == '%' && !*(s + 1))
			return (0);
		s++;
	}
	return (1);
}

static int	ft_put(char c, va_list args)
{
	int	count;

	count = 0;

	if (c == 'c')
		count += pft_putchar(va_arg(args, int));
	else if (c == 's')
		count += pft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += pft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += pft_putuns(va_arg(args, unsigned int));
	else if (c == 'p')
		count += pft_putptr(va_arg(args, void *));
	else if (c == 'x' || c == 'X')
		count += pft_putnbr_hex(va_arg(args, long long), c);
	else if (c == '%')
		count += pft_putchar('%');
	return (count);
}

static int	pft_putnbr(int n)
{
	int					count;
	unsigned long int	nb;

	count = 0;
	nb = (unsigned long)n;
	if (n < 0)
	{
		count += pft_putchar('-');
		nb *= -1;
	}
	if (nb == 0)
		return (count + pft_putchar('0'));
	if (nb >= 10)
		count += pft_putnbr(nb / 10);
	count += pft_putchar((char)(nb % 10 + '0'));
	return (count);
}

static size_t	digits_nb(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	while (n != 0)
	{
		digits++;
		n /= 16;
	}
	return (digits);
}

static void	print_ptr(uintptr_t addr)
{
	static char	*digits;

	digits = "0123456789abcdef";
	if (addr >= 16)
		print_ptr(addr / 16);
	write(1, &digits[addr % 16], 1);
}

static int	pft_putptr(void *addr)
{
	if (!addr)
	{
		pft_putstr("0x0");
		return (3);
	}
	pft_putstr("0x");
	print_ptr((uintptr_t)addr);
	return (digits_nb((uintptr_t)addr) + 2);
}

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

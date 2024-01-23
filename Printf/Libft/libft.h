/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:56:04 by crea              #+#    #+#             */
/*   Updated: 2024/01/23 22:55:55 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>

int ft_putchar(char c);
int ft_putstr(const char *str);
int ft_putnbr(int n);
int ft_put(char c, va_list args);

#endif

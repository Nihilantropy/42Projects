/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:41:42 by crea              #+#    #+#             */
/*   Updated: 2024/03/23 11:46:48 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' && ft_isdigit(str[i + 1])
			|| str[i] == '+' && ft_isdigit(str[i + 1])))
			return (1);
		else if (ft_isdigit(str[i]))
			return (1);
		else if (ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (0);
}
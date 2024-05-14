/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:14:32 by crea              #+#    #+#             */
/*   Updated: 2024/05/14 13:32:05 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_checks(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf(ERR_NBR_ARG);
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		if (!ft_isdigit_str(argv[i]))
		{
			printf(ERR_ARG_FORM);
			return (0);
		}
		else if (argv[i][0] == '0')
		{
			printf(ERR_ZERO_INPUT);
			return (0);
		}
		i++;
	}
	return (1);
}

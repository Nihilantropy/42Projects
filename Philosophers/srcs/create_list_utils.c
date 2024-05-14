/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:39:18 by crea              #+#    #+#             */
/*   Updated: 2024/05/14 14:44:36 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	printf_list(t_philo *philo)
{
	if (!table)
		return ;
	while (1)
	{
		printf("philo index is: %d\n", table->philo->index);
		if (table->philo->next == table->philo)
			break ;
		table->philo = table->philo->next;
	}
}

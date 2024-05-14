/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:39:18 by crea              #+#    #+#             */
/*   Updated: 2024/05/14 15:02:17 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_list(t_philo *philo)
{
	if (!philo)
		return ;
	while (1)
	{
		printf("philo index is: %d\n", philo->index);
		if (philo->next == philo)
			break ;
		philo = philo->next;
	}
}

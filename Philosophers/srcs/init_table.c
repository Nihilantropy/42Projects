/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:47:12 by crea              #+#    #+#             */
/*   Updated: 2024/05/16 17:05:17 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_table(t_table *table, char **argv)
{
	table->nbr_of_philo = ft_atoi(argv[1]);
	printf("Number of philosopher: %d\n", table->nbr_of_philo);
	if (argv[5])
		table->nbr_of_meals = ft_atoi(argv[5]);
	else
		table->nbr_of_meals = -1;
	printf("Number of meals to eat: %d\n", table->nbr_of_meals);
	if (pthread_mutex_init(&table->is_writing, NULL))
		return (0);
	table->dinner_start = false;
	printf("Dinner started? %d\n", table->dinner_start);
	table->dinner_end = false;
	printf("Dinner ended? %d\n", table->dinner_end);
	table->philo = NULL;
	if (!create_philo_list(&table->philo, argv))
		return (0);
	printf(PHILO_LIST_READY);
	return (1);
}

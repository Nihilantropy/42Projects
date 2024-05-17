/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_observer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:31:50 by crea              #+#    #+#             */
/*   Updated: 2024/05/17 22:29:56 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// static void	observer_action(t_table *table)
// {
// 	int	philo_has_eaten;
// 	t_philo	*current_philo;

// 	philo_has_eaten = 0;
// 	current_philo = table->philo;
// 	while (1)
// 	{
// 		while (!table->dinner_end)
// 		{
// 			while (current_philo)
// 			{
// 				if (table->philo->current_meal == table->nbr_of_meals)
// 				{
// 					philo_has_eaten++;
// 					if (philo_has_eaten == table->nbr_of_philo)
// 					{
// 						table->dinner_end = true;
// 						pthread_mutex_lock(&table->is_writing);
// 						printf("All philo have eaten %d meals\n", table->nbr_of_meals);
// 						printf("Dinner have ended at %llu\n", get_time());
// 						pthread_mutex_unlock(&table->is_writing);
// 						break ;
// 					}
// 				}
// 				current_philo = current_philo->next;
// 			}
// 			current_philo = table->philo;
// 		}
// 		return ;
// 	}
// 	return ;
// }

void	*observer(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	(void)table;

	pthread_mutex_lock(&table->is_writing);
	printf("Observer routine has started\n");
	printf("Dinner have started at %llu\n", get_time());
	pthread_mutex_unlock(&table->is_writing);
	//print_list(table->philo);
	//observer_action(table);
	return (NULL);
}

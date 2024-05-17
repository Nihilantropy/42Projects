/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_observer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:31:50 by crea              #+#    #+#             */
/*   Updated: 2024/05/17 12:25:30 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	return (NULL);
}

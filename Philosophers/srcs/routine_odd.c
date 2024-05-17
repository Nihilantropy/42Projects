/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_odd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:31:11 by crea              #+#    #+#             */
/*   Updated: 2024/05/17 22:06:47 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine_odd(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	(void)table;
	pthread_mutex_lock(&table->is_writing);
	printf("Philo routine odd has started\n");
	pthread_mutex_unlock(&table->is_writing);
	
	return (NULL);
}

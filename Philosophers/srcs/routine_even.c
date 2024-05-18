/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_even.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:58:03 by crea              #+#    #+#             */
/*   Updated: 2024/05/18 17:10:49 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	philo_actions(t_table *table, t_philo *current_philo)
{
	if (!table || !current_philo)
		return ;
	while (1)
	{
		if (table->dinner_end)
			break ;
		if (current_philo->is_eating)
			eating(table, current_philo);
		if (current_philo->is_sleeping)
			sleeping(table, current_philo);
		if (current_philo->is_thinking)
			thinking(table, current_philo);
	}
	return ;
}

void	*philo_routine_even(void *arg)
{
	t_table *table;
	t_philo *current_philo;

	table = (t_table *)arg;
	if (!table)
		return (NULL);
	pthread_mutex_lock(&table->is_sitting);
	current_philo = table->philo;
	while ((current_philo->index) != table->philo_index + 1)
		current_philo = current_philo->next;
	table->philo_index++;
	if (current_philo->index % 2 != 0)
		current_philo->is_eating = true;
	else
		current_philo->is_thinking = true;
	pthread_mutex_unlock(&table->is_sitting);
	philo_actions(table, current_philo);
	return (NULL);
}

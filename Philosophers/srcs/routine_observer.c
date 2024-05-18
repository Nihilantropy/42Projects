/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_observer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:31:50 by crea              #+#    #+#             */
/*   Updated: 2024/05/18 18:46:20 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	check_meals(t_table *table)
{
	int		philo_has_eaten;
	t_philo	*current_philo;

	philo_has_eaten = 0;
	current_philo = table->philo;
	while (1)
	{
		if (table->philo->current_meal == table->nbr_of_meals)
		{
			philo_has_eaten++;
			if (philo_has_eaten == table->nbr_of_philo)
			{
				table->dinner_end = true;
				pthread_mutex_lock(&table->is_writing);
				printf("All philo have eaten %d meals\n", table->nbr_of_meals);
				printf("Dinner have ended at %llu\n", get_time());
				pthread_mutex_unlock(&table->is_writing);
				break ;
			}
		}
		current_philo = current_philo->next;
		if (current_philo == table->philo)
			break ;
	}
	return ;
}

static void	check_death(t_table *table)
{
	t_philo		*current_philo;
	long long	current_time;

	current_philo = table->philo;
	while (1)
	{
		current_time = get_time();
		if (current_philo->last_meal && (current_philo->is_eating == false) &&
			(current_time - current_philo->last_meal > table->philo->time_to_die))
		{
			current_philo->is_dead = true;
			pthread_mutex_lock(&table->death);
			if (table->dinner_end)
			{
				pthread_mutex_unlock(&table->death);
				return ;
			}
			pthread_mutex_lock(&table->is_writing);
			printf("%llu %d died\n", current_time, current_philo->index);
			printf("Dinner have ended at %llu\n", current_time);
			printf("Death check\n");
			pthread_mutex_unlock(&table->is_writing);
			table->dinner_end = true;
			pthread_mutex_unlock(&table->death);
			break ;
		}
		current_philo = current_philo->next;
		if (current_philo == table->philo)
			break ;
	}
	return ;
}

static void	observer_action(t_table *table)
{
	while (!table->dinner_end)
	{
		if (table->nbr_of_meals != -1)
			check_meals(table);
		if (table->dinner_end)
			break ;
		check_death(table);
		if (table->dinner_end)
			break ;
	}
	return ;
}

void	*observer(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	(void)table;

	pthread_mutex_lock(&table->is_sitting);
	pthread_mutex_lock(&table->is_writing);
	table->dinner_start = get_time();
	printf("Observer routine has started\n");
	printf("dinner start %llu\n", table->dinner_start);
	pthread_mutex_unlock(&table->is_writing);
	//print_list(table->philo);
	pthread_mutex_unlock(&table->is_sitting);
	observer_action(table);
	return (NULL);
}

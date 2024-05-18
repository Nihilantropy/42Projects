/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:56:45 by crea              #+#    #+#             */
/*   Updated: 2024/05/18 12:21:37 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating(t_table *table, t_philo *current_philo)
{
	long long current_time;

	if (!table || !current_philo)
		return ;
	pthread_mutex_lock(&current_philo->right_fork);
	pthread_mutex_lock(&current_philo->next->right_fork);
	pthread_mutex_lock(&current_philo->dead_lock);
	if (table->dinner_end)
	{
		pthread_mutex_unlock(&current_philo->right_fork);
		pthread_mutex_unlock(&current_philo->next->right_fork);
		pthread_mutex_unlock(&current_philo->dead_lock);
		return ;
	}
	current_time = get_time();

	current_philo->is_sleeping = false;
	current_philo->is_thinking = false;

	pthread_mutex_lock(&table->is_writing);
	printf("%llu %d has taken a fork\n", current_time, current_philo->index);
	printf("%llu %d is eating\n", current_time, current_philo->index);
	pthread_mutex_unlock(&table->is_writing);

	usleep(current_philo->time_for_eat * 1000);
	current_philo->last_meal = get_time();
	pthread_mutex_lock(&table->is_writing);
	printf("philo %d last meal: %llu\n", current_philo->index, current_philo->last_meal);
	pthread_mutex_unlock(&table->is_writing);

	if (table->nbr_of_meals != -1)
		current_philo->current_meal++;
	current_philo->is_eating = false;
	current_philo->is_sleeping = true;

	pthread_mutex_unlock(&current_philo->right_fork);
	pthread_mutex_unlock(&current_philo->next->right_fork);
	pthread_mutex_unlock(&current_philo->dead_lock);

}

void	sleeping(t_table *table, t_philo *current_philo)
{
	long long current_time;

	if (table->dinner_end)
		return ;
	current_time = get_time();
	pthread_mutex_lock(&table->is_writing);
	printf("%llu %d is sleeping\n", current_time, current_philo->index);
	pthread_mutex_unlock(&table->is_writing);
	usleep(current_philo->time_for_sleep * 1000);
	if (current_philo->last_meal)
	{		
		if (get_time() - current_philo->last_meal >= current_philo->time_to_die)
		{
			pthread_mutex_lock(&table->death);
			current_philo->is_sleeping = false;
			current_philo->is_dead = true;
			if (table->dinner_end)
			{
				pthread_mutex_unlock(&table->death);
				return ;
			}
			pthread_mutex_lock(&table->is_writing);
			printf("%llu %d died\n", current_time, current_philo->index);
			pthread_mutex_unlock(&table->is_writing);
			table->dinner_end = true;
			pthread_mutex_unlock(&table->death);
			return ;
		}
	}
	current_philo->is_sleeping = false;
	current_philo->is_thinking = true;
}

void	thinking(t_table *table, t_philo *current_philo)
{
	long long current_time;

	if (table->dinner_end)
		return;
	current_time = get_time();
	pthread_mutex_lock(&table->is_writing);
	printf("%llu %d is thinking\n", current_time, current_philo->index);
	pthread_mutex_unlock(&table->is_writing);
	if (current_philo->last_meal)
	{
		if (get_time() - current_philo->last_meal >= current_philo->time_to_die)
		{
			pthread_mutex_lock(&table->death);
			current_philo->is_thinking = false;
			current_philo->is_dead = true;
			if (table->dinner_end)
			{
				pthread_mutex_unlock(&table->death);
				return ;
			}
			pthread_mutex_lock(&table->is_writing);
			printf("%llu %d died\n", current_time, current_philo->index);
			pthread_mutex_unlock(&table->is_writing);
			table->dinner_end = true;
			pthread_mutex_unlock(&table->death);
			return ;
		}
	}
	usleep(1000);
	current_philo->is_thinking = false;
	current_philo->is_eating = true;
}
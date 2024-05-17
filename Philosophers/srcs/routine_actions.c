/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:56:45 by crea              #+#    #+#             */
/*   Updated: 2024/05/17 13:43:25 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating(t_table *table, t_philo *current_philo)
{
	long long current_time;

	if (!table || !current_philo)
		return ;
	current_time = get_time();
	pthread_mutex_lock(&current_philo->right_fork);
	pthread_mutex_lock(&current_philo->next->right_fork);
	pthread_mutex_lock(&current_philo->dead_lock);
	pthread_mutex_lock(&table->is_writing);
	current_philo->is_sleeping = false;
	current_philo->is_thinking = false;
	printf("%llu %d has taken a fork\n", current_time, current_philo->index);
	printf("%llu %d is eating\n", current_time, current_philo->index);
	usleep(current_philo->time_for_eat * 1000);
	current_philo->current_meal++;
	current_philo->last_meal = current_time;
	printf("philo %d current meal is: %d\n", current_philo->index, current_philo->current_meal);
	current_philo->is_eating = false;
	pthread_mutex_unlock(&table->is_writing);
	pthread_mutex_unlock(&current_philo->dead_lock);
	pthread_mutex_unlock(&current_philo->next->right_fork);
	pthread_mutex_unlock(&current_philo->right_fork);
	current_philo->is_sleeping = true;
	
}

void	sleeping(t_table *table, t_philo *current_philo)
{
	long long current_time;

	current_time = get_time();
	//pthread_mutex_lock(&table->is_writing);
	printf("philo %d is sleeping\n", current_philo->index);
	usleep(current_philo->time_for_sleep * 1000);
	if (current_time >= current_philo->last_meal + current_philo->time_to_die)
	{
		current_philo->is_dead = true;
		printf("%llu %d died\n", get_time(), current_philo->index);
		current_philo->is_sleeping = false;
		table->dinner_end = true;
		return ;
	}
	current_philo->is_sleeping = false;
	current_philo->is_thinking = true;
	//pthread_mutex_unlock(&table->is_writing);
}

void	thinking(t_table *table, t_philo *current_philo)
{
	long long current_time;

	current_time = get_time();
	//pthread_mutex_lock(&table->is_writing);
	printf("philo %d is thinking\n", current_philo->index);
	usleep(current_philo->time_for_eat * 1000);
	if (current_time >= current_philo->last_meal + current_philo->time_to_die)
	{
		current_philo->is_dead = true;
		printf("%llu %d died\n", get_time(), current_philo->index);
		current_philo->is_thinking = false;
		table->dinner_end = true;
		return ;
	}
	current_philo->is_thinking = false;
	current_philo->is_eating = true;
	//pthread_mutex_unlock(&table->is_writing);
}
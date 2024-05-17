/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:39:18 by crea              #+#    #+#             */
/*   Updated: 2024/05/17 12:07:48 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_list(t_philo *philo)
{
	if (!philo)
		return ;
	while (philo)
	{
		printf("philo index: **%d**\n", philo->index);
		printf("philo time to die: %llu msec\n", philo->time_to_die);
		printf("philo time for sleep: %llu msec\n", philo->time_for_sleep);
		printf("philo time for eat: %llu msec\n", philo->time_for_eat);
		printf("philo current meal: %d\n", philo->current_meal);
		philo = philo->next;
	}
}

void	free_list(t_philo **philo)
{
	t_philo	*current;
	t_philo	*next;

	current = *philo;
	if (!current)
		return ;
	while (current)
	{
		next = current->next;
		pthread_mutex_destroy(&current->dead_lock);
		pthread_mutex_destroy(&current->right_fork);
		free(current);
		current = next;
	}
	*philo = NULL;
}

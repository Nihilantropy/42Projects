/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:19:06 by crea              #+#    #+#             */
/*   Updated: 2024/05/14 15:24:03 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&philo->is_sleeping, NULL))
		return (0);
	if (pthread_mutex_init(&philo->is_thinking, NULL))
		return (0);
	if (pthread_mutex_init(&philo->is_eating, NULL))
		return (0);
	if (pthread_mutex_init(&philo->right_fork, NULL))
		return (0);
	return (1);
}

int	init_philo(t_philo *philo, char **argv, int index)
{
	philo->index = index;
	printf("philo index is: %d\n", philo->index);
	philo->is_dead = false;
	printf("philo is dead? %d\n", philo->is_dead);
	philo->time_to_die = ft_atol(argv[2]);
	printf("philo time to die is: %llu\n", philo->time_to_die);
	philo->time_for_sleep = ft_atol(argv[4]);
	printf("philo time for sleep is: %llu\n", philo->time_for_sleep);
	philo->time_for_eat = ft_atol(argv[3]);
	printf("philo time for eat is: %llu\n", philo->time_for_eat);
	if (argv[5])
		philo->nbr_of_meals = ft_atoi(argv[5]);
	else
		philo->nbr_of_meals = -1;
	printf("philo nbr of meals is: %d\n", philo->nbr_of_meals);
	if (!init_mutex(philo))
	{
		printf("can't init philo mutexes\n");
		return (0);
	}
	return (1);
}

int	create_philo_list(t_philo **philo, char **argv)
{
	int		i;
	t_philo	*new_philo;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		printf("number of philo is: %d\n", ft_atoi(argv[1]));
		new_philo = malloc(sizeof(t_philo));
		if (!new_philo)
		{
			printf("can't alloc mem for philo\n");
			return (0);
		}
		if (!init_philo(new_philo, argv, i))
		{
			printf("can't init new philo\n");
			return (0);
		}
		if (!*philo)
		{
			new_philo->next = new_philo;
			new_philo->prev = new_philo;
			*philo = new_philo;
		}
		else
		{
			new_philo->next = (*philo);
			new_philo->prev = (*philo)->prev;
			(*philo)->prev->next = new_philo;
			(*philo)->prev = new_philo;
		}
		i++;
	}
	printf("ciao\n");
	//print_list(*philo);
	return (1);
}

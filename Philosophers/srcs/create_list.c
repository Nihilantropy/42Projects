/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:19:06 by crea              #+#    #+#             */
/*   Updated: 2024/05/14 14:42:15 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philo(t_philo *philo, char **argv, int i)
{
	philo->index = i;
	philo->is_dead = false;
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_for_eat = ft_atol(argv[3]);
	philo->time_for_sleep = ft_atol(argv[4]);
	if (argv[5])
		philo->nbr_of_meals = ft_atoi(argv[5]);
	init_mutex(philo);
	philo->next = NULL;
	philo->prev = NULL;
}

int	create_node(t_philo **philo, char **argv)
{
	int		i;
	t_philo	*new_philo;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		new_philo = malloc(sizeof(t_philo));
		if (!new_philo)
			return (0);
		init_philo(new_philo, argv, i);
		if (!*table)
			*table = new_philo;
		else
		{
			*table->prev->next = new_philo;
			*table->prev = new_philo;
		}
	}
	return (1);
}

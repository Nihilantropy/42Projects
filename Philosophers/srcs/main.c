/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:41:24 by crea              #+#    #+#             */
/*   Updated: 2024/05/14 15:21:55 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_table(t_table *table, char **argv)
{
	table->philo = NULL;
	if (!create_philo_list(&table->philo, argv))
		return (0);
	printf("lista creata\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!ft_checks(argc, argv))
		return (0);
	printf("controlli superati\n");
	if (!init_table(&table, argv))
		return (0);
	printf("tavolo inizializzato\n");
}

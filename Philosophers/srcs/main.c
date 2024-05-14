/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:41:24 by crea              #+#    #+#             */
/*   Updated: 2024/05/14 14:41:38 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_table(t_table *table, char **argv)
{
	if (!create_node(&table->philo, argv))
		return (0);
	printf("initializing table. %p %p\n", table, argv);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!ft_checks(argc, argv))
		return (0);
	if (!init_table(&table, argv))
		return (0);
}

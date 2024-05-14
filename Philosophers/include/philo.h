/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:27:02 by crea              #+#    #+#             */
/*   Updated: 2024/05/14 14:45:06 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include "messages.h"

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_philo
{
	int				index;
	t_bool			is_dead;
	long long		time_to_die;
	long long		time_for_eat;
	long long		time_for_sleep;
	pthread_mutex_t	is_sleeping;
	pthread_mutex_t	is_thinking;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	right_fork;
	struct s_philo	*next;
	struct s_philo	*prev;
}					t_philo;

typedef struct s_table
{
	int		nbr_of_philo;
	int		nbr_of_meals;
	t_bool	dinner_start;
	t_bool	dinner_end;
	t_philo	*philo;

}			t_table;

/* main */
int			init_table(t_table **table, char **argv);

/* main_utils */
long long	get_time(void);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);

/* checks */
int			ft_checks(int argc, char **argv);
int			ft_isdigit_str(char *str);

/* create_list */

/* create_list_utils */
void		printf_list(t_philo *philo);

#endif
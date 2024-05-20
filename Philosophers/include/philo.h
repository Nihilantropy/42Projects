/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:27:02 by crea              #+#    #+#             */
/*   Updated: 2024/05/20 16:12:20 by crea             ###   ########.fr       */
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
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		last_meal;
	int				current_meal;
	t_bool			first_meal;
	t_bool			is_sleeping;
	t_bool			is_thinking;
	t_bool			is_eating;
	t_bool			is_dead;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	right_fork;
	struct s_philo	*next;
	struct s_philo	*prev;
}					t_philo;

typedef struct s_table
{
	int					nbr_of_philo;
	int					philo_index;
	int					nbr_of_meals;
	t_bool				first_meal;
	pthread_mutex_t		is_sitting;
	pthread_mutex_t		is_writing;
	pthread_mutex_t		death;
	long long			dinner_start;
	t_bool				dinner_end;
	t_philo				*philo;

}						t_table;

/* init table */
int			init_table(t_table *table, char **argv);
void		destroy_mutexes(t_table *table);

/* main_utils */
long long	get_time(void);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);

/* checks */
int			ft_checks(int argc, char **argv);

/* checks_utils*/
int			check_positive_input(char *str);
int			ft_isdigit_str(char *str);
int			max_thread(char *str);

/* create_list */
int			init_philo(t_philo *philo, char **argv, int index);
int			create_philo_list(t_philo **philo, char **argv);

/* create_list_utils */
void		print_list(t_philo *philo);
void		free_list(t_philo **philo);

/* The even and odd refers to the number of philosophers, not their index */
/* routines */
void		*philo_routine_even(void *arg);
void		*philo_routine_odd(void *arg);
void		*observer(void *arg);

/* routine even actions */
void		eating_even(t_table *table, t_philo *current_philo);
void		sleeping_even(t_table *table, t_philo *current_philo);
void		thinking_even(t_table *table, t_philo *current_philo);

/* routine odd actions */
void		eating_odd(t_table *table, t_philo *current_philo);
void		sleeping_odd(t_table *table, t_philo *current_philo);
void		thinking_odd(t_table *table, t_philo *current_philo);

#endif
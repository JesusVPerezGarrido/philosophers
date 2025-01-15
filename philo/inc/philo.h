/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:57:53 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/13 12:07:55 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>		// write
# include <stdio.h>			// printf
# include <stdlib.h>		// malloc free
# include <pthread.h>		// pthread/mutex
# include "time_utils.h"	// gettimeofday/usleep
# include <string.h> 		// memset

typedef enum e_exit
{
	OK,
	ARG_NUM,
	INV_ARG,
	MALLOC_ERROR,
	MUTEX_ERROR,
	THREAD_ERROR,
}	t_exit;

typedef enum e_bool
{
	false,
	true,
}	t_bool;

typedef struct s_setting
{
	t_milliseconds	time_die;
	t_milliseconds	time_eat;
	t_milliseconds	time_sleep;
	int				number_eats;
}	t_settings;

typedef struct s_philo
{
	int				id;
	struct timeval	born;
	struct timeval	last_eat;
	pthread_mutex_t	leat_mut;
	int				number_eat;
	pthread_mutex_t	neat_mut;
	pthread_mutex_t	*forks[2];
	t_settings		settings;
	t_bool			*lethal;
	pthread_mutex_t	*lethal_mut;
	pthread_t		thread;
	pthread_mutex_t	*print;
}					t_philo;

typedef struct s_table
{
	int				size;
	struct timeval	start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_bool			lethal;
	pthread_mutex_t	lethal_mut;
	pthread_mutex_t	print;
	pthread_t		thread;
	t_settings		settings;
}					t_table;

typedef union u_mutex_value
{
	struct timeval	tv;
	int				i;
}					t_mutex_value;

t_exit		valid_args(int argc, char **argv);
int			ft_atoi(const char *nptr);
t_bool		ft_isdigit(char c);
t_exit		create_table(t_table **table, int argc, char **argv);
void		create_settings(t_table *table, int argc, char **argv);
t_exit		create_forks(t_table *table);
t_exit		create_philos(t_table *table);
void		*ft_calloc(size_t nmemb, size_t size);
void		*philo_manager(void *arg);
void		*monitor_manager(void *arg);
void		pheat(t_philo *philo);
t_bool		is_lethal(t_bool *address, pthread_mutex_t *mutex);

#endif

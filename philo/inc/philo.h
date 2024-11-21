/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:57:53 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/21 15:53:36 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>		// write/usleep
# include <stdio.h>			// printf
# include <stdlib.h>		// malloc free
# include <pthread.h>		// pthread/mutex
# include "time_utils.h"	// gettimeofday
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

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}		t_fork;

typedef struct s_philo
{
	int				id;
	t_bool			alive;
	struct timeval	born;
	struct timeval	last_eat;
	int				number_eat;
	t_fork			*forks[2];
	t_settings		*settings;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*print;
}					t_philo;

typedef struct s_table
{
	int				size;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	print;
	pthread_t		thread;
	t_settings		settings;
}					t_table;

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

#endif

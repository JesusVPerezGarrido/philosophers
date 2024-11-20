/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:57:53 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/20 13:07:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>	// write usleep
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc free
# include <pthread.h>	// pthread/mutex
# include <sys/time.h>	// gettimeofday
# include <string.h> 	// memset

typedef enum e_bool
{
	false,
	true,
}	t_bool;

typedef time_t	t_milliseconds;
typedef time_t	t_microseconds;
typedef time_t	t_seconds;

typedef struct s_setting
{
	t_milliseconds	time_die;
	t_milliseconds	time_eat;
	t_milliseconds	time_sleep;
	int				number_eats;
}	t_settings;

typedef struct s_philo
{
	int			id;
	t_settings	*settings;
	pthread_t	thread;
}				t_philo;

t_bool		valid_args(int argc, char **argv);
int			ft_atoi(const char *nptr);
t_bool		ft_isdigit(char c);
t_settings	create_settings(int argc, char **argv);
t_philo		*create_philo(int nphilo, t_settings *setting);
void		*ft_calloc(size_t nmemb, size_t size);
void		*philo_manager(void *arg);

#endif

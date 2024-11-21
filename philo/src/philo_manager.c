/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:25:41 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/21 11:30:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	pheat(t_philo *philo)
{
	struct timeval	tv;

	pthread_mutex_lock(&philo->mutex);
	gettimeofday(&tv, NULL);
	if (tvtoms(time_diff(philo->last_eat, tv)) > philo->settings->time_die)
		return (0);
	pthread_mutex_lock(&philo->forks[0]->mutex);
	pthread_mutex_lock(&philo->forks[1]->mutex);
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_lock(philo->print);
	printf("%li %i is eating\n", tvtoms(time_diff(philo->born,
				philo->last_eat)), philo->id);
	pthread_mutex_unlock(philo->print);
	usleep(mstomus(philo->settings->time_eat));
	pthread_mutex_unlock(&philo->forks[0]->mutex);
	pthread_mutex_unlock(&philo->forks[1]->mutex);
	return (1);
}

static void	phsleep(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philo->print);
	printf("%li %i is sleeping\n", tvtoms(time_diff(philo->born,
				tv)), philo->id);
	pthread_mutex_unlock(philo->print);
	usleep(mstomus(philo->settings->time_sleep));
}

static void	phthink(t_philo *philo)
{
	struct timeval	tv;

	philo->alive = true;
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philo->print);
	printf("%li %i is thinking\n", tvtoms(time_diff(philo->born,
				tv)), philo->id);
	pthread_mutex_unlock(philo->print);
}

void	*philo_manager(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->mutex);
	gettimeofday(&philo->born, NULL);
	philo->last_eat = philo->born;
	while (true)
	{
		if (!pheat(philo))
		{
			philo->alive = false;
			break ;
		}
		phsleep(philo);
		phthink(philo);
	}
	return (NULL);
}

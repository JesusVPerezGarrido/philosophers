/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:13:22 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/22 15:29:23 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	grab_fork(t_philo *philo, t_fork *fork)
{
	struct timeval	tv;

	pthread_mutex_lock(&fork->mutex);
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philo->print);
	printf("%li %i has taken a fork\n", tvtoms(time_diff(tv, philo->born)),
		philo->id);
	pthread_mutex_unlock(philo->print);
}

static void	pheat(t_philo *philo)
{
	if (philo->id % 2)
	{
		grab_fork(philo, philo->forks[0]);
		grab_fork(philo, philo->forks[1]);
	}
	else
	{
		grab_fork(philo, philo->forks[1]);
		grab_fork(philo, philo->forks[0]);
	}
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_lock(philo->print);
	printf("%li %i is eating\n", tvtoms(time_diff(philo->last_eat,
				philo->born)), philo->id);
	pthread_mutex_unlock(philo->print);
	philo->number_eat++;
	wait(philo->settings->time_eat);
	pthread_mutex_lock(philo->print);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_unlock(&philo->forks[0]->mutex);
	pthread_mutex_unlock(&philo->forks[1]->mutex);
}

static void	phsleep(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philo->print);
	printf("%li %i is sleeping\n", tvtoms(time_diff(tv, philo->born)),
		philo->id);
	pthread_mutex_unlock(philo->print);
	wait(philo->settings->time_sleep);
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philo->print);
	printf("%li %i is thinking\n", tvtoms(time_diff(tv, philo->born)),
		philo->id);
	pthread_mutex_unlock(philo->print);
}

void	*philo_manager(void *arg)
{
	t_philo	*philo;

	philo = arg;
	gettimeofday(&philo->born, NULL);
	pthread_mutex_unlock(&philo->mutex);
	philo->last_eat = philo->born;
	while (true)
	{
		pheat(philo);
		phsleep(philo);
	}
	return (arg);
}

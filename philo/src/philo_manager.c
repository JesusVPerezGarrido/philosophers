/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:13:22 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/13 16:42:57 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	grab_fork(t_philo *philo, t_fork *fork)
{
	struct timeval	tv;

	pthread_mutex_lock(&fork->mutex);
	gettimeofday(&tv, NULL);
	if (*philo->lethal)
		return ;
	pthread_mutex_lock(philo->print);
	printf("%li %i has taken a fork\n", tvtoms(time_diff(tv, philo->born)),
		philo->id);
	pthread_mutex_unlock(philo->print);
}

static void	pheat(t_philo *philo)
{
	grab_fork(philo, philo->forks[0]);
	if (philo->forks[0] == philo->forks[1])
		return ;
	grab_fork(philo, philo->forks[1]);
	if (*philo->lethal)
		return ;
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_lock(philo->print);
	printf("%li %i is eating\n", tvtoms(time_diff(philo->last_eat,
				philo->born)), philo->id);
	pthread_mutex_unlock(philo->print);
	philo->number_eat++;
	wait(philo->settings->time_eat);
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
	if (*philo->lethal)
		return ;
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
	if (philo->id % 2)
		wait(5);
	while (!(*philo->lethal))
	{
		pheat(philo);
		if (philo->forks[0] == philo->forks[1])
			break ;
		if (*philo->lethal)
			break ;
		phsleep(philo);
	}
	return (arg);
}

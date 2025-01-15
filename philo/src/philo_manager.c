/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:13:22 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/13 13:29:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	phsleep(t_philo *philo)
{
	struct timeval	start;
	struct timeval	now;

	if (is_lethal(philo->lethal, philo->lethal_mut))
		return ;
	gettimeofday(&start, NULL);
	now = start;
	pthread_mutex_lock(philo->print);
	printf("%li %i is sleeping\n", tvtoms(time_diff(start, philo->born)),
		philo->id);
	pthread_mutex_unlock(philo->print);
	while (tvtoms(time_diff(now, start)) < philo->settings.time_sleep)
	{
		usleep(100);
		gettimeofday(&now, NULL);
		if (is_lethal(philo->lethal, philo->lethal_mut))
			return ;
	}
	pthread_mutex_lock(philo->print);
	printf("%li %i is thinking\n", tvtoms(time_diff(now, philo->born)),
		philo->id);
	pthread_mutex_unlock(philo->print);
	usleep(100);
}

static void	philo_init(t_philo *philo)
{
	pthread_mutex_lock(&philo->leat_mut);
	philo->last_eat = philo->born;
	pthread_mutex_unlock(&philo->leat_mut);
	if (philo->id % 2)
		usleep(1000);
}

void	*philo_manager(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo_init(philo);
	if (philo->forks[0] == philo->forks[1])
	{
		pthread_mutex_lock(philo->print);
		printf("0 %i has taken a fork\n", philo->id);
		pthread_mutex_unlock(philo->print);
		return (NULL);
	}
	while (!is_lethal(philo->lethal, philo->lethal_mut))
	{
		pheat(philo);
		phsleep(philo);
	}
	return (NULL);
}

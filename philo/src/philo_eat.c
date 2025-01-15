/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:10:42 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/13 13:22:45 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	grab_fork(t_philo *philo, pthread_mutex_t *fork)
{
	struct timeval	tv;

	pthread_mutex_lock(fork);
	gettimeofday(&tv, NULL);
	if (is_lethal(philo->lethal, philo->lethal_mut))
		return ;
	pthread_mutex_lock(philo->print);
	printf("%li %i has taken a fork\n", tvtoms(time_diff(tv, philo->born)),
		philo->id);
	pthread_mutex_unlock(philo->print);
}

static void	pheat_forks(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		grab_fork(philo, philo->forks[0]);
		grab_fork(philo, philo->forks[1]);
	}
	else
	{
		grab_fork(philo, philo->forks[1]);
		grab_fork(philo, philo->forks[0]);
	}
}

static void	pheat_print(t_philo *philo)
{
	pthread_mutex_lock(&philo->leat_mut);
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_unlock(&philo->leat_mut);
	pthread_mutex_lock(philo->print);
	printf("%li %i is eating\n", tvtoms(time_diff(philo->last_eat,
				philo->born)), philo->id);
	pthread_mutex_unlock(philo->print);
}

static void	pheat_wait(t_philo *philo)
{
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	now = start;
	while (tvtoms(time_diff(now, start)) < philo->settings.time_eat)
	{
		usleep(100);
		gettimeofday(&now, NULL);
		if (is_lethal(philo->lethal, philo->lethal_mut))
			return ;
	}
	pthread_mutex_lock(&philo->neat_mut);
	philo->number_eat++;
	pthread_mutex_unlock(&philo->neat_mut);
}

void	pheat(t_philo *philo)
{
	if (is_lethal(philo->lethal, philo->lethal_mut))
		return ;
	pheat_forks(philo);
	if (!is_lethal(philo->lethal, philo->lethal_mut))
		pheat_print(philo);
	if (!is_lethal(philo->lethal, philo->lethal_mut))
		pheat_wait(philo);
	pthread_mutex_unlock(philo->forks[0]);
	pthread_mutex_unlock(philo->forks[1]);
}

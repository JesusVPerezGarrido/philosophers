/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:13:22 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/07 17:11:38 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	phsleep(t_philo *philo)
{
	struct timeval	tv;

	if (is_lethal(philo->lethal, philo->lethal_mut))
		return ;
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philo->print);
	printf("%li %i is sleeping\n", tvtoms(time_diff(tv, philo->born)),
		philo->id);
	pthread_mutex_unlock(philo->print);
	wait(philo->settings.time_sleep);
	gettimeofday(&tv, NULL);
	if (is_lethal(philo->lethal, philo->lethal_mut))
		return ;
	pthread_mutex_lock(philo->print);
	printf("%li %i is thinking\n", tvtoms(time_diff(tv, philo->born)),
		philo->id);
	pthread_mutex_unlock(philo->print);
}

static void	philo_init(t_philo *philo)
{
	gettimeofday(&philo->born, NULL);
	pthread_mutex_lock(&philo->leat_mut);
	philo->last_eat = philo->born;
	pthread_mutex_unlock(&philo->leat_mut);
	if (philo->id % 2)
		wait(10);
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
		if (philo->forks[0] == philo->forks[1])
			break ;
		phsleep(philo);
	}
	return (NULL);
}

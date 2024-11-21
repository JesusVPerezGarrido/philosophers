/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:49:43 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/21 11:39:45 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_exit	create_philos(t_table *table)
{
	int		index;
	t_philo	*philo;

	table->philos = ft_calloc(table->size, sizeof(t_philo));
	if (!table->philos)
		return (MALLOC_ERROR);
	index = 0;
	while (index < table->size)
	{
		philo = &table->philos[index];
		philo->id = index;
		philo->alive = true;
		philo->forks[0] = &table->forks[index];
		philo->forks[1] = &table->forks[(index + 1) % table->size];
		philo->settings = &table->settings;
		if (pthread_mutex_init(&philo->mutex, NULL))
			return (MUTEX_ERROR);
		pthread_mutex_lock(&philo->mutex);
		philo->print = &table->print;
		if (pthread_create(&philo->thread, NULL, philo_manager, philo))
			return (THREAD_ERROR);
		index++;
	}
	return (OK);
}

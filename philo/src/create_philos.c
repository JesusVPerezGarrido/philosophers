/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:49:43 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/09 16:38:13 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_mutex(t_table *table, t_philo *philo)
{
	philo->lethal = &table->lethal;
	philo->print = &table->print;
	philo->lethal_mut = &table->lethal_mut;
	if (pthread_mutex_init(&philo->neat_mut, NULL))
		return (1);
	if (pthread_mutex_init(&philo->leat_mut, NULL))
		return (1);
	return (0);
}

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
		philo->id = index + 1;
		philo->born = table->start;
		philo->number_eat = 0;
		philo->settings = table->settings;
		philo->forks[0] = &table->forks[index];
		philo->forks[1] = &table->forks[(index + 1) % table->size];
		if (create_philo_mutex(table, philo))
			return (MUTEX_ERROR);
		if (pthread_create(&philo->thread, NULL, philo_manager, philo))
			return (THREAD_ERROR);
		index++;
	}
	return (OK);
}

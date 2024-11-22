/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:14:38 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/22 15:33:44 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_start(t_table *table)
{
	int index;
	
	index = 0;
	while (index < table->size)
	{
		pthread_mutex_lock(&table->philos[index].mutex);
		index++;
	}
}

static t_bool	check_death(struct timeval tv, t_table *table, int index)
{
	t_philo			philo;
	t_milliseconds	time_die;

	philo = table->philos[index];
	time_die = table->settings.time_die;
	if (tvtoms(time_diff(tv, philo.last_eat)) > time_die + 1)
	{
		pthread_mutex_lock(&table->print);
		printf("%li %i died\n", tvtoms(time_diff(tv, philo.born)), index);
		pthread_mutex_unlock(&table->print);
		return (true);
	}
	return (false);	
}

void	*monitor_manager(void *arg)
{
	t_table			*table;
	struct timeval	tv;
	int				index;
	int				lowest;

	table = arg;
	philo_start(table);
	while (true)
	{
		index = 0;
		gettimeofday(&tv, NULL);
		lowest = table->philos[0].number_eat;
		while (index < table->size)
		{
			if (table->philos[index].number_eat < lowest)
				lowest = table->philos[index].number_eat;
			if (check_death(tv, table, index))
				return (arg);
			index++;
		}
		if (table->settings.number_eats
			&& lowest >= table->settings.number_eats)
			return (arg);
	}
	return (arg);
}

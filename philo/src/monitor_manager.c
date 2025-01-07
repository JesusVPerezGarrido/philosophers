/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:14:38 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/07 17:22:34 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_death(t_table *table)
{
	struct timeval	tv;
	struct timeval	last_eat;
	int				index;

	index = 0;
	while (index < table->size)
	{
		pthread_mutex_lock(&table->philos[index].leat_mut);
		last_eat = table->philos[index].last_eat;
		pthread_mutex_unlock(&table->philos[index].leat_mut);
		gettimeofday(&tv, NULL);
		if (tvtoms(time_diff(tv, last_eat)) > table->settings.time_die)
		{
			pthread_mutex_lock(&table->print);
			printf("%li %i died\n", tvtoms(time_diff(tv, last_eat)), index);
			pthread_mutex_unlock(&table->print);
			pthread_mutex_lock(&table->lethal_mut);
			table->lethal = true;
			pthread_mutex_unlock(&table->lethal_mut);
			return ;
		}
		index++;
	}
}

static void	check_neats(t_table *table)
{
	int	index;
	int	lowest;

	lowest = 2147483647;
	index = 0;
	while (index < table->size)
	{
		pthread_mutex_lock(&table->philos[index].neat_mut);
		if (table->philos[index].number_eat < lowest)
			lowest = table->philos[index].number_eat;
		pthread_mutex_unlock(&table->philos[index].neat_mut);
		index++;
	}
	if (lowest >= table->settings.number_eats)
	{
		pthread_mutex_lock(&table->lethal_mut);
		table->lethal = true;
		pthread_mutex_unlock(&table->lethal_mut);
	}
}

void	*monitor_manager(void *arg)
{
	t_table	*table;

	table = arg;
	wait(10);
	while (!is_lethal(&table->lethal, &table->lethal_mut))
	{
		check_death(table);
		if (table->settings.number_eats
			&& !is_lethal(&table->lethal, &table->lethal_mut))
			check_neats(table);
	}
	return (NULL);
}

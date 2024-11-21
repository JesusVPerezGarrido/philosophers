/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:28:17 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/21 16:00:02 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	feed_philos(t_table *table, t_bool *menu)
{
	static int	cycle = 0;
	int			index;

	index = 0;
	while (index < table->size)
	{
		if (menu[(index + cycle) % table->size])
			pthread_mutex_unlock(&table->philos[index].mutex);
		index++;
	}
	cycle = (cycle + 1) % table->size;
}

static t_bool	*plan_menu(t_table *table)
{
	t_bool	*menu;
	int		index;

	menu = ft_calloc(table->size, sizeof(t_bool));
	if (!menu)
		return (NULL);
	index = 0;
	while (index < table->size)
	{
		menu[index] = index % 2;
		index++;
	}
	return (menu);
}

static int	lowest_eater(t_table *table)
{
	int	index;
	int	lowest;

	index = 0;
	lowest = table->philos[0].number_eat;
	while (index < table->size)
	{
		if (table->philos[index].number_eat < lowest)
			lowest = table->philos[index].number_eat;
		index++;
	}
	return (lowest);
}

static t_bool	check_death(t_table *table)
{
	int				index;
	long			wait;
	struct timeval	tv;

	wait = 0;
	while (100 * wait < mstomus(table->settings.time_eat) )
	{
		index = -1;
		while (++index < table->size)
		{
			if (!table->philos[index].alive)
			{
				gettimeofday(&tv, NULL);
				pthread_mutex_lock(&table->print);
				printf("%li %i died", tvtoms(time_diff(tv,
							table->philos[index].born)),
					table->philos[index].id);
				pthread_mutex_unlock(&table->print);
				return (true);
			}
		}
		wait++;
		usleep(100);
	}
	return (false);
}

void	*monitor_manager(void *arg)
{
	t_table	*table;
	t_bool	*menu;
	int		index;

	table = arg;
	menu = plan_menu(table);
	if (!menu)
		return (NULL);
	index = -1;
	while (++index < table->size)
		pthread_mutex_unlock(&table->philos[index].mutex);
	while (true)
	{
		if (table->settings.number_eats
			&& lowest_eater(table) < table->settings.number_eats)
			break ;
		feed_philos(table, menu);
		if (check_death(table))
			break ;
	}
	free(menu);
	return (NULL);
}

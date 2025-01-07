/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:23:06 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/07 18:06:45 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_philos(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->size)
	{
		pthread_mutex_destroy(&table->philos[index].leat_mut);
		pthread_mutex_destroy(&table->philos[index].neat_mut);
		index++;
	}
	free(table->philos);
}

void	clean_table(t_table *table)
{
	int	index;

	if (table)
	{
		if (table->philos)
			clean_philos(table);
		if (table->forks)
		{
			index = 0;
			while (index < table->size)
			{
				pthread_mutex_destroy(&table->forks[index]);
				index++;
			}
			free(table->forks);
		}
		pthread_mutex_destroy(&table->print);
		pthread_mutex_destroy(&table->lethal_mut);
		free(table);
	}
}

static void	wait_philo(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->size)
	{
		pthread_join(table->philos[index].thread, 0);
		index++;
	}
}

int	main(int argc, char **argv)
{
	t_table	*table;
	t_exit	exit;

	exit = valid_args(argc, argv);
	if (exit)
		return (exit);
	exit = create_table(&table, argc, argv);
	if (exit)
	{
		clean_table(table);
		return (exit);
	}
	pthread_join(table->thread, NULL);
	wait_philo(table);
	clean_table(table);
	return (OK);
}

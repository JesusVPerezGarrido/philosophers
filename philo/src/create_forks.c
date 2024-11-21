/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:12:53 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/21 11:26:02 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_exit	create_forks(t_table *table)
{
	int		index;

	table->forks = ft_calloc(table->size, sizeof(t_fork));
	if (!table->forks)
		return (MALLOC_ERROR);
	index = 0;
	while (index < table->size)
	{
		table->forks[index].id = index;
		if (pthread_mutex_init(&table->forks[index].mutex, NULL))
			return (MUTEX_ERROR);
		index++;
	}
	return (OK);
}

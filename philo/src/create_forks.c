/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:12:53 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/07 14:56:25 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_exit	create_forks(t_table *table)
{
	int		index;

	table->forks = ft_calloc(table->size, sizeof(pthread_mutex_t));
	if (!table->forks)
		return (MALLOC_ERROR);
	index = 0;
	while (index < table->size)
	{
		if (pthread_mutex_init(&table->forks[index], NULL))
			return (MUTEX_ERROR);
		index++;
	}
	return (OK);
}

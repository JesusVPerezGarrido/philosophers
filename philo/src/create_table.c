/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:53:58 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/21 15:53:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_exit	create_table(t_table **table, int argc, char **argv)
{
	t_exit	exit;

	*table = ft_calloc(1, sizeof(t_table));
	if (!*table)
		return (MALLOC_ERROR);
	create_settings(*table, argc, argv);
	if (pthread_mutex_init(&(*table)->print, NULL))
		return (MUTEX_ERROR);
	exit = create_forks(*table);
	if (exit)
		return (exit);
	exit = create_philos(*table);
	if (exit)
		return (exit);
	exit = pthread_create(&(*table)->thread, NULL, monitor_manager, *table);
	if (exit)
		return (exit);
	return (OK);
}

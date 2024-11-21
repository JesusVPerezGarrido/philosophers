/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:23:06 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/21 15:52:39 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_table(t_table *table)
{
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	free(table);
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
	clean_table(table);
	return (OK);
}

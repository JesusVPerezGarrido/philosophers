/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:19:21 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/22 10:38:40 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_settings(t_table *table, int argc, char **argv)
{
	table->size = ft_atoi(argv[1]);
	table->settings.time_die = ft_atoi(argv[2]);
	table->settings.time_eat = ft_atoi(argv[3]);
	table->settings.time_sleep = ft_atoi(argv[4]);
	table->settings.number_eats = 0;
	if (argc == 6)
		table->settings.number_eats = ft_atoi(argv[5]);
}

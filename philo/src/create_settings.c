/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:19:21 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/20 12:31:53 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_settings	create_settings(int argc, char **argv)
{
	t_settings	value;

	value.time_die = ft_atoi(argv[2]);
	value.time_eat = ft_atoi(argv[3]);
	value.time_sleep = ft_atoi(argv[4]);
	value.number_eats = 0;
	if (argc == 6)
		value.time_sleep = ft_atoi(argv[5]);
	return (value);
}

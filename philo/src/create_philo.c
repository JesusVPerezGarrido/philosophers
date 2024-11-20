/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:49:43 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/20 13:07:47 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_manager(void *arg)
{
	t_philo philo;
	
	philo = *(t_philo *)arg;
	return (NULL);
}

t_philo	*create_philo(int nphilo, t_settings *setting)
{
	t_philo	*pbundle;
	int		index;

	pbundle = ft_calloc(nphilo, sizeof(t_philo));
	if (!pbundle)
		return (NULL);
	index = 0;
	while (index < nphilo)
	{
		pbundle[index].id = index;
		pbundle[index].settings = setting;
		pthread_create(&pbundle[index].thread, NULL, philo_manager, &pbundle[index]);
		if (!pbundle[index].thread)
		{
			free(pbundle);
			return (NULL);
		}
		index++;
	}
	return (pbundle);
}

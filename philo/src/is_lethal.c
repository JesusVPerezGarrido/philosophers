/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lethal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:10:10 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/07 17:10:26 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_lethal(t_bool *address, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	if (*address)
	{
		pthread_mutex_unlock(mutex);
		return (true);
	}
	pthread_mutex_unlock(mutex);
	return (false);
}

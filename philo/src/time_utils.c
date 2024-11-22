/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:08:56 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/22 14:20:34 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_utils.h"
#include <stdio.h>

struct timeval	time_diff(struct timeval time1, struct timeval time2)
{
	struct timeval	diff;

	diff.tv_sec = (time1.tv_sec - time2.tv_sec);
	diff.tv_usec = (time1.tv_usec - time2.tv_usec);
	return (diff);
}

t_milliseconds	tvtoms(struct timeval tv)
{
	t_milliseconds	ms;

	ms = 1000 * tv.tv_sec;
	ms += tv.tv_usec / 1000;
	return (ms);
}

t_microseconds	mstomus(t_microseconds ms)
{
	return (1000 * ms);
}

void	wait(t_milliseconds ms)
{
	struct timeval	start;
	struct timeval	current;

	gettimeofday(&start, 0);
	current = start;
	while (tvtoms(time_diff(current, start)) < ms)
	{
		usleep(ms);
		gettimeofday(&current, 0);
	}
}

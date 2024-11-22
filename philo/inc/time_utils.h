/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:09:36 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/22 12:13:44 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_UTILS_H
# define TIME_UTILS_H

# include <sys/time.h>	// gettimeofday
# include <unistd.h>	// usleep

typedef time_t	t_milliseconds;
typedef time_t	t_microseconds;

struct timeval	time_diff(struct timeval time1, struct timeval time2);
t_milliseconds	tvtoms(struct timeval tv);
t_microseconds	mstomus(t_milliseconds ms);
void			wait(t_milliseconds ms);

#endif

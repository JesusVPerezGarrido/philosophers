/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:57:53 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/20 12:25:44 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef enum e_bool
{
	false,
	true,
}	t_bool;

typedef time_t	t_milliseconds;
typedef time_t	t_microseconds;
typedef time_t	t_seconds;
typedef enum e_error_code
{
	OK,
	ARG_NUM,
	INV_ARG,
}	t_error_code;

typedef struct s_philo_setting
{
	t_milliseconds	time_die;
	t_milliseconds	time_eat;
	t_milliseconds	time_sleep;
	int				number_eats;
}	t_philo_setting;

typedef struct s_philo
{
	int				id;
	t_philo_setting	settings;
	pthread_t		*thread;
}					t_philo;

t_error_code	validate_args(int argc, char **argv);
int				ft_atoi(const char *nptr);
t_bool			ft_isdigit(char c);
t_philo_setting	create_settings(int argc, char **argv);
void			create_philo(int argc, char **argv);
void			*ft_calloc(size_t nmemb, size_t size);
void			philo_manager(void);

#endif

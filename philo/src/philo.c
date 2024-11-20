/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:23:06 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/20 13:01:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_settings	settings;
	t_philo		*philos;

	
	if (!valid_args(argc, argv))
		return (1);
	settings = create_settings(argc, argv);
	philos = create_philo(ft_atoi(argv[1]), &settings);
	if (!philos)
		return (1);
	free(philos);
	return (0);
}

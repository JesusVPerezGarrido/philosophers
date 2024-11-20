/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:30:56 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/20 12:35:50 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	valid_args(int argc, char **argv)
{
	int	index;
	int	chr;

	if (argc < 5 || argc > 6)
		return (false);
	index = 1;
	while (index < argc)
	{
		chr = 0;
		while (argv[index][chr])
		{
			if (!ft_isdigit(argv[index][chr]))
				if (chr != 0 || (argv[index][chr] != '+'
					&& argv[index][chr] != '-'))
					return (false);
			chr++;
		}
		if (ft_atoi(argv[index]) < 1)
			return (false);
		index++;
	}
	return (true);
}

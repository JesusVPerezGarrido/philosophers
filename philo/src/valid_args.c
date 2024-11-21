/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:30:56 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/21 14:36:08 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_exit	valid_args(int argc, char **argv)
{
	int	index;
	int	chr;

	if (argc < 5 || argc > 6)
		return (ARG_NUM);
	index = 1;
	if (ft_atoi(argv[1]) > 200)
		return (INV_ARG);
	while (index < argc)
	{
		chr = 0;
		while (argv[index][chr])
		{
			if (!ft_isdigit(argv[index][chr]))
				if (chr != 0 || (argv[index][chr] != '+'
					&& argv[index][chr] != '-'))
					return (INV_ARG);
			chr++;
		}
		if (ft_atoi(argv[index]) < 1)
			return (INV_ARG);
		index++;
	}
	return (OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:23:06 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/21 11:26:31 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	t_exit	exit;

	exit = valid_args(argc, argv);
	if (exit)
		return (exit);
	table = 0;
	exit = create_table(table, argc, argv);
	if (exit)
		return (exit);
	return (OK);
}
